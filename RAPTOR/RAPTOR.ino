#include <elapsedMillis.h>

#include "src/guidance/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"
#include "src/drivers/solenoid/solenoid.h"

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; } // enable stream style output

#define CUTDOWN_ALT 900 // altitude to cut down at

#define SWP_PIN A0 // Parafoil solenoid switch
#define SWC_PIN A1 // Cutdown solenoid switch

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

BNO bno;
BMP bmp;
elapsedMillis timeElapsed;
Pilot pilot;

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
GPS gps(mySerial);

boolean flying = false;

/* 
 * Arduino setup function, first function to be run.
 */
void setup()
{
  timeElapsed = 0;

  /* Buzzer and LEDs */
  pinMode(BZZ_DTA, OUTPUT);  // Set buzzer to output
  pinMode(LEDS_DTA, OUTPUT); // Set LEDs to output

  /* BMP180 */
  bmp.init();

  /* IMU */
  bno.init();

  /* GPS */
  gps.init();
  delay(1000);

  /* SD */
  pinMode(SD_GRN, OUTPUT);
  Serial.begin(9600);

  // Reset OpenLog
  digitalWrite(SD_GRN, LOW);
  delay(100);
  digitalWrite(SD_GRN, HIGH);

  delay(10);
  Serial.print(F("TIME," 
  "TEMPERATURE, PRESSURE, ALTITUDE," 
  "LATITUDE, LONGITUDE, ANGLE,"
  "X, Y, Z,"
  "SWC, SWP, FLYING\n")); // data header
  delay(5000);
}

/* 
 * Arduino loop function, always runs.
 */
void loop()
{
  if (!flying)
  {
    // just poll altitude calculations
    if (!bmp.update())
      bmp.pressure = bmp.temperature = bmp.altitude = 0; // if the bmp doesn't work set them to zero

    if (correct_alt_ascending() > CUTDOWN_ALT)
    {
      cutdown(); // cutdown

      if (!cutdown_check() || !digitalRead(SWC_PIN))
      { // we want to make sure that we have cut down and we are falling
        Serial << F("!!!! CUTDOWN ERROR !!!!") << "\n";
        cutdown(); // try cutdown again
      }

      parafoil_deploy(); // deploy parafoil
      if (!digitalRead(SWP_PIN))
      { // make sure the parafoil has deployed
        Serial << F("!!!! PARAFOIL DEPLOYMENT ERROR !!!!") << "\n";
        parafoil_deploy(); // try deploying parafoil again
      }

      // pilot.wake();
      flying = true;
    }
  }

  bno.update();

  /* Let's spray the OpenLog with a hose of data */
  Serial << timeElapsed << F(",")
  << bmp.temperature << F(",") << bmp.pressure << F(",") << bmp.altitude << F(",")
  << gps.latitude << F(",") << gps.longitude << F(",") << gps.angle << F(",")
  << bno.data.orientation.x << F(",") << bno.data.orientation.y << F(",") << bno.data.orientation.z << F(",")
  << digitalRead(SWC_PIN) << F(",") << digitalRead(SWP_PIN) << F(",") << flying << "\n"; // write everything to SD card
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
    if (gps.parse(gps.lastNMEA()) && flying)
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
    delay(200);                       //.2 second delay
    if (bmp.update())
      if (correct_alt_ascending() > prevAltitude) //Are we falling (is our current altitude higher or lower than our previous altitude)?
      {
        return false; //Ascending
      }
  }
  return true; //Falling
}