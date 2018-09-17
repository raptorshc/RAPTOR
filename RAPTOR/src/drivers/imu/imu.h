/*
 * imu.h - 
 * Library written for use with Adafruit BNO055 sensor.
 * Utilizes Adafruit BNO055 library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef IMU_H_
#define IMU_H_

#include <Adafruit_Sensor.h>

void bno_init(void);
void bno_update(sensors_event_t *event);

#endif