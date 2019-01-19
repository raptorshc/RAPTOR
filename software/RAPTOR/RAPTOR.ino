#include <elapsedMillis.h>
#include <EEPROM.h>
#include <Streaming.h> // http://arduiniana.org/libraries/streaming/

#include "src/guidance/pilot/pilot.h"
#include "src/environment/environment.h"
#include "src/guidance/drivers/solenoid/solenoid.h"

#define GROUND_ALT 15.24  // altitude to transition to FS1 [ASCENT] or FS3 [LANDED], =50ft
#define CUTDOWN_ALT 609.6 // altitude to transition to FS2 [DESCENT], =1000ft

#define TARGET_LONG -86.633730
#define TARGET_LAT 34.722988 // HARD CODED TARGET COORDINATES

#define DEPLOY_DELAY 1200 // time to wait between deployment and guidance [ms]
#define FLY_DELAY 1000    // time to wait between calling fly [ms]

#define BZZ_DTA 11  // buzzer
#define LEDS_DTA 12 // external flight LEDs

#define SET_BTN 7 // eeprom write button

Environment environment; // contains all of our sensors in one nice class
Pilot pilot;             // takes environmental input and makes all decisions regarding flight control

elapsedMillis timeElapsed; // time elapsed in milliseconds

uint8_t flight_state = 0; // current flight state
long fly_time = 0;        // amount of time passed between flight controlling
bool didwake = false;     // whether or not we have woken the pilot yet

/* 
 * Arduino setup function, first function to be run.
 */
void setup()
{
  timeElapsed = 0;

  /* Buzzer and LEDs */
  pinMode(BZZ_DTA, OUTPUT);  // Set buzzer to output
  pinMode(LEDS_DTA, OUTPUT); // Set LEDs to output

  Serial.begin(9600);

  pinMode(SET_BTN, OUTPUT);
  if (!digitalRead(SET_BTN))
  {
    read_EEPROM();
  }
  /* Solenoids, Servos, BMP, BNO */
  startup_sequence();

  if (digitalRead(SET_BTN))
  {
    write_EEPROM();
  }

  /* GPS */
  environment.gps->init();

  delay(10);
  Serial.print(F("TIME,"
                 "TEMPERATURE,PRESSURE,ALTITUDE,"
                 "LATITUDE,LONGITUDE,ANGLE,GPS_ALT,"
                 "X,Y,Z, "
                 "SWC,SWP,"
                 "TURN,FLIGHT_STATE\n")); // data header
}

/* 
 * arduino loop function, always runs.
 */
void loop()
{
  switch (flight_state)
  {
  // FS0 [LAUNCH]
  case 0:
    environment.bmp->update();

    if (environment.bmp->altitude > GROUND_ALT)
    { // at 50ft (15.24 meters), transition to FS1 [ASCENT]
      flight_state = 1;
      write_EEPROM();
    }

    // blink the LEDs and print data at a rate of 1Hz
    blink_led(1000);
    print_data();
    break;

  // FS1 [ASCENT]
  case 1:
    environment.bmp->update();

    if (environment.bmp->altitude > CUTDOWN_ALT)
    { // at the cutdown altiude perform cutdown, deploy, and transition to FS2 [DESCENT]
      // CUTDOWN
      cutdown();

      if (!cutdown_switch())
      { // we want to make sure that we have cut down
        Serial << F("\n!!!! CUTDOWN ERROR DETECTED !!!!\n");
        cutdown(); // try cutdown again, probably won't do much
      }

      // PARAFOIL DEPLOY
      while (environment.bmp->altitude > CUTDOWN_ALT - 3.048)
      { // wait 3 meters to deploy the parafoil
        delay(1);
        environment.bmp->update();
        print_data();
      }

      parafoil_deploy();

      if (parafoil_switch())
      { // make sure the parafoil has deployed
        Serial << F("\n!!!! PARAFOIL DEPLOYMENT ERROR DETECTED !!!!\n");
        parafoil_deploy(); // try deploying parafoil again, probably won't do much
      }

      delay(DEPLOY_DELAY); // wait for the parafoil to deploy/inflate before we begin guidance

      flight_state = 2;
      write_EEPROM();
    }

    // blink the LEDs and print data at a rate of 5Hz
    blink_led(200);
    print_data();
    break;

  // FS2 [DESCENT]
  case 2:

    // if we have yet to wake the pilot, do so
    if (!didwake)
    {
      // first set up our coordinates
      Coordinate current, target;

      current.latitude = environment.gps->latitude;
      current.longitude = environment.gps->longitude;

      target.latitude = TARGET_LAT;
      target.longitude = TARGET_LONG;

      // then wake the pilot and give it the coordinates
      Serial << "Waking pilot\n";
      pilot.wake(current, target);
      didwake = true;
    }

    environment.bmp->update();

    fly_time = timeElapsed;
    if (fly_time > FLY_DELAY)
    {                                    // don't want to constantly call fly
      pilot.fly(environment.gps->angle); // the pilot just needs our current angle to do his calculations
      fly_time = 0;
    }

    if (environment.bmp->altitude < GROUND_ALT)
    { // at 50ft (15.24 meters), transition to FS3 [LANDED]
      if (environment.landing_check())
      { // make sure that we have landed by checking the altitude constantly
        pilot.sleep();
        flight_state = 3;
        Serial << "\n!!!! LANDED !!!!\n";
      }
    }

    // blink the LEDs and print data at 10Hz
    blink_led(100);
    print_data();
    break;

  // FS3 [LANDED]
  case 3:
    // in the landed state, only toggle the LEDs and buzzer every 2 seconds, then print data
    analogWrite(BZZ_DTA, 200);
    blink_led(2000);
    analogWrite(BZZ_DTA, 0);

    delay(200);
    print_data();

    break;
  }
}

/*
 * print_data updates sensor readings then prints all relevant data to the serial pins.
 */
void print_data()
{
  environment.update();

  /* Let's spray the serial port with a hose of data */

  // time, temperature, pressure, altitude,
  Serial << timeElapsed << F(",") << environment.bmp->temperature << F(",") << environment.bmp->pressure
         << F(",") << environment.bmp->altitude << F(",");

  // latitude, longitude, angle, (gps) altitude,
  Serial << _FLOAT(environment.gps->latitude, 7) << F(",") << _FLOAT(environment.gps->longitude, 7)
         << F(",") << _FLOAT(environment.gps->angle, 7) << F(",") << environment.gps->altitude << F(",");

  // x orientation, y orientation, z orientation,
  Serial << _FLOAT(environment.bno->data.orientation.x, 4) << F(",") << _FLOAT(environment.bno->data.orientation.y, 4)
         << F(",") << _FLOAT(environment.bno->data.orientation.z, 4) << F(",");

  // cutdown switch, parafoil switch, turn status, flight state
  Serial << cutdown_switch() << F(",") << parafoil_switch() << F(",")
         << pilot.get_turn() << F(",") << flight_state << "\n"; // write everything to SD card
}

/* 
 *  startup_sequence intitializes our solenoids, servos, and sensors.
 *   If in flight state 0 (launch), performs a sequence that indicates board power,
 *   solenoid power, servo power, and successful sensor initialization.
 */
void startup_sequence(void)
{
  // indicate board power with a buzzer beep if in flight state 0
  if (flight_state == 0)
  {
    analogWrite(BZZ_DTA, 200); // turn on the buzzer for half a second
    delay(500);
    analogWrite(BZZ_DTA, 0);
  }

  // intialize solenoids, should hear them click and see the indicator LEDs turn on
  sol_init();
  cutdown_switch();
  parafoil_switch();

  // initialize servos, if we're in flight state 0 we'll test them as well
  pilot.servo_init();
  if (flight_state == 0)
  {
    pilot.servo_test(); // rotates and resets each servo
    delay(200);
  }

  // initialize sensors, then indicate if we were successful or not
  if (environment.init(flight_state))
  { // if the initialization was successful and we're in flight state 0 blink 5 times
    if (flight_state == 0)
    {
      for (int i = 0; i < 5; i++)
        blink_led(500);
    }
  }
  else
  { // if the initialization was unsucessful and we're in flight state 1 blink 15 times
    if (flight_state == 0)
    {
      for (int i = 0; i < 15; i++)
      {
        analogWrite(BZZ_DTA, 200);
        blink_led(500);
        analogWrite(BZZ_DTA, 0);
      }
    }
  }
}

/* 
 * write_EEPROM deposits flight state and baseline pressure into the EEPROM. 
 */
void write_EEPROM()
{
  EEPROM.put(0, flight_state);                // flight state is always at address 0
  EEPROM.put(100, environment.bmp->baseline); // baseline pressure always at address 100
}

/* 
 * read_EEPROM retrieves flight state and baseline pressure from the EEPROM. 
 */
void read_EEPROM()
{
  Serial << "Read EEPROM\n";

  // retrive flight state from address 0
  EEPROM.get(0, flight_state);
  if (flight_state == 1)
    flight_state = 2; // if the read flight state is 1, transition immediately to 2 as the solenoids fail open

  // retrieve baseline pressure from address 100
  EEPROM.get(100, environment.bmp->baseline);

  // print retrieved data
  Serial << "Saved flight state: " << flight_state;
  Serial << "\nSaved baseline: " << environment.bmp->baseline << "\n";
}

/* 
 * blink_led toggles the LED, then delays for a certain length of time.
 *  Can be used to achieve a blink rate, but will delay the entire execution.
 */
void blink_led(int length)
{
  digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA));
  delay(length);
}

/*
 * custom_angle returns an angle parsed from user input 
 */
float custom_angle(void)
{
  Serial << "\nPlease input an angle: ";
  while (Serial.available() == 0)
    ; // wait for user input
  float angle = Serial.parseFloat();
  Serial << "\nAngle: " << angle << "\n";
  return angle;
}