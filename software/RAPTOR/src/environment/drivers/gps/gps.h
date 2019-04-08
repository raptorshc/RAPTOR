/*
 * gps.h - 
 * Library written for use with Adafruit Ultimate GPS.
 * Utilizes Adafruit Ultimate GPS library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef GPS_H_
#define GPS_H_

#include <Adafruit_GPS.h>

class GPS
    : public Adafruit_GPS
{
public:
  GPS(SoftwareSerial *mySerial) : Adafruit_GPS(mySerial)
  {
    first_gps = true;
  }

  void init(void);

  void update(void);

  float init_alt, agl; // initial altitude and above ground level altitude
  bool first_gps;

  int counter = 0;

private:
  void dms_to_dec(void);
};

#endif