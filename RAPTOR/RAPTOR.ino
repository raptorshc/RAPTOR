#include <SD.h>
#include <elapsedMillis.h>

#include "src/guidance/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"

#define CUTDOWN_ALT 1000 // altitude to cutdown at

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

elapsedMillis timeElapsed;
Pilot pilot;

boolean flying = false;
double correctAlt(void);

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
  imu_init();

  /* GPS */
  gps_init();

  delay(1000);

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
 *  Interrupt on millisecond
 */
SIGNAL(TIMER0_COMPA_vect)
{
  GPS.read(); // Check to see if we have new data

  if (GPS.newNMEAreceived())
  {
    if (GPS.parse(GPS.lastNMEA()) && flying)
    { // this also sets the newNMEAreceived() flag to false
      if (!bmp_update())
        bmp_data.pressure = bmp_data.temperature = bmp_data.altitude = 0; // if it doesn't work set them to zero

      //pilot.fly(correctAlt(), GPS.angle); // the pilot needs altitude and angle to do his calculations
    }
  }
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

    if (correctAlt() > CUTDOWN_ALT)
    { // we have liftoff, or liftdown I guess
      // may want to do some falling checks here
      // also may want to deploy our parafoil
      // and then check the parafoil

      // pilot.wake();
      flying = true;
    }
  }

  // collect IMU data
  // write everything to SD card
}

/* 
 * Check our altitude measurements, grab the correct one 
 *  or return the average if they're both correct.
 */
double correctAlt(void)
{
  if (bmp_data.altitude - GPS.altitude > 50)
    return bmp_data.altitude;
  else if (GPS.altitude - bmp_data.altitude > 50)
    return GPS.altitude;
  else
    return (bmp_data.altitude + GPS.altitude) / 2;
}