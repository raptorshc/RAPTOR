#include "src/drivers/servo/continuous_servo.h"

ContinuousServo servo;

void setup(){
    servo.attach(9);
    servo.Adjustment(1);
}

void loop(){
}