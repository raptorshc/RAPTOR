/*
  ContinuousServo.h - 
  Library written for use with continuous rotation servos.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef GPS_H_
#define GPS_H_

#include "Arduino.h"
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
Adafruit_GPS GPS(&mySerial);

void gps_init(void);

#endif

