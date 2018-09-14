#ifndef BMP_H_
#define BMP_H_

struct BmpData {
  double baseline, pressure, temperature, altitude;  // since the BMP object doesn't store data for us
} bmp_data;

bool bmpUpdate(void);

#endif /* BMP_H_ */