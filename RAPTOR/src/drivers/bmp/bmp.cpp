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
void BMP::init(void)
{
  if (!this->begin())
  { // Begin bmp measurements
    Serial.print(F("No BMP detected!"));
  }

  // gather a baseline
  uint8_t counter = 0;
  baseline = 1013.25; // put in a fake baseline for the initial calculation, which won't be used

  while (!update() && counter++ < 50); // until we can get a good pressure reading or we've tried more than 50 times
  baseline = pressure; // grab a baseline pressure
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
    pressure = event.pressure;
    // temperature in celsius
    getTemperature(&temperature);
    // altitude in feet
    pressureToAltitude(baseline, pressure);
  }
  else
    return false; // collection failed
}