#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <Arduino.h>
#include "SparkFunIMU.h"

extern "C"
{
  #include "inv_mpu.h"
  #include "avr_i2c.h"
};

class MPU_9250 //: public SparkFunIMU
{
  /* Set up APIs */
public:
  MPU_9250(void){}
  ~MPU_9250(void)
  {
    avr_i2c_end();
  }

  // Setup APIs
  // Arduinoified version of mpu_init
  inline int begin(struct int_param_s &int_param)
  {
    avr_i2c_begin();
    return mpu_init(&int_param);
  }
  int init_slave(void) { return mpu_init_slave(); }
  int set_bypass(unsigned char bypass_on)
  {
    return mpu_set_bypass(bypass_on);
  }

  // Configuration APIs
  int lpAccelMode(unsigned short rate)  // Low Power
  {
    return mpu_lp_accel_mode(rate);
  }
  int lpMotionInterrupt(unsigned short thresh, unsigned char time,
    unsigned short lpa_freq)
  {
    return mpu_lp_motion_interrupt( thresh, time, lpa_freq);
  }
  int setIntLevel(unsigned char active_low)
  {
    return mpu_set_int_level(active_low);
  }
  int setIntLatched(unsigned char enable)
  {
    return mpu_set_int_latched(enable);
  }

  int setDmpState(unsigned char enable)
  {
    return mpu_set_dmp_state(enable);
  }
  int getDmpState(unsigned char &enabled)
  {
    return mpu_get_dmp_state(&enabled);
  }

  int getLPF(unsigned short &lpf)
  {
    return mpu_get_lpf(&lpf);
  }
  int setLPF(unsigned short lpf)
  {
    return mpu_set_lpf(lpf);
  }

  int getGyroFullScaleRange(unsigned short &fsr)
  {
    return mpu_get_gyro_fsr(&fsr);
  }
  int setGyroFullScaleRange(unsigned short fsr)
  {
    return mpu_set_gyro_fsr(fsr);
  }

  int getAccelFullScaleRange(unsigned char &fsr)
  {
    return mpu_get_accel_fsr(&fsr);
  }
  int setAccelFullScaleRange(unsigned char fsr)
  {
    return mpu_set_accel_fsr(fsr);
  }

  int getCompassFullScaleRange(unsigned short &fsr)
  {
    return mpu_get_compass_fsr(&fsr);
  }

  int getGyroSens(float &sens)
  {
    return mpu_get_gyro_sens(&sens);
  }
  int getAccelSens(unsigned short &sens)
  {
    return mpu_get_accel_sens(&sens);
  }

  int getSampleRate(unsigned short &rate)
  {
    return mpu_get_sample_rate(&rate);
  }
  int setSampleRate(unsigned short rate)
  {
    return mpu_set_sample_rate(rate);
  }
  int getCompassSampleRate(unsigned short &rate)
  {
    return mpu_get_compass_sample_rate(&rate);
  }
  int setCompassSampleRate(unsigned short rate)
  {
    return mpu_set_compass_sample_rate(rate);
  }

  int getFIFOConfig(unsigned char &sensors)
  {
    return mpu_get_fifo_config(&sensors);
  }
  int configureFIFO(unsigned char sensors)
  {
    return mpu_configure_fifo(sensors);
  }

  int getPowerState(unsigned char &power_on)
  {
    return mpu_get_power_state(&power_on);
  }
  int setSensors(unsigned char sensors)
  {
    return mpu_set_sensors(sensors);
  }

  int read6500AccelBias(long &accel_bias)
  {
    return mpu_read_6500_accel_bias(&accel_bias);
  }
  int setGyroBiasReg(long &gyro_bias)
  {
    return mpu_set_gyro_bias_reg(&gyro_bias);
  }
  int setAccelBias6500Reg(const long &accel_bias)
  {
    return mpu_set_accel_bias_6500_reg(&accel_bias);
  }
  int read6050AccelBias(long &accel_bias)
  {
    return mpu_read_6050_accel_bias(&accel_bias);
  }
  int setAccelBias6050Reg(const long &accel_bias)
  {
    return mpu_set_accel_bias_6050_reg(&accel_bias);
  }

  // Data getter/setter APIs
  int getGyroReg(short &data, unsigned long &timestamp)
  {
    return mpu_get_gyro_reg(&data, &timestamp);
  }
  int getAccelReg(short &data, unsigned long &timestamp)
  {
    return mpu_get_accel_reg(&data, &timestamp);
  }
  int getCompassReg(short &data, unsigned long &timestamp)
  {
    return mpu_get_compass_reg(&data, &timestamp);
  }
  int get_temperature(long &data, unsigned long &timestamp)
  {
    return mpu_get_temperature(&data, &timestamp);
  }

  int getIntStatus(short &status)
  {
    return mpu_get_int_status(&status);
  }
  int readFIFO(short &gyro, short &accel, unsigned long &timestamp,
                unsigned char &sensors, unsigned char &more)
  {
    return mpu_read_fifo(&gyro, &accel, &timestamp, &sensors, &more);
  }
  int readFIFOStream(unsigned short length, unsigned char &data,
                       unsigned char &more)
  {
    return mpu_read_fifo_stream(length, &data, &more);
  }
  int resetFIFO(void)
  {
    return mpu_reset_fifo();
  }

  int writeMem(unsigned short mem_addr, unsigned short length,
               unsigned char &data)
  {
    return mpu_write_mem(mem_addr, length, &data);
  }
  int readMem(unsigned short mem_addr, unsigned short length,
              unsigned char &data)
  {
    return mpu_read_mem(mem_addr, length, &data);
  }
  int loadFirmware(unsigned short length, const unsigned char &firmware,
                    unsigned short start_addr, unsigned short sample_rate)
  {
    return mpu_load_firmware(length, &firmware, start_addr, sample_rate);
  }

  int regDump(void)
  {
    return mpu_reg_dump();
  }
  int readReg(unsigned char reg, unsigned char &data)
  {
    return mpu_read_reg(reg, &data);
  }
  int runSelfTest(long &gyro, long &accel)
  {
    return mpu_run_self_test(&gyro, &accel);
  }
  int run6500SelfTest(long &gyro, long &accel, unsigned char debug)
  {
    return mpu_run_6500_self_test(&gyro, &accel, debug);
  }
  /* Not implemented
  int registerTapCb(void (*func)(unsigned char, unsigned char))
  {
    return mpu_register_tap_cb(void (*func)(unsigned char, unsigned char));
  }
  */

protected:
};

#endif

