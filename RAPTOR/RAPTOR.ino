#include <elapsedMillis.h>

#include "src/guidance/pilot/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"
#include "src/drivers/solenoid/solenoid.h"

template <class T>inline Print &operator<<(Print &obj, T arg){obj.print(arg); return obj;} // allows stream style input and output

#define CUTDOWN_ALT 900 // altitude to cut down at

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

BNO bno;
BMP bmp;
elapsedMillis timeElapsed;
Pilot pilot;

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
GPS gps(mySerial);

uint8_t flight_state = 0;

/* 
 * Arduino setup function, first function to be run.
 */
void setup()
{
  timeElapsed = 0;

  /* Buzzer and LEDs */
  pinMode(BZZ_DTA, OUTPUT);  // Set buzzer to output
  pinMode(LEDS_DTA, OUTPUT); // Set LEDs to output

  /* Solenoids */
  sol_init();

  /* BMP180 */
  bmp.init();

  /* IMU */
  bno.init();

  /* GPS */
  gps.init();

  /* SD */
  pinMode(SD_GRN, OUTPUT);
  Serial.begin(9600);

  // Reset OpenLog
  digitalWrite(SD_GRN, LOW);
  delay(100);
  digitalWrite(SD_GRN, HIGH);

  delay(10);
  Serial.print(F("TIME,"
                 "TEMPERATURE, PRESSURE, ALTITUDE, "
                 "LATITUDE, LONGITUDE, ANGLE, "
                 "X, Y, Z, "
                 "SWC, SWP, "
                 "SRVOR, SRVOL, FLIGHT_STATE\n")); // data header
}

/* 
 * Arduino loop function, always runs.
 */
void loop()
{
  switch (flight_state)
  {
  case 0: // flight state 0 is launch
    if (!bmp.update())
      bmp.pressure = bmp.temperature = bmp.altitude = 0; // if the bmp doesn't work set them to zero

    if (correct_alt_ascending() > 30.0)
      flight_state = 1; // transition to flight state 1

    break;
  case 1: // flight state 1 is ascent
    if (!bmp.update())
      bmp.pressure = bmp.temperature = bmp.altitude = 0; // if the bmp doesn't work set them to zero

    if (correct_alt_ascending() > CUTDOWN_ALT)
    {
      cutdown(); // cutdown

      if (!cutdown_check() || cutdown_switch())
      { // we want to make sure that we have cut down and we are falling
        Serial << F("\n!!!! CUTDOWN ERROR !!!!\n");
        cutdown(); // try cutdown again
      }

      parafoil_deploy(); // deploy parafoil
      if (parafoil_switch())
      { // make sure the parafoil has deployed
        Serial << F("\n!!!! PARAFOIL DEPLOYMENT ERROR !!!!\n");
        parafoil_deploy(); // try deploying parafoil again, probably won't do much
      }

      Coordinate target_lat, target_long, current_lat, current_long;

      target_lat.decimal = 34.73; // HARD CODED TARGET COORDINATES
      target_long.decimal = 86.64;

      current_lat.decimal = gps.latitude;
      current_long.decimal = gps.longitude;

      pilot.wake(target_lat, target_long, current_lat, current_long);
      flight_state = 2;
    }
    print_data();
    break;
  case 2: // flight state 2 is descent
    if (correct_alt_descending() < 30.0)
    { // **** maybe check a few times?
      flight_state = 3;
      Serial << "\n!!!! LANDED !!!!\n";
    }
    print_data();
    delay(100);
    break;
  case 3:                                           // flight state 3 is landed
    digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA)); // toggle LEDs every second
    analogWrite(BZZ_DTA, 200);                      // turn on buzzer for 500 ms, off for 500 ms
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
    if (gps.parse(gps.lastNMEA()) && flight_state == 2)
    {                       // this also sets the newNMEAreceived() flag to false
      pilot.fly(gps.angle); // the pilot just needs our current angle to do his calculations
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
    uint16_t prevAltitude = correct_alt_descending(); //Update previous altitude
    delay(200);                                       //.2 second delay
    if (bmp.update())
      if (correct_alt_ascending() > prevAltitude) //Are we falling (is our current altitude higher or lower than our previous altitude)?
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
         << F(",") << pilot.servoR_status() << F(",") << pilot.servoL_status() << flight_state << "\n"; // write everything to SD card
}

/* 
 *  startup_sequence gives us a nice little sequences that indicates board power,
 *    solenoid power, servo power, and successful sensor initialization
 */
void startup_sequence(void)
{
  analogWrite(BZZ_DTA, 200);
  delay(500);
  analogWrite(BZZ_DTA, 0);

  sol_init();
  pilot.servo_test();

  delay(200);
  

  if (bmp.init() && bno.init())
  { // check to see if our sensors are working, if they are blink once, if not blink 5 times
    digitalWrite(LEDS_DTA, HIGH);
    delay(500);
    digitalWrite(LEDS_DTA, LOW);
  }
  else
  {
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA));
      delay(200);
    }
  }
}