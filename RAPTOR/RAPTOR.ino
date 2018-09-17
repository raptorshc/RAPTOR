#include <SD.h>
#include <elapsedMillis.h>
#include <Adafruit_Sensor.h>

#include "src/guidance/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"

#define CUTDOWN_ALT 900 // altitude to cut down at

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

elapsedMillis timeElapsed;
Pilot pilot;

extern BmpData bmp_data;
extern Adafruit_GPS gps;

boolean flying = false;
Coordinate initial_lat, initial_long;

float correct_alt(void);

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
  read_gps(initial_lat, initial_long);

  /* SD */
  pinMode(SD_GRN, OUTPUT);
  Serial.begin(9600);

  // Reset OpenLog
  digitalWrite(SD_GRN, LOW);
  delay(100);
  digitalWrite(SD_GRN, HIGH);

  delay(10);
  Serial.print(F("TIME, TEMPERATURE, bmp, ALTITUDE, \n")); // data header
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

    if (correct_alt() > CUTDOWN_ALT)
    { // we have liftoff, or liftdown I guess
      // may want to do some falling checks here
      // also may want to deploy our parafoil
      // and then check the parafoil

      // pilot.wake();
      flying = true;
    }
  }

  sensors_event_t event;
  if (!bno_update(&event))
    event.orientation.x = event.orientation.y = event.orientation.z = 0;

  // write everything to SD card
}

/* 
 * Check our altitude measurements, grab the correct one 
 *  or return the average if they're both correct.
 */
float correct_alt(void)
{
  if (bmp_data.altitude - gps.altitude > 50)
    return bmp_data.altitude;
  else if (gps.altitude - bmp_data.altitude > 50)
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