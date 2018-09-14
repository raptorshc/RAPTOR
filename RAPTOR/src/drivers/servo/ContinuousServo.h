/*
  ContinuousServo.h - 
  Library written for use with continuous rotation servos.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef CONTINUOUSSERVO_H_
#define CONTINUOUSSERVO_H_

#include "Arduino.h"
#include <Servo.h>

#define RIGHT 1     // Direction of the turn
#define LEFT 0      //Direction of the turn

#define SERVO_STOP 90

#define TTR 100

class ContinuousServo{
  public:
    ContinuousServo(int pin);
    void servoAdjustment(float deg, int dir);
  private:
    int timeToTurn(float deg);
    void resetServos(int dir);
    void manualAdjustment(int dir);
    
    Servo _servo;
	
	int _currentdef;				// current deflection setting 
	
	int _hspeed = 75; 				// default high speed is 75
	int _lspeed = 30; 				// default low speed is 30
	
	int _dPSH = 1; 					// number of degs per second that the high setting rotates with
	int _dPSL = 2;					// number of degs per second that the low setting rotates with
	
	int _ttr = 100;					// default amount of time to rotate the servos to achieve either deflection setting is 100ms
};

#endif

