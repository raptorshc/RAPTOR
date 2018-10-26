/*
  solenoid.h - 
  Library written for use with solenoids, as well as switches and LED indicators for the solenoid.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef SOLENOID_H_
#define SOLENOID_H_

#include "Arduino.h"

void sol_init(void);
void cutdown(void);
void parafoil_deploy(void);
bool cutdown_switch(void);
bool parafoil_switch(void);

#endif
