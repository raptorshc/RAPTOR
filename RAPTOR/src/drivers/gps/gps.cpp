/*
 * this->cpp - 
 * Contains implementation for functions in this->h.
 * Utilizes Adafruit Ultimate GPS library, details: https://learn.adafruit.com/adafruit-ultimate-gps
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "gps.h"
#include "math.h"

/*
 * init begins the GPS readings, sets up the timer counter used for the
 *  millisecond interrupt, which will query and parse the GPS data 
 */
void GPS::init(void)
{
    this->begin(9600);

    this->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // RMC (recommended minimum), GGA (fix data) + altitude
    this->sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);    // 1 Hz update rate
    this->sendCommand(PGCMD_ANTENNA);               // Request updates on antenna status

    // set up timer counter for interrupt
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}

void GPS::correct_coords(void)
// converts lat/long from Adafruit degree-minute format to decimal-degrees
{
    float min_long = this->longitude;
    float min_lat = this->latitude;
    double minlo = 0.0;
    double minla = 0.0;

    //get the minutes, fmod() requires double
    minlo = fmod((double)min_long, 100.0);
    minla = fmod((double)min_lat, 100.0);

    //rebuild coordinates in decimal degrees
    min_long = (int)(min_long / 100);
    this->longitude = min_long + (minlo / 60);

    min_lat = (int)(min_lat / 100);
    this->latitude = min_lat + (minla / 60);
}