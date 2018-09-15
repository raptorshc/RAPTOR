/*
 * bmp.cpp - 
 * Contains implementation for functions in bmp.h
 * Utilizes the adafruit BMP180 external library, details here: https://learn.adafruit.com/bmp085
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "bmp.h"

#include "Arduino.h"
#include <Adafruit_BMP085_U.h> // external adafruit library
#include <Adafruit_Sensor.h>

BmpData bmp_data;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085); //SDA -> A4, SCL -> A5 https://learn.adafruit.com/bmp085/wiring-the-bmp085

/*
 *	bmp_init begins the BMP measurements and 
 *   grabs a baseline pressure for alt calculations.
 */
void bmp_init(void)
{
  if(!bmp.begin()){ // Begin bmp measurements
    Serial.print(F("No BMP detected!"));
  }

  // gather a baseline
  uint8_t counter = 0;
  bmp_data.baseline = 1013.25; // put in a fake baseline for the initial calculation, which won't be used
  
  while (!bmp_update && counter++ < 50); // until we can get a good pressure reading or we've tried more than 50 times
  bmp_data.baseline = bmp_data.pressure; // grab a baseline pressure
}

/*
 *	bmp_update will update the temperature, pressure, then altitude,
 *   if temperature fails, pressure will not be read, if pressure fails altitude will not be calculated.
 */
bool bmp_update(void)
{
  // get a new sensor event
  sensors_event_t event;
  bmp.getEvent(&event);

  // if pressure measurement succeeded, we can collect the data
  if(event.pressure){
    // pressure in hPa
    bmp_data.pressure = event.pressure;
    // temperature in celsius
    bmp.getTemperature(&bmp_data.temperature);
    // altitude in feet
    bmp.pressureToAltitude(bmp_data.baseline, bmp_data.pressure);
  }
  else return false; // collection failed
}