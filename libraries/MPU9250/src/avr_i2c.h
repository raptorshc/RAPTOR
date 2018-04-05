#ifndef _AVR_I2C_H_
#define _AVR_I2C_H_

void avr_i2c_begin(void); // Master only
void avr_i2c_end  (void);
int  avr_i2c_read( unsigned char slave_addr, unsigned char reg_addr,
                   unsigned char length,     unsigned char *data);
int  avr_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
                   unsigned char length,     unsigned char const * data);

#endif
