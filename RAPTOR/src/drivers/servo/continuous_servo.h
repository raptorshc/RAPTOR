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
  ContinuousServo(){}

  void adjustment(int dir);
  void reset(int dir);

  static const int RIGHT = 1,
                   LEFT = 0;

private:
  static const int STOP = 1500,
                   CCW = 1000,
                   CW = 1900,
                   TTR = 500;
};

#endif
