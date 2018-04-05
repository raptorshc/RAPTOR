#include <Arduino.h>
#include "avr_i2c.h"
//#include "utility/twi.h"
#include "twi.h"

#define BUFFER_LENGTH 32
#define SUCCESS 0
#define ERROR 1

typedef struct
{
  uint8_t data[BUFFER_LENGTH];
  uint8_t index;
  uint8_t length;
  uint8_t address;
} buffer;

// rxAddress shouldn't be used.
static buffer rxBuffer = { .index = 0, .length = 0, .address = 0 };
static buffer txBuffer = { .index = 0, .length = 0, .address = 0 };

static uint8_t transmitting = 0;


void avr_i2c_begin(void)  // Master device only
{
  rxBuffer.index = 0;
  rxBuffer.length = 0;

  txBuffer.index = 0;
  txBuffer.length = 0;

  twi_init();
}



void avr_i2c_end(void)
{
  twi_disable();
}



static void avr_i2c_beginTransmission(uint8_t slave_addr)
{
  // Indicate that we are transmitting
  transmitting = 1;
  // Set address of targeted slave
  txBuffer.address = slave_addr;
  // Reset tx buffer iterator vars
  txBuffer.index = 0;
  txBuffer.length = 0;
}



// STOP is performed on the I2C bus
static uint8_t avr_i2c_endTransmission(bool sendStop)
{
  // transmit buffer (blocking)
  uint8_t ret = twi_writeTo(txBuffer.address, txBuffer.data,
                            txBuffer.length, 1, sendStop);
  // reset tx buffer iterator vars
  txBuffer.index = 0;
  txBuffer.length = 0;
  // indicate that we are done transmitting
  transmitting = 0;
  return ret;
}



// Must be called in:
// slave tx event callback
// or after beginTransmission(address)
static size_t avr_i2c_write_byte(uint8_t data)
{
  if (transmitting)
  {
    // In master transmitter mode don't bother if buffer is full
    if(txBuffer.length >= BUFFER_LENGTH)
    {
      // Found in Print.h setWriteError();
      return 0; // Length too long for buffer
    }
    // put byte in tx buffer
    txBuffer.data[txBuffer.index++] = data;
    // update amount in buffer   
    txBuffer.length = txBuffer.index;
  }
  else
  { // in slave send mode
    // reply to master
    twi_transmit(&data, 1);
  }

  return txBuffer.length; // Success
}



// Must be called in:
// slave tx event callback
// or after beginTransmission(address)
static size_t avr_i2c_write_bytes(const uint8_t *data, size_t quantity)
{
  if (transmitting)
  { // in master transmitter mode
    size_t i;
    for(i = 0; i < quantity; ++i)
    {
      avr_i2c_write_byte(data[i]);
    }
  }
  else
  { // in slave send mode
    // reply to master
    twi_transmit(data, quantity);
  }
  return quantity;
}



int avr_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
              unsigned char length, unsigned char const * data)
{
  int ret = ERROR;
  avr_i2c_beginTransmission(slave_addr);  // Initialize the Tx buffer

  if (avr_i2c_write_byte(reg_addr))
  {
    ret = avr_i2c_write_bytes(data, length);
    if (ret)
    {
      switch (avr_i2c_endTransmission(true))
      {
      case 0:
        ret = SUCCESS;
        break;
      case 1: // Data too long to fit in transmit buffer
        ret = 1;
        break;
      case 2: // Received NACK on transmit of address
        ret = 2;
        break;
      case 3: // Received NACK on transmit of data
        ret = 3;
        break;
      case 4: // Other Error
        ret = 4;
        break;
      default:
        ret = ERROR;
      }
    }
    else
    {
      ret = ERROR;
    }
  }

  return ret;
}



// TODO: Probably not compatible with newer boards like Due (internal registers)
static uint8_t avr_i2c_requestFrom(uint8_t slave_addr, uint8_t length,
                                   uint8_t sendStop)
{
  // TODO: Messing with this function when all broke 1/20/2016
  // clamp to buffer length
  if(length > BUFFER_LENGTH){
    length = BUFFER_LENGTH;
  }
 
  // perform blocking read into buffer
  uint8_t read = twi_readFrom(slave_addr, rxBuffer.data, length, sendStop);
  // set rx buffer iterator vars
  rxBuffer.index = 0;
  rxBuffer.length = read;

  return read;
}



static int avr_i2c_available(void)
{
  return rxBuffer.length - rxBuffer.index;
}

static unsigned char avr_i2c_read_byte(void)
{
  unsigned char value = 0xAA; // Junk value (magic!)
  
  // get each successive byte on each call
  if(rxBuffer.index < rxBuffer.length){
    value = rxBuffer.data[rxBuffer.index];
    ++rxBuffer.index;
  }

  return value;
}


// Returns zero on success, -1 otherwise
int avr_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
                 unsigned char length, unsigned char *data)
{
  if (!length)
  {
    return 0;
  }

  int ret = -1; // Error
  avr_i2c_beginTransmission(slave_addr);  // Initialize the Tx buffer
  if (avr_i2c_write_byte(reg_addr))  // Put slave register address in Tx buff
  {
    if (avr_i2c_endTransmission(false))  // Send Tx, send restart to keep alive
    {
      ret = -1; // Error
    }
    else if (avr_i2c_requestFrom(slave_addr, length, (uint8_t)true))
    {
      unsigned char count = 0;
      while (avr_i2c_available())
      {
        data[count++] = avr_i2c_read_byte();
      }
      if (count == length)
      {
        ret = SUCCESS;
      }
      else
      {
        ret = -1;  // Error
      }
    }
    else
    {
      ret = -1;  // Error
    }
  }

  return ret;
}

