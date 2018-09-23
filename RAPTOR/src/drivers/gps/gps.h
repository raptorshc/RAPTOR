/*
 * gps.h - 
 * Library written for use with Adafruit Ultimate GPS.
 * Utilizes Adafruit Ultimate GPS library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef GPS_H_
#define GPS_H_

#include "Arduino.h"
#include <Adafruit_GPS.h>

class GPS
    : public Adafruit_GPS
{
  public:
    GPS(SoftwareSerial &mySerial) : Adafruit_GPS(&mySerial) {}

    void init(void);
};

#endif