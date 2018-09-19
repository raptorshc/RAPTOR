#include "src/drivers/servo/continuous_servo.h"

ContinuousServo servo;

void setup(){
  servo.attach(9);
  Serial.begin(9600);

  servo.write(90);
}

void loop(){
  servo.Adjustment(1);
  delay(1000);
  servo.Adjustment(0);
  delay(1000);
  Serial.print(" ");
}