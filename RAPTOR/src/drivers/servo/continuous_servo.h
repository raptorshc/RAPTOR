/*
  ContinuousServo.h - 
  Library written for use with continuous rotation servos.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef CONTINUOUSSERVO_H_
#define CONTINUOUSSERVO_H_

#include "Arduino.h"
#include <Servo.h>

class ContinuousServo : public Servo
{
public:
  ContinuousServo();

  void Adjustment(int dir);

private:
  int timeToTurn(float deg);
  void resetServo(int dir);
  void manualAdjustment(int dir);

  uint8_t _currentdef; // current deflection setting

  uint8_t _hspeed = 75; // default high speed is 75
  uint8_t _lspeed = 30; // default low speed is 30

  uint8_t _dPSH = 1; // number of degs per second that the high setting rotates with
  uint8_t _dPSL = 2; // number of degs per second that the low setting rotates with

  uint8_t _ttr = 100; // default amount of time to rotate the servos to achieve either deflection setting is 100ms
};

#endif
