#include <ContinuousServo.h>
#include <Pathfinder.h>

#define SERVO_PIN 6

ContinuousServo servo(SERVO_PIN);

void setup() {
  // put your setup code here, to run once:
  Coordinate current_lat;
  Coordinate current_long;
  Coordinate final_lat;
  Coordinate final_long;
  
  Pathfinder target_pf(current_lat, current_long, final_lat, final_long);
}

void loop() {
  // put your main code here, to run repeatedly:
  Coordinate current_lat;
  Coordinate current_long;
  Coordinate final_lat;
  Coordinate final_long;
  
  Pathfinder target_pf(current_lat, current_long, final_lat, final_long);
  
  servo.servoAdjustment(100.0, 50);
  Pathfinder current_pf = target_pf;
}
