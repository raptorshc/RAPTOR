/*
 * gps.h - 
 * Library written for use with Adafruit Ultimate GPS.
 * Utilizes Adafruit Ultimate GPS library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef GPS_H_
#define GPS_H_

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

class GPS
   
{
public:
  GPS(SoftwareSerial *mySerial);
 

  void init(void);

  void update(void);

  Adafruit_GPS *getGPS(void);

  float init_alt, agl; // initial altitude and above ground level altitude
  bool first_gps;
  Adafruit_GPS *a_GPS;
  int counter = 0;

private:
  void dms_to_dec(void);
};

#endif