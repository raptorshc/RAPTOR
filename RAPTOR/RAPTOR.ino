#include <SFE_BMP180.h>
#include <Wire.h>
#include <Servo.h>
#include <SD.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <elapsedMillis.h>
#include "src/guidance/Pilot.h" // to be completed
#include "src/drivers/continuous_servo.h" // to be completed
#include "src/drivers/bmp/bmp.h" // to be completed

#define CUTDOWN_ALT 1000 // altitude to cutdown at

#define BZZ_DTA 11    // Buzzer
#define LEDS_DTA 12   // External flight LEDs;

#define LEDP_DTA A2   // Parafoil solenoid indicator light
#define LEDC_DTA A3   // Cutdown solenoid indicator light

#define SD_GRN 4      // OpenLog Reset pin

elapsedMillis timeElapsed;

boolean flying = false;
double correctAlt(void);

/* 
 *
 *  
 */
void setup() {
  timeElapsed = 0;

  /* Buzzer and LEDs */
  pinMode(BZZ_DTA, OUTPUT);     // Set buzzer to output
  pinMode(LEDS_DTA, OUTPUT);    // Set LEDs to output
  
  /* Servos */ 
  servoR.attach(SRVOR_DTA);     // Attach right servo
  servoL.attach(SRVOL_DTA);     // Attach left servo

  /* Solenoids */
  pinMode(SOLP_DTA, OUTPUT);    // Set Parafoil solenoid to output
  pinMode(SOLC_DTA, OUTPUT);    // Set Cutdown solenoid to output

  pinMode(SWP_PIN, INPUT);      // Set Parafoil switch to input
  pinMode(SWC_PIN, INPUT);      // Set Cutdown switch to input

  pinMode(LEDP_DTA, OUTPUT);    // Set Parafoil LED to output
  pinMode(LEDC_DTA, OUTPUT);    // Set Cutdown LED to output

  digitalWrite(SOLP_DTA, HIGH); // Engage Parafoil solenoid
  digitalWrite(SOLC_DTA, HIGH); // Engage Cutdown solenoid
  
  /* BMP180 */
  bmp.begin();             // Begin bmp measurements
  while(!bmpUpdate); // until we can get a good pressure reading
  bmp_data.baseline = bmp_data.pressure; // grab a baseline pressure
    
  
  /* IMU */
  

  /* GPS */
  GPS.begin(9600);
  
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);   // RMC (recommended minimum), GGA (fix data) + altitude
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);      // 1 Hz update rate
  GPS.sendCommand(PGCMD_ANTENNA);                 // Request updates on antenna status

  interrupt_init();

  delay(1000);

  /* Pilot */
  //pilot.wake();
  
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
 *
 *  
 */
void loop() {
  if(!flying){
    // just poll altitude calculations
    if(!bmpUpdate())
      bmp_data.pressure = bmp_data.temperature = bmp_data.altitude = 0; // if the bmp doesn't work set them to zero

    if (correctAlt() > CUTDOWN_ALT){ // we have liftoff, or liftdown I guess
      // may want to do some falling checks here
      // also may want to deploy our parafoil
      // and then check the parafoil
    
      //pilot.wake();
      flying = true;
    }
  }
  
  // collect IMU data
  // write everything to SD card
}

/*
 *
 *  Timer0 used for millis(), interrupt in the middle 
 */
void interrupt_init(void){
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

/* 
 *
 *  Interrupt on millisecond
 */
SIGNAL(TIMER0_COMPA_vect) {
  GPS.read(); // Check to see if we have new data
  
  if(GPS.newNMEAreceived()){
    if (GPS.parse(GPS.lastNMEA()) && flying){   // this also sets the newNMEAreceived() flag to false
      if(!bmpUpdate())
        bmp_data.pressure = bmp_data.temperature = bmp_data.altitude = 0; // if it doesn't work set them to zero
      
      //pilot.fly(correctAlt(), GPS.angle); // the pilot needs altitude and angle to do his calculations
    }
  }
}

double correctAlt(void){
  if(bmp_data.altitude - GPS.altitude > 50)
    return bmp_data.altitude;
  else if(GPS.altitude - bmp_data.altitude > 50)
    return GPS.altitude;
  else return (bmp_data.altitude+GPS.altitude)/2;
}