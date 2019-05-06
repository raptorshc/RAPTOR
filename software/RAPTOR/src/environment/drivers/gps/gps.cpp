/*
 * gps.cpp - 
 * Contains implementation for functions in gps.h.
 * Utilizes Adafruit Ultimate GPS library, details: https://learn.adafruit.com/adafruit-ultimate-gps
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "gps.h"
#include "math.h"

GPS::GPS(SoftwareSerial *mySerial) 
{
    a_GPS = new Adafruit_GPS(mySerial);
    first_gps = true;
}


/*
 * init begins the GPS readings, sets up the timer counter used for the
 *  millisecond interrupt, which will query and parse the GPS data 
 */
void GPS::init(void)
{
  Serial.println("GPS init.");

  a_GPS->begin(9600);
  a_GPS->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // RMC (recommended minimum), GGA (fix data) + altitude
  a_GPS->sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);    // 1 Hz update rate
  a_GPS->sendCommand(PGCMD_ANTENNA);               // Request updates on antenna status
  delay(1000);

  // set up timer counter for interrupt
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

/*
 * update performs all needed actions for parsing 
 *  a new set of data collected by the GPS
 */
void GPS::update(void)
{
  if (a_GPS->newNMEAreceived())
  { // if we have a new nmea, parse it
    if (a_GPS->parse(a_GPS->lastNMEA()))
    {
      if (this->first_gps)
      { // set the ground level altitude on our first reading
        this->first_gps = false;
        this->init_alt = a_GPS->altitude;
      }

      // correct the coordinates to decimal-degrees and altitude to AGL
      dms_to_dec();
      this->agl = a_GPS->altitude - this->init_alt;
    }
  }
}

/*
 * converts lat/long from Adafruit degree-minute format to decimal-degrees 
 */
void GPS::dms_to_dec(void)
// from http://arduinodev.woofex.net/2013/02/06/adafruit_gps_forma/
{
  float min_long = a_GPS->longitude;
  float min_lat = a_GPS->latitude;
  double minlo = 0.0;
  double minla = 0.0;

  //get the minutes, fmod() requires double
  minlo = fmod((double)min_long, 100.0);
  minla = fmod((double)min_lat, 100.0);

  //rebuild coordinates in decimal degrees
  min_long = (int)(min_long / 100);
  a_GPS->longitude = min_long + (minlo / 60);

  min_lat = (int)(min_lat / 100);
  a_GPS->latitude = min_lat + (minla / 60);
}

Adafruit_GPS *GPS::getGPS(void)
{
  return a_GPS;
}