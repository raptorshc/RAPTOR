#include <elapsedMillis.h>
#include <EEPROM.h>

#include "src/guidance/pilot/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"
#include "src/drivers/solenoid/solenoid.h"

template <class T> inline Print &operator<<(Print &obj, T arg){obj.print(arg);return obj;} // allows stream style input and output

#define CUTDOWN_ALT 900 // altitude to cut down at

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SET_BTN 7

BNO bno;
BMP bmp;
elapsedMillis timeElapsed;
Pilot pilot;

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
GPS gps(mySerial);

uint8_t flight_state = 0;
volatile long fly_time = 0;
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
  gps.init();

  delay(10);
  Serial.print(F("TIME,"
                 "TEMPERATURE, PRESSURE, ALTITUDE, "
                 "LATITUDE, LONGITUDE, ANGLE, "
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
    bmp.update();

    if (bmp.altitude > 30.0)
    {
      flight_state = 1; // transition to flight state 1
      write_EEPROM();
    }

    blink_led(1000);
    print_data();
    break;
  case 1: // flight state 1 is ascent
    bmp.update();

    if (bmp.altitude > CUTDOWN_ALT)
    {
      cutdown(); // cutdown

      if (!cutdown_check() || cutdown_switch())
      { // we want to make sure that we have cut down and we are falling
        Serial << F("\n!!!! CUTDOWN ERROR !!!!\n");
        cutdown(); // try cutdown again
      }

      while (bmp.altitude > 875)
      {
        bmp.update();
      }                  // wait a hundred feet to deployment
      parafoil_deploy(); // deploy parafoil
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
    if(!didwake)
    {
      Coordinate target_lat, target_long, current_lat, current_long;

      target_lat.decimal = 34.758224; // HARD CODED TARGET COORDINATES, Baseball Field!
      target_long.decimal = 86.657632;

      current_lat.decimal = gps.latitude;
      current_long.decimal = gps.longitude;

      Serial << "Waking pilot\n";
      pilot.wake(target_lat, target_long, current_lat, current_long);
      didwake = true;
    }
    bmp.update();
    fly_time = timeElapsed;
    if (fly_time > 1000)
    {
      pilot.fly(gps.angle); // the pilot just needs our current angle to do his calculations
      fly_time = 0;
    }
    if (bmp.altitude < 50.0) //correct_alt_descending() < 30.0)
    {
      if (landing_check())
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
 * check our altitude measurements with the assumption we are ascending, 
 *  grab the correct one or return the average if they're both correct.
 */
float correct_alt_ascending(void)
{
  if (bmp.altitude - gps.altitude > 50)
    return bmp.altitude;
  else if (gps.altitude - bmp.altitude > 50)
    return gps.altitude;
  else
    return (bmp.altitude + gps.altitude) / 2;
}

/* 
 * check our altitude measurements with the assumption we are descending, 
 *  grab the correct one or return the average if they're both correct.
 */
float correct_alt_descending(void)
{
  if (bmp.altitude == 0) // if either are zero during descent, don't trust them
    return gps.altitude;
  if (gps.altitude == 0)
    return bmp.altitude;

  if (gps.altitude - bmp.altitude > 50)
    return bmp.altitude;
  else if (bmp.altitude - gps.altitude > 50)
    return gps.altitude;
  else
    return (bmp.altitude + gps.altitude) / 2;
}

/* 
 *  Interrupt on millisecond,
 *    check if we have a new GPS NMEA string, if we do grab bmp data and fly
 */
SIGNAL(TIMER0_COMPA_vect)
{
  gps.read(); // Check to see if we have new data

  if (gps.newNMEAreceived())
  {
    if (gps.parse(gps.lastNMEA()))
    {
      gps.correct_coords();
    }
  }
}

/* 
 *  cutdown_check checks 10 consecutive alitude measurements over 2 seconds, 
 *    if all are decreasing return true, if not return false  
 */
bool cutdown_check(void)
{
  for (int i = 0; i < 10; i++)
  {
    uint16_t prevAltitude = bmp.altitude; //Update previous altitude
    delay(200);                                       //.2 second delay
    if (bmp.update())
      if (bmp.altitude > prevAltitude) //Are we falling (is our current altitude higher or lower than our previous altitude)?
      {
        return false; //Ascending
      }
  }
  return true; //Falling
}

void print_data()
{
  bno.update();

  /* Let's spray the OpenLog with a hose of data */
  Serial << timeElapsed << F(",")
         << bmp.temperature << F(",") << bmp.pressure << F(",") << bmp.altitude << F(",")
         << gps.latitude << F(",") << gps.longitude << F(",") << gps.angle << F(",")
         << bno.data.orientation.x << F(",") << bno.data.orientation.y << F(",") << bno.data.orientation.z << F(",")
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

  if (bmp.init(flight_state) && bno.init())
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
  EEPROM.put(0, flight_state);   // flight state is always at address 0
  EEPROM.put(100, bmp.baseline); // baseline pressure always at address 100
}

void read_EEPROM()
{
  Serial << "Read EEPROM\n";
  EEPROM.get(0, flight_state);
  if (flight_state == 1)
    flight_state = 2; // this makes sense cause we'll be falling!

  EEPROM.get(100, bmp.baseline);

  Serial << "Saved flight state: " << flight_state;
  Serial << "\nSaved baseline: " << bmp.baseline << "\n";
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
  while (Serial.available() == 0);
  float angle = Serial.parseFloat();
  Serial << "\nAngle: " << angle << "\n";
  return angle;
}

/*
* landing_check checks the altitude 4 times to see if we've actually landed 
*/
bool landing_check(void)
{
  uint8_t counter = 0;
  while (counter++ < 4 && bmp.altitude < 50)
  { // check our altitude 4 times, if we're below 50ft in all of them we're landed
    delay(100);
    bmp.update();
  }
  if (counter < 3)
  { // we exited our while loop early
    return false;
  }
  return true;
}