/*

*/
#include "eeprom.h"

/* Public Methods */
/* 
 * write_state deposits flight state and baseline pressure into the EEPROM. 
 */
void Prom::write_state(uint8_t fs, float baseline)
{
    this->put(0, fs);         // flight state is always at address 0
    this->put(100, baseline); // baseline pressure always at address 100
}

/* 
 * read_state retrieves flight state and baseline pressure from the EEPROM. 
 */
void Prom::read_state(uint8_t *fs, float *baseline)
{
    // retrive flight state from address 0
    this->get(0, *fs);
    if (*fs == 1)
        *fs = 2; // if the read flight state is 1, transition immediately to 2 as the solenoids fail open

    // retrieve baseline pressure from address 100
    this->get(100, *baseline);
}