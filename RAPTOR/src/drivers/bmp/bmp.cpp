/*
 * bmp.cpp - 
 * Contains implementation for functions in bmp.h
 * Utilizes the adafruit BMP180 external library, details here: https://learn.adafruit.com/bmp085
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "bmp.h"

#include "Arduino.h"
#include <SFE_BMP180.h> // external adafruit library

SFE_BMP180 bmp; //SDA -> A4, SCL -> A5 https://learn.adafruit.com/bmp085/wiring-the-bmp085

/*
 *	bmp_init begins the BMP measurements and 
 *   grabs a baseline pressure for alt calculations.
 */
void bmp_init(void)
{
  bmp.begin(); // Begin bmp measurements
  while (!bmp_update); // until we can get a good pressure reading
  bmp_data.baseline = bmp_data.pressure; // grab a baseline pressure
}

/*
 *	bmp_update will update the temperature, pressure, then altitude,
 *   if temperature fails, pressure will not be read, if pressure fails altitude will not be calculated.
 */
bool bmp_update(void)
{
  // Temperature measurement
  char status = bmp.startTemperature();
  delay(status);
  status = bmp.getTemperature(bmp_data.temperature);

  // If temperature succeeded, pressure measurement
  if (status)
  {
    status = bmp.startPressure(3);
    delay(status);
    status = bmp.getPressure(bmp_data.pressure, bmp_data.temperature);

    // If pressure succeeded, calculate altitude
    if (status)
    {
      bmp_data.altitude = bmp.altitude(bmp_data.pressure, bmp_data.baseline);
    }
    else
      return false;
  }
  else
    return false;
}