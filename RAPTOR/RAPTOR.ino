#include <SFE_BMP180.h>
#include <Wire.h>
#include <Servo.h>
#include <SD.h>
#include <elapsedMillis.h>

#define SERVO_STOP 90

#define SERVO1_PIN 6
#define SERVO2_PIN 5
#define SERVO1_SWITCH 4
#define SERVO2_SWITCH 1

#define SOLENOID1_PIN 9
#define SOLENOID1_SWITCH 2

#define SOLENOID2_PIN 8
#define SOLENOID2_SWITCH 3


Servo servo1;
Servo servo2;
SFE_BMP180 pressure; //SDA -> A4, SCL -> A5 https://learn.adafruit.com/bmp085/wiring-the-bmp085
File file;           //CLK -> 13, DO -> 12, DI -> 11, CS -> 10 https://learn.adafruit.com/adafruit-micro-sd-breakout-board-card-tutorial/arduino-wiring
elapsedMillis timeElapsed;

float baseline;

void setup() {
  timeElapsed = 0;

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  
  pinMode(SERVO1_SWITCH, OUTPUT);
  pinMode(SERVO2_SWITCH, OUTPUT);
  
  pinMode(SOLENOID1_PIN, OUTPUT);
  pinMode(SOLENOID2_PIN, OUTPUT);

  pinMode(SOLENOID1_SWITCH, OUTPUT);
  pinMode(SOLENOID2_SWITCH, OUTPUT);

  servo1.write(90);
  servo2.write(90);
  /* Pressure */
  pressure.begin();
  baseline = getPressure();

  digitalWrite(SOLENOID2_PIN, HIGH);
  /* SD Card */
  pinMode(10, OUTPUT);
  SD.begin(10);
  file.close();
}

void loop() {
  file = SD.open("data.csv", FILE_WRITE);  //FORMAT: time(sec), temperature(C), pressure(Pascal?), altitude(m), servo 1(bool), servo 2(bool), solenoid 1(bool), solenoid 2(bool) 
  
  file.print(timeElapsed/1000);
  file.print(",");
    
  double P = getPressure();
  file.print(P);
  file.print(",");
  double a = pressure.altitude(P, baseline);
  file.print(a);
  file.print(",");

  if(a > 150){
    servoTest(1000);
    
    solenoidTest(500);
  }
  file.print("\n");
  file.close();
  delay(5000);
}

double getPressure(){
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
          file.print(T);
          file.print(",");
          return(P);
        }
        else file.println("error retrieving pressure measurement\n");
      }
      else file.println("error starting pressure measurement\n");
    }
    else file.println("error retrieving temperature measurement\n");
  }
  else file.println("error starting temperature measurement\n");
}

/*
   servoTest will send a write to the servo to test it, upon which a physical switch will activate a pin if it is hit.
   The function will monitor this pin, and record to the SD card whether it is hit within the duration given.
*/
void servoTest(int duration) {
  int milli = 0;
  boolean switch1_hit = false;
  boolean switch2_hit = false;

  servo1.write(SERVO_STOP);
  servo2.write(SERVO_STOP);

  delay(10);

  servo1.write(180);
  servo2.write(180);
  
  while (milli < duration) {                 // Until the limit switch for the servo is hit, or we have waited for duration in milliseconds.
    if(!switch1_hit)
      switch1_hit = digitalRead(SERVO1_SWITCH);                 // Read in the digital value of the SERVO_SWITCH pins
    if(!switch2_hit)
      switch2_hit = digitalRead(SERVO2_SWITCH);
    delay(1);
    milli++;                                                    // Increment i every 1 millisecond
  }

  delay(100);
  servo1.write(SERVO_STOP);
  servo2.write(SERVO_STOP);

  if (switch1_hit) {                                         // If the switch has been hit
    file.print("TRUE,");
  }
  else {
    file.print("FALSE,");
  }

  if (switch2_hit) {                                         // If the switch has been hit
    file.print("TRUE,");
  }
  else {
    file.print("FALSE,");
  }
}

/*
   solenoidTest will send a write to the servo to test it, upon which a physical switch will activate a pin if it is hit.
   The function will monitor this pin, and record to the SD card whether it is hit within the duration given.
*/
void solenoidTest(int duration) {
  int milli = 0;
  boolean switch_hit = false;

  digitalWrite(SOLENOID1_PIN, HIGH);                        // Start the solenoid

  while (!switch_hit && milli < duration) {                // Until the limit switch for the solenoid is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SOLENOID1_SWITCH);             // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    milli++;                                                   // Increment i every 1 millisecond
  }
  digitalWrite(SOLENOID1_PIN, LOW);

  if (switch_hit) {                                        // If the switch has been hit
    file.print("TRUE,");
  }
  else {
    file.print("FALSE,");
  }
  if(digitalRead(SOLENOID2_SWITCH))
    file.print("TRUE");
  else
    file.print("FALSE");
}

