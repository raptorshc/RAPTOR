#include "src/drivers/servo/continuous_servo.h"

#define CUTDOWN_ALT 900 // altitude to cut down at

#define SWP_PIN A0 // Parafoil solenoid switch
#define SWC_PIN A1 // Cutdown solenoid switch

#define BZZ_DTA 11  // Buzzer
#define LEDS_DTA 12 // External flight LEDs

#define SD_GRN 4 // OpenLog Reset pin

#define SRVOR_DTA 5
#define SRVOL_DTA 6

ContinuousServo servoR;
ContinuousServo servoL;

void setup(){
  pinMode(9, OUTPUT);
  servoR.attach(SRVOR_DTA);
  servoL.attach(SRVOL_DTA);

  servoR.writeMicroseconds(1500);
  servoL.writeMicroseconds(1500);

  Serial.begin(9600);

  delay(100);
}

void loop(){
  testOutputs();
  delay(1000);
}

// LEDs, Buzzer, Servo, Solenoid
void testOutputs(void){
  
  digitalWrite(LEDS_DTA, !digitalRead(LEDS_DTA));
  
  servoR.adjustment(ContinuousServo::RIGHT);
  servoL.adjustment(ContinuousServo::LEFT);

  delay(1000);

  servoR.reset(ContinuousServo::RIGHT);
  servoR.reset(ContinuousServo::LEFT);

  delay(1000);

  servoR.adjustment(ContinuousServo::LEFT);
  servoL.adjustment(ContinuousServo::RIGHT);

  delay(1000);

  servoR.reset(ContinuousServo::LEFT);
  servoR.reset(ContinuousServo::RIGHT);
}

// detect input on both switches
void testSwitches(void){

}

// gather + print IMU data
void testIMU(void){

}

// run bmpUpdate, print data
void testBMP(void){

}

// print GPS data
void testGPS(void){

}