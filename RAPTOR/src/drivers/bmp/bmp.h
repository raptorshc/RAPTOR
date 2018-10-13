/*
 * bmp.h - 
 * Library written for use with Adafruit BMP180 sensor.
 * Utilizes Adafruit BMP library
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef BMP_H_
#define BMP_H_

#include <Adafruit_BMP085_U.h> // external adafruit library
#include <Adafruit_Sensor.h>
#include "Arduino.h"

class BMP
    : public Adafruit_BMP085_Unified
{
public:
  BMP() : Adafruit_BMP085_Unified(10085) {}
  bool init(uint8_t fs);
  bool update(void);

  float baseline, pressure, temperature, altitude;
};

#endif /* BMP_H_ */