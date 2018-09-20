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

  void adjustment(uint8_t dir);
  void reset(int dir);

  static const uint8_t RIGHT = 1;
  static const uint8_t LEFT = 0;

private:
  int timeToTurn(float deg);
  void manualAdjustment(int dir);
};

#endif
