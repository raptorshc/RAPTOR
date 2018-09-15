/*
 * gps.cpp - 
 * Contains implementation for functions in gps.h.
 * Utilizes Adafruit Ultimate GPS library, details: https://learn.adafruit.com/adafruit-ultimate-gps
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "gps.h"

#include "Arduino.h"
#include "../bmp/bmp.h"
#include <SoftwareSerial.h>
#include <Adafruit_GPS.h>

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
Adafruit_GPS gps(&mySerial);

extern bool flying;

/*
 * gps_init begins the GPS readings, sets up the timer counter used for the
 *  millisecond interrupt, which will query and parse the GPS data 
 */
void gps_init(void){
    gps.begin(9600);
  
    gps.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);   // RMC (recommended minimum), GGA (fix data) + altitude
    gps.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);      // 1 Hz update rate
    gps.sendCommand(PGCMD_ANTENNA);                 // Request updates on antenna status
    
    // set up timer counter for interrupt
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}

/* 
 * Check our altitude measurements, grab the correct one 
 *  or return the average if they're both correct.
 */
double correct_alt(void)
{
  if (bmp_data.altitude - gps.altitude > 50)
    return bmp_data.altitude;
  else if (gps.altitude - bmp_data.altitude > 50)
    return gps.altitude;
  else
    return (bmp_data.altitude + gps.altitude) / 2;
}

/* 
 *  Interrupt on millisecond
 */
SIGNAL(TIMER0_COMPA_vect)
{
  gps.read(); // Check to see if we have new data

  if (gps.newNMEAreceived())
  {
    if (gps.parse(gps.lastNMEA()) && flying)
    { // this also sets the newNMEAreceived() flag to false
      if (!bmp_update())
        bmp_data.pressure = bmp_data.temperature = bmp_data.altitude = 0; // if it doesn't work set them to zero

      //pilot.fly(correctAlt(), gps.angle); // the pilot needs altitude and angle to do his calculations
    }
  }
}