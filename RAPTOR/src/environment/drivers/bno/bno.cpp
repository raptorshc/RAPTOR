/*
 * bno.cpp - 
 * Library written for use with Adafruit BNO055 sensor.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "bno.h"

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

bool BNO::update()
{
    return this->getEvent(&this->data);
}