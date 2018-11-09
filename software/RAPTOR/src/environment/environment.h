/*
  environment.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef ENVIRONMENT_h
#define ENVIRONMENT_h

#include <elapsedMillis.h>
#include "drivers/bmp/bmp.h"
#include "drivers/bno/bno.h"
#include "drivers/gps/gps.h"

class Environment
{
public:
  Environment(); // constructor

  bool init(uint8_t flight_state);
  bool update();

  float correct_alt(uint8_t flight_state);

  bool landing_check(void);
  bool cutdown_check(void);
  
  BMP *bmp;
  BNO *bno;
  GPS *gps;
  elapsedMillis *timeElapsed;
};

#endif