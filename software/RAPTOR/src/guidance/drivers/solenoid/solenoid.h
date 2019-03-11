/*
  solenoid.h - 
  Library written for use with solenoids, as well as switches and LED indicators for the solenoid.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef SOLENOID_H_
#define SOLENOID_H_

#include <Arduino.h>

class Solenoid
{
public:
  Solenoid(uint8_t data, uint8_t sw, uint8_t led);

  void open(void);
  void close(void);

  bool read_switch(void);

private:
  uint8_t dta_pin;
  uint8_t sw_pin;
  uint8_t led_pin;
};

#endif
