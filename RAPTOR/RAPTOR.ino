#include <SD.h>
#include <elapsedMillis.h>
#include <Adafruit_Sensor.h>

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

elapsedMillis timeElapsed;
Pilot pilot;

extern BmpData bmp_data;
extern Adafruit_GPS gps;

boolean flying = false;
Coordinate initial_lat, initial_long;

float correct_alt_ascending(void);

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
  bmp_init();

  /* IMU */
  bno_init();

  /* GPS */
  gps_init();
  delay(1000);

  // grab our launch location
  gps_read(&initial_lat, &initial_long);

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
}

/* 
 * Arduino loop function, always runs.
 */
void loop()
{
  if (!flying)
  {
    // just poll altitude calculations
    if (!bmp_update())
      bmp_data.pressure = bmp_data.temperature = bmp_data.altitude = 0; // if the bmp doesn't work set them to zero

    if (correct_alt_ascending() > CUTDOWN_ALT)
    {
      uint8_t counter = 0;         // error check counter so we aren't stuck if we get some errant readings
      cutdown(); // cutdown

      while (!cutdown_check() && counter++ < 10)
      { // we want to make sure that we have cut down and we are falling
        cutdown(); // try cutdown again
      }

      counter = 0;                 // reset counter for parafoil
      parafoil_deploy(); // deploy parafoil
      while (!parafoil_deployed() && counter++ < 10)
      { // make sure the parafoil has deployed
        parafoil_deploy(); // try deploying parafoil again
      }

      // pilot.wake();
      flying = true;
    }
  }

  sensors_event_t event;
  bno_update(&event);

  /* Let's spray the OpenLog with a hose of data */
  Serial << timeElapsed << ","
  << bmp_data.temperature << "," << bmp_data.pressure << "," << bmp_data.altitude << ","
  << gps.latitude << "," << gps.longitude << "," << gps.angle << ","
  << event.orientation.x << "," << event.orientation.y << "," << event.orientation.z << ","
  << digitalRead(SWC_PIN) << "," << digitalRead(SWP_PIN) << "," << flying << "\n"; // write everything to SD card
}

/* 
 * check our altitude measurements with the assumption we are ascending, 
 *  grab the correct one or return the average if they're both correct.
 */
float correct_alt_ascending(void)
{
  if (bmp_data.altitude - gps.altitude > 50)
    return bmp_data.altitude;
  else if (gps.altitude - bmp_data.altitude > 50)
    return gps.altitude;
  else
    return (bmp_data.altitude + gps.altitude) / 2;
}

/* 
 * check our altitude measurements with the assumption we are descending, 
 *  grab the correct one or return the average if they're both correct.
 */
float correct_alt_descending(void)
{
  if (gps.altitude - bmp_data.altitude > 50)
    return bmp_data.altitude;
  else if (bmp_data.altitude - gps.altitude > 50)
    return gps.altitude;
  else
    return (bmp_data.altitude + gps.altitude) / 2;
}

/* 
 *  Interrupt on millisecond,
 *    check if we have a new GPS NMEA string, if we do grab bmp data and 
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
    if (bmp_update())
      if (correct_alt_ascending() > prevAltitude) //Are we falling (is our current altitude higher or lower than our previous altitude)?
      {
        return false; //Ascending
      }
  }
  return true; //Falling
}

/* 
 *  cutdown_check checks 10 consecutive alitude measurements over 2 seconds, 
 *    if all are decreasing return true, if not return false  
 */
bool parafoil_deployed(void)
{
  // probably do some fancy IMU stuff with glide angle to check this
  return true; // deployed
}