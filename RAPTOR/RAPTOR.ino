#include <SFE_BMP180.h>
#include <Wire.h>
#include <Servo.h>
#include <SD.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <elapsedMillis.h>
//#include <Pilot.h>

#define CUTDOWN_ALT 1000 // altitude to cutdown at

#define SERVO_STOP 90

#define BZZ_DTA 13    // Buzzer
#define LEDS_DTA 12   // External flight LEDs;

#define SRVOL_DTA 6   // Left servo
#define SRVOR_DTA 5   // Right servo

#define SOLP_DTA 9    // Parafoil solenoid
#define SOLC_DTA 8    // Cutdown solenoid

#define SWP_PIN A0    // Parafoil solenoid switch
#define SWC_PIN A1    // Cutdown solenoid switch

#define LEDP_DTA A2   // Parafoil solenoid indicator light
#define LEDC_DTA A3   // Cutdown solenoid indicator light

#define SD_GRN 4      // OpenLog Reset pin

Servo servoL;
Servo servoR;

SFE_BMP180 pressure; //SDA -> A4, SCL -> A5 https://learn.adafruit.com/bmp085/wiring-the-bmp085

elapsedMillis timeElapsed;

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
volatile Adafruit_GPS GPS(&mySerial);

boolean flying = false;

float baseline;

double getPressure(void); // provide prototypes for the ISR
double correctAlt(double bmpressure, double gpspressure);

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
  pressure.begin();             // Begin pressure measurements
  baseline = getPressure();     // Grab a baseline pressure

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
  Serial.print(F("TIME, TEMPERATURE, PRESSURE, ALTITUDE, \n")); // data header
  
}

void loop() {
  
    if(correctAlt(pressure.altitude(getPressure(),baseline), GPS.altitude) > CUTDOWN_ALT && !flying){ // we have liftoff, or liftdown I guess
      // may want to do some falling checks here
      // also may want to deploy our parafoil
      // and then check the parafoil
      
      //pilot.wake();
      flying = true;
    }
    
    // collect IMU data
    // write everything to SD card
}

/* Timer0 used for millis(), interrupt in the middle */
void interrupt_init(void){
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

/* Interrupt on millisecond */
SIGNAL(TIMER0_COMPA_vect) {
  GPS.read(); // Check to see if we have new data
  
  if(GPS.newNMEAreceived()){
    if (GPS.parse(GPS.lastNMEA())){   // this also sets the newNMEAreceived() flag to false

      if(flying)
        ;//pilot.fly(correctAlt(pressure.altitude(getPressure(),baseline), GPS.altitude), GPS.angle); // the pilot needs altitude and angle to do his calculations
    }
  }
}

double getPressure(void){
  char status;
  double T,P,p0,a,b;

  // You must first get a temperature measurement to perform a pressure reading.
  
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.

  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:

    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Use '&T' to provide the address of T to the function.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Use '&P' to provide the address of P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
//          Serial.print(T);
//          Serial.print(",");
          return(P);
        }
//        else Serial.println("error retrieving pressure measurement\n");
      }
//      else Serial.println("error starting pressure measurement\n");
    }
//    else Serial.println("error retrieving temperature measurement\n");
  }
//  else Serial.println("error starting temperature measurement\n");
}

double correctAlt(double bmpressure, double gpspressure){
  // to write
}

