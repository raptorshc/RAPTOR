/*
 * imu.cpp - 
 * Library written for use with Adafruit BMP180 sensor.
 * Utilizes Adafruit BMP library, details: https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor?view=all
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "imu.h"

#include "Arduino.h"
#include <Adafruit_BNO055.h>

void bno_init(void){
    if(!bno.begin())
        Serial.print(F("No BNO055 detected!"));
    //calibrate?
}

bool bno_update(sensors_event_t *event){
    bno.getEvent(event);

    if(event->orientation) return true;
    else return false;
}