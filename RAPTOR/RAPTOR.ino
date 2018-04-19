#include <SFE_BMP180.h>
#include <Wire.h>
#include <Servo.h>
#include <SD.h>

#define SERVO_PIN 6
#define SERVO_STOP 90
#define SERVO_SWITCH 3

#define SOLENOID_PIN 5
#define SOLENOID_SWITCH 6

Servo servo;
SFE_BMP180 pressure;
File file;

float baseline;

void setup() {
  Serial.begin(9600);
  servo.attach(6);
  pinMode(SERVO_SWITCH, OUTPUT);
  pinMode(SOLENOID_PIN, OUTPUT);

  /* Pressure */
  pressure.begin();
  baseline = getPressure();
  
  /* SD Card */
  pinMode(10, OUTPUT);
  SD.begin(10);
  file = SD.open("data.txt", FILE_WRITE);

  file.print("Baseline = ");
  file.println(baseline);
  
  file.println("TEMPERATURE | PRESSURE | ALTITUDE | SERVO 1 | SERVO 2 | SOLENOID 1 | SOLENOID 2");
  file.close();
}

void loop() {
  file = SD.open("data.csv", FILE_WRITE);
  double P = getPressure();
  file.print(P);
  file.print(",");
  double a = pressure.altitude(P, baseline);
  file.print(a);
  file.print(",");

  if(a > 150){
    servoTest(1000);
    solenoidTest(200);
  }
  
  file.println(" ");
  file.close();
  delay(5000);
}

double getPressure(){
  char status;
  double T,P,p0,a;

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
  boolean switch_hit = false;

  servo.write(SERVO_STOP);
  servo.write(180);                                         // Start the servo

  while (!switch_hit && milli < duration) {                 // Until the limit switch for the servo is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SERVO_SWITCH);                 // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    milli++;                                                    // Increment i every 1 millisecond
  }
  servo.write(SERVO_STOP);

  if (switch_hit) {                                         // If the switch has been hit
    file.print("TRUE");
  }
  else {
    file.print("FALSE");
  }
}

/*
   solenoidTest will send a write to the servo to test it, upon which a physical switch will activate a pin if it is hit.
   The function will monitor this pin, and record to the SD card whether it is hit within the duration given.
*/
void solenoidTest(int duration) {
  int milli = 0;
  boolean switch_hit = false;

  digitalWrite(SOLENOID_PIN, HIGH);                        // Start the solenoid

  while (!switch_hit && milli < duration) {                // Until the limit switch for the solenoid is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SOLENOID_SWITCH);             // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    milli++;                                                   // Increment i every 1 millisecond
  }
  digitalWrite(SOLENOID_PIN, LOW);

  if (switch_hit) {                                        // If the switch has been hit
    file.print("TRUE");
  }
  else {
    file.print("FALSE");
  }
}

