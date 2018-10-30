#include <elapsedMillis.h>
#include <EEPROM.h>
#include <Streaming.h> // http://arduiniana.org/libraries/streaming/

#include "src/guidance/pilot/pilot.h"
#include "src/environment/environment.h"
#include "src/guidance/drivers/solenoid/solenoid.h"

#define CUTDOWN_ALT 304.8 // altitude to cut down at in meters. =900ft
#define TARGET_LONG -86.635738;
#define TARGET_LAT 34.720197; // HARD CODED TARGET COORDINATES

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SET_BTN 7

Environment environment;
Pilot pilot;

elapsedMillis timeElapsed;

uint8_t flight_state = 0;
volatile long fly_time = 0;
volatile bool first_gps = true;
bool didwake = false;

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
                 "TEMPERATURE, PRESSURE, ALTITUDE, "
                 "LATITUDE, LONGITUDE, ANGLE, GPS_ALT,"
                 "X, Y, Z, "
                 "SWC, SWP, "
                 "TURN, FLIGHT_STATE\n")); // data header
}

/* 
 * Arduino loop function, always runs.
 */
void loop()
{
  switch (flight_state)
  {
  case 0: // flight state 0 is launch
    environment.bmp->update();

    if (environment.bmp->altitude > 9.144) //Altitude converted to meters. =30ft
    {
      flight_state = 1; // transition to flight state 1
      write_EEPROM();
    }

    blink_led(1000);
    print_data();
    break;
  case 1: // flight state 1 is ascent
    environment.bmp->update();

    if (environment.bmp->altitude > CUTDOWN_ALT)
    {
      cutdown(); // cutdown

      if (!cutdown_switch())
      { // we want to make sure that we have cut down and we are falling
        Serial << F("\n!!!! CUTDOWN ERROR !!!!\n");
        cutdown(); // try cutdown again
      }

      while (environment.bmp->altitude > CUTDOWN_ALT - 3.048) // deploy parafoil after 3 meters
      {
        delay(1);
        environment.bmp->update();
      }
      parafoil_deploy(); // deploy parafoil
      delay(1200);       //delay before trying to turn after deploying parafoil
      if (parafoil_switch())
      { // make sure the parafoil has deployed
        Serial << F("\n!!!! PARAFOIL DEPLOYMENT ERROR !!!!\n");
        parafoil_deploy(); // try deploying parafoil again, probably won't do much
      }

      flight_state = 2;
      write_EEPROM();
    }
    print_data();
    blink_led(200);
    break;
  case 2: // flight state 2 is descent
    if (!didwake)
    {
      Coordinate current, target;

      current.latitude = environment.gps->latitude;
      current.longitude = environment.gps->longitude;

      target.latitude = TARGET_LAT;
      target.longitude = TARGET_LONG; // HARD CODED TARGET COORDINATES, Baseball Field!

      Serial << "Waking pilot\n";
      pilot.wake(current, target);
      didwake = true;
    }
    environment.bmp->update();
    fly_time = timeElapsed;
    if (fly_time > 1000)
    {
      pilot.fly(environment.gps->angle); // the pilot just needs our current angle to do his calculations
      fly_time = 0;
    }
    if (environment.bmp->altitude < 15.24) //correct_alt_descending() < 30.0) // Altitude converted to meters. =50ft
    {
      if (environment.landing_check())
      {
        pilot.sleep();
        flight_state = 3;
        Serial << "\n!!!! LANDED !!!!\n";
      }
    }
    print_data();
    blink_led(100);
    break;
  case 3:                      // flight state 3 is landed
    blink_led(500);            // toggle LEDs every 1.5 second
    analogWrite(BZZ_DTA, 200); // turn on buzzer for 500 ms, off for 1000 ms
    delay(500);
    analogWrite(BZZ_DTA, 0);
    delay(500);
    break;
  }
}

/* 
 *  Interrupt on millisecond,
 *    check if we have a new GPS NMEA string, if we do grab bmp data and fly
 */
SIGNAL(TIMER0_COMPA_vect)
{
  environment.gps->read(); // Check to see if we have new data

  if (environment.gps->newNMEAreceived())
  {
    if (environment.gps->parse(environment.gps->lastNMEA()))
    {
      if (first_gps)
        environment.gps->set_initalt();

      environment.gps->correct_coords();
      environment.gps->calc_agl();
    }
  }
}

void print_data()
{
  environment.bno->update();

  /* Let's spray the OpenLog with a hose of data */
  Serial << timeElapsed << F(",")
         << environment.bmp->temperature << F(",") << environment.bmp->pressure << F(",") << environment.bmp->altitude << F(",")
         << _FLOAT(environment.gps->latitude, 7) << F(",") << _FLOAT(environment.gps->longitude, 7) << F(",") << _FLOAT(environment.gps->angle, 7) << F(",") << environment.gps->altitude << F(",")
         << _FLOAT(environment.bno->data.orientation.x, 4) << F(",") << _FLOAT(environment.bno->data.orientation.y, 4) << F(",") << _FLOAT(environment.bno->data.orientation.z, 4) << F(",")
         << cutdown_switch() << F(",") << parafoil_switch() << F(",")
         << pilot.get_turn() << F(",") << flight_state << "\n"; // write everything to SD card
}

/* 
 *  startup_sequence gives us a nice little sequences that indicates board power,
 *    solenoid power, servo power, and successful sensor initialization
 */
void startup_sequence(void)
{
  if (flight_state == 0)
  {
    analogWrite(BZZ_DTA, 200); // turn on the buzzer for a second to indicate board power
    delay(500);
    analogWrite(BZZ_DTA, 0);
  }

  sol_init(); // initialize solenoids, should hear them click
  cutdown_switch();
  parafoil_switch();

  pilot.servo_init();
  if (flight_state == 0)
  {
    pilot.servo_test(); // rotates and resets each servo
    delay(200);
  }

  if (environment.init(flight_state))
  { // check to see if our sensors are working, if they are blink once, if not blink 15 times
    if (flight_state == 0)
    {
      digitalWrite(LEDS_DTA, HIGH);
      delay(3000);
      digitalWrite(LEDS_DTA, LOW);
    }
  }
  else
  {
    if (flight_state == 0)
    {
      for (int i = 0; i < 15; i++)
      {
        digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA));
        delay(200);
      }
    }
  }
}

void write_EEPROM()
{
  Serial << "Write EEPROM\n";
  EEPROM.put(0, flight_state);                // flight state is always at address 0
  EEPROM.put(100, environment.bmp->baseline); // baseline pressure always at address 100
}

void read_EEPROM()
{
  Serial << "Read EEPROM\n";
  EEPROM.get(0, flight_state);
  if (flight_state == 1)
    flight_state = 2; // this makes sense cause we'll be falling!

  EEPROM.get(100, environment.bmp->baseline);

  Serial << "Saved flight state: " << flight_state;
  Serial << "\nSaved baseline: " << environment.bmp->baseline << "\n";
}

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
    ;
  float angle = Serial.parseFloat();
  Serial << "\nAngle: " << angle << "\n";
  return angle;
}