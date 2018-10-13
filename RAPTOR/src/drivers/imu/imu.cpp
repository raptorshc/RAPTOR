/*
 * imu.cpp - 
 * Library written for use with Adafruit BMP180 sensor.
 * Utilizes Adafruit BMP library, details: https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor?view=all
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "imu.h"

#include "Arduino.h"
#include <Adafruit_BNO055.h>

bool BNO::init(void)
{
    if (!this->begin())
    {
        Serial.print(F("No BNO055 detected!"));
        return false;
    }
    //calibrate here
    return true;
}

void BNO::update()
{
    this->getEvent(&this->data);
}