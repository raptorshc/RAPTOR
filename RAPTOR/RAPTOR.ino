#include <ContinuousServo.h>
#include <Pathfinder.h>

#define SERVO_PIN 6

ContinuousServo servo(SERVO_PIN);
void environmentalUpdate();
void dropTest();
void basicFlightTest();

struct environment{
  int pressure;
  int temperature;
  int altitude;
  int gps;
  int imu;
}

void setup() {
  // put your setup code here, to run once:
  Coordinate current_lat;
  Coordinate current_long;
  Coordinate final_lat;
  Coordinate final_long;
  
  Pathfinder target_pf(current_lat, current_long, final_lat, final_long);
}

void loop() {
  // put your main code here, to run repeatedly

  environmentalUpdate();
  runSkynet();
  Pathfinder();
  Navigation();
  saveData();
  
//  
//  Coordinate current_lat;
//  Coordinate current_long;
//  Coordinate final_lat;
//  Coordinate final_long;
//  
//  Pathfinder target_pf(current_lat, current_long, final_lat, final_long);
//  
//  servo.servoAdjustment(100.0, 50);
//  Pathfinder current_pf = target_pf;
}

void environmentalUpdate(){
  environment.pressure = getPressure();
  environment.temperature = getTemperature();
  environment.altitude = getAltitude();
  environment.gps.getGPS();
  environment.imu.getIMU();
}

void dropTest(){
  
}

void basicFlightTest(){
  while(1){
    delay(5000);
    servo.servoAdjustment(100.0, 50);
    solenoid.release();
    delay(5000);
    solenoid.open();
    
    saveData(clock);
  }
}

void dropTest(){
  
}

