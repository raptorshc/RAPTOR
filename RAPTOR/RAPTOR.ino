#include <Servo.h>

#define SERVO_PIN 6
#define SERVO_STOP 90

#define SERVO_SWITCH 3

Servo servo;

void setup() {
  servo.attach(6);
  pinMode(SERVO_SWITCH, INPUT);
}

void loop() {
  servoTest(1000);
  delay(5000);
}


void servoTest(int duration){
  int milli = 0;
  boolean switch_hit = false;
  
  servo.write(SERVO_STOP);
  servo.write(180);                                   // Start the servo
  
  while(!switch_hit && milli < duration){             // Until the limit switch for the servo is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SERVO_SWITCH);           // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    i++;                                              // Increment i every 1 millisecond
  }
  servo.write(SERVO_STOP);

  if(switch_hit){                                     // If the switch has been hit
    Serial.write("Motor switch hit, took %d milliseconds.\n", milli);
  }
  else{
    Serial.write("!!!MOTOR SWITCH NOT HIT!!!!\n");
  }
}

