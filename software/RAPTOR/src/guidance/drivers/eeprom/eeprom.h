/*
  eeprom.h - 
  
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef EEPROM_H__
#define EEPROM_H__

#include <EEPROM.h>

class Prom : public EEPROMClass
{
public:
  void write_state(uint8_t fs, float baseline);
  void read_state(uint8_t *fs, float *baseline);
};

#endif