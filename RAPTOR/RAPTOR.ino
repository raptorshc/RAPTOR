#include "src/drivers/servo/continuous_servo.h"

ContinuousServo servo;

void setup(){
  pinMode(9, OUTPUT);
  servo.attach(9);
  Serial.begin(9600);

  delay(100);
  servo.writeMicroseconds(1500);
}

void loop(){
 servo.Adjustment(ContinuousServo::RIGHT);
 delay(1000);
 servo.Adjustment(ContinuousServo::LEFT); 
 delay(1000);
}