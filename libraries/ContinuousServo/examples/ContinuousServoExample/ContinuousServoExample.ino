#include <ContinuousServo.h>

#define SERVO_PIN 6

ContinuousServo servo(SERVO_PIN);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.servoAdjustment(100.0, 50);
}
