#include "src/drivers/servo/continuous_servo.h"

ContinuousServo servo;

void setup(){
    servo.attach(8);
}

void loop(){
    servo.servoAdjustment(1);
}