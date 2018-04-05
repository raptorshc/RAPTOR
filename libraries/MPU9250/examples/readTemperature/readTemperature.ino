extern "C"
{
  #include "avr_i2c.h"
}

#include <mpu9250.h>

MPU_9250 myIMU;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial port started up...");

  struct int_param_s int_param;
  myIMU.begin(int_param);
  myIMU.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
}

void loop()
{
  long temperature = 0;
  unsigned long timestamp = 0;
  myIMU.get_temperature(temperature, timestamp);
  Serial.print("Temperature (˚C): ");
  Serial.println(temperature/65536.0F);
  delay(750);
}
