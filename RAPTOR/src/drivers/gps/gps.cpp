/*
 * gps.cpp - 
 * Contains implementation for functions in gps.h.
 * Utilizes Adafruit Ultimate GPS library, details: https://learn.adafruit.com/adafruit-ultimate-gps
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "gps.h"

#include "Arduino.h"

/*
 * gps_init begins the GPS readings, sets up the timer counter used for the
 *  millisecond interrupt, which will query and parse the GPS data 
 */
void gps_init(void){
    GPS.begin(9600);
  
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);   // RMC (recommended minimum), GGA (fix data) + altitude
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);      // 1 Hz update rate
    GPS.sendCommand(PGCMD_ANTENNA);                 // Request updates on antenna status
    
    // set up timer counter for interrupt
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}