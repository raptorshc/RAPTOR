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
  ContinuousServo(uint8_t setservo)
  {
    this->servo = setservo;
  }

  void turn(bool reset = false);
  void reset();

  static const uint8_t RIGHT = 1,
                       LEFT = 0;

private:
  static const int STOP = 1500,
                   CCW = 1000,
                   CW = 1900,
                   TTR = 500;
  uint8_t servo; // uses RIGHT/LEFT to determine which way to turn and how to reset
};

#endif
