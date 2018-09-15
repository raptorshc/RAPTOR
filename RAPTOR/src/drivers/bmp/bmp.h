/*
 * bmp.h - 
 * Library written for use with Adafruit BMP180 sensor.
 * Utilizes Adafruit BMP library
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef BMP_H_
#define BMP_H_

struct BmpData // since the BMP object doesn't store data for us
{
  float baseline, pressure, temperature, altitude;
};

extern BmpData bmp_data;

void bmp_init(void);
bool bmp_update(void);

#endif /* BMP_H_ */