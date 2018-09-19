#include "src/drivers/servo/continuous_servo.h"

ContinuousServo servo;

void setup(){
    servo.attach(9);
}

void loop(){
    servo.Adjustment(1);
}