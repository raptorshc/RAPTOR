/*
 * imu.h - 
 * Library written for use with Adafruit BNO055 sensor.
 * Utilizes Adafruit BNO055 library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef IMU_H_
#define IMU_H_

void bno_init(void);
bool bno_update(void);

#endif