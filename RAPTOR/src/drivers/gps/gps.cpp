/*

*/
#include "gps.h"

#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Adafruit_GPS.h>

SoftwareSerial mySerial(3, 2); // GPS serial comm pins
volatile Adafruit_GPS GPS(&mySerial);

