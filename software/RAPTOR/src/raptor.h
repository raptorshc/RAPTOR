/*
  raptor.h - 
		DESCRIPTION NEEDED.
		Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef RAPTOR_h
#define RAPTOR_h

#include "guidance/pilot/pilot.h"
#include "environment/environment.h"
#include "guidance/drivers/solenoid/solenoid.h"
#include "guidance/drivers/eeprom/eeprom.h"

class Raptor
{
public:
  Raptor();

  void launch();
  void ascent();
  void descent();
  void landed();

  void rc_test();

private:
  void startup_sequence();
  void blink_led(int length);
  void print_data();

  Environment *environment;
  Pilot *pilot;
  Prom *eeprom;

  Solenoid *parafoil_sol;
  Solenoid *cutdown_sol;

  uint8_t flight_state = 0; // current flight state
  long fly_time = 0;        // amount of time passed between flight controlling
  bool didwake = false;     // whether or not we have woken the pilot yet

  const float GROUND_ALT = 15.24;  // altitude to transition to FS1 [ASCENT] or FS3 [LANDED], =50ft
  const float CUTDOWN_ALT = 609.6; // altitude to transition to FS2 [DESCENT], =1000ft

  const float TARGET_LONG = -86.633730;
  const float TARGET_LAT = 34.722988; // HARD CODED TARGET COORDINATES

  const unsigned int DEPLOY_DELAY = 1200; // time to wait between deployment and guidance [ms]
  const unsigned int FLY_DELAY = 1000;    // time to wait between calling fly [ms]

  const uint8_t BZZ_DTA = 11;  // buzzer
  const uint8_t LEDS_DTA = 12; // external flight LEDs

  const uint8_t SET_BTN = 7; // eeprom write button
};

#endif