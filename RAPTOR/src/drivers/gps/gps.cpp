/*

*/
#include "gps.h"

#include "Arduino.h"

/*
 *
 *  Timer0 used for millis(), interrupt in the middle 
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