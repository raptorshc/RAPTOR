// debugs
#define TESTPILOT
// #define SENSORS_ENABLED
// #define CUTDOWN

#include <elapsedMillis.h>

#include "src/guidance/Pilot.h"
#include "src/drivers/bmp/bmp.h"
#include "src/drivers/gps/gps.h"
#include "src/drivers/imu/imu.h"
#include "src/drivers/servo/continuous_servo.h"
#include "src/drivers/solenoid/solenoid.h"

#include "src/guidance/Pathfinder.h"

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }

#define CUTDOWN_ALT 900 // altitude to cut down at

#define SWP_PIN A0 // Parafoil solenoid switch
#define SWC_PIN A1 // Cutdown solenoid switch

#define LEDP_DTA A2 // Parafoil solenoid indicator light
#define LEDC_DTA A3 // Cutdown solenoid indicator light

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

#define SRVOR_DTA 6
#define SRVOL_DTA 5

BNO bno;
BMP bmp;
elapsedMillis timeElapsed;
Pilot pilot;

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
GPS gps(mySerial);

ContinuousServo servoR(ContinuousServo::RIGHT);
ContinuousServo servoL(ContinuousServo::LEFT);

boolean flying = false;
float angle = 0;

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
                 "TEMPERATURE, PRESSURE, ALTITUDE, "
                 "LATITUDE, LONGITUDE, ANGLE, "
                 "X, Y, Z, "
                 "SWC, SWP, " 
                 "SERVOR, SERVOL, "
                 "FLYING\n")); // data header

  servoR.attach(SRVOR_DTA);
  servoL.attach(SRVOL_DTA);
}

/* 
 * Arduino loop function, always runs.
 */
void loop()
{
  if (!flying)
  {
#ifdef TESTPILOT
    float altitude = custom_altitude();
#endif /* TESTPILOT */
    // just poll altitude calculations
#ifndef TESTPILOT
    if (!bmp.update())
      bmp.pressure = bmp.temperature = bmp.altitude = 0; // if the bmp doesn't work set them to zero

    if (correct_alt_ascending() > CUTDOWN_ALT)
#endif /* TESTPILOT */
#ifdef TESTPILOT
    if (altitude > CUTDOWN_ALT)
#endif
    {
#ifndef TESTPILOT
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
#endif /* CUTDOWN */
      Serial << "Waking pilot. Input:(target_lat, target_long, current_lat, current_long)\n";
      pilot.wake(custom_coordinate(), custom_coordinate(), custom_coordinate(), custom_coordinate());
      flying = true;
    }
  }

  digitalWrite(LEDC_DTA, LOW);
  servoL.turn(); // left servo should always turn left
  digitalWrite(LEDP_DTA, HIGH);

  delay(1000);

  digitalWrite(LEDP_DTA, LOW);
  servoL.reset();
  digitalWrite(LEDC_DTA, HIGH);

  delay(500);

  digitalWrite(LEDC_DTA, LOW);
  servoR.turn(); // right servo should always turn right
  digitalWrite(LEDP_DTA, HIGH);

  delay(1000);

  digitalWrite(LEDP_DTA, LOW);
  servoR.reset();
  digitalWrite(LEDC_DTA, HIGH);

  delay(500);

#ifdef TESTPILOT
  angle = custom_altitude();
#endif /* TESTPILOT */

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
#ifdef SENSORS_ENABLED
      pilot.fly(gps.angle); // the pilot just needs our current angle to do his calculations
#endif /* SENSORS_ENABLED */
#ifdef TESTPILOT
      pilot.fly(angle);
#endif /* TESTPILOT */
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

// LEDs, Buzzer, Servo, Solenoid
void testOutputs(void)
{
  digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA));

  pilot.test();
}

/*
* custom_coordinate constructs a coordinate from user input 
*/
Coordinate custom_coordinate(void){
  Coordinate result;
  Serial << "\nPlease input a coordinate (degrees, minutes, seconds): ";
  while(Serial.available() == 0);
  result.degrees = Serial.parseInt();
  result.minutes = Serial.parseInt();
  result.seconds = Serial.parseInt();
  Serial << "\nYour coordinate: degrees[" << result.degrees << "] minutes[" << result.minutes << "] seconds[" << result.seconds << "]\n"; 
  return result;
}

/*
* custom_coordinate returns an altitude parsed from user input 
*/
float custom_altitude(void){
  Serial << "\nPlease input an altitude: ";
  while(Serial.available() == 0);
  float altitude = Serial.parseFloat();
  Serial << "\nAltitude: " << altitude << "\n";
  return altitude;
}

/*
* custom_angle returns an angle parsed from user input 
*/
float custom_angle(void){
  Serial << "\nPlease input an angle: ";
  while(Serial.available() == 0);
  angle = Serial.parseFloat();
  Serial << "\nAngle: " << angle << "\n";
  return angle;
}