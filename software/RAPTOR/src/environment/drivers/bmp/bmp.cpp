/*
 * bmp.cpp - 
 * Contains implementation for functions in bmp.h
 * Utilizes the adafruit BMP180 external library, details here: https://learn.adafruit.com/bmp085
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "bmp.h"

/*
 *	init begins the BMP measurements and 
 *   grabs a baseline pressure for alt calculations.
 */
bool BMP::init(uint8_t flight_state)
{
  // check to make sure it initializes properly
  if (!this->begin())
  { // begin bmp measurements
    Serial.print(F("No BMP detected!"));
    return false;
  }

  // if it does and we're in FS0 [LAUNCH], grab a new baseline
  uint8_t counter = 0;
  if (flight_state == 0)
  {
    this->baseline = 1013.25; // put in a fake baseline for the initial calculation, which won't be used

    while (!update() && counter++ < 50)
      ;                              // until we can get a good pressure reading or we've tried more than 50 times
    this->baseline = this->pressure; // grab a baseline pressure
  }
  return true;
}

/*
 *	update will update the temperature, pressure, then altitude,
 *   if temperature fails, pressure will not be read, if pressure fails altitude will not be calculated.
 */
bool BMP::update(void)
{
  // get a new sensor event
  sensors_event_t event;
  this->getEvent(&event);

  // if pressure measurement succeeded, we can collect the data
  if (event.pressure)
  {
    // pressure in hPa
    this->pressure = event.pressure;
    // temperature in celsius
    getTemperature(&this->temperature);
    // altitude in meters
    this->altitude = pressureToAltitude(this->baseline, this->pressure);
  }
  else
    return false; // collection failed
}