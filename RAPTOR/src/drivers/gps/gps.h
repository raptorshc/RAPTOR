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

#include "../../guidance/Pathfinder.h"

class GPS : Adafruit_GPS{
    SoftwareSerial mySerial(3, 2); // GPS serial comm pins
    GPS() : Adafruit_GPS(&mySerial){}

    void init(void);
    void update(void);
};
extern Adafruit_GPS gps;

void gps_init(void);
void gps_read(Coordinate *x, Coordinate *y);

#endif