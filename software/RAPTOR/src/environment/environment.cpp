/*
  environment.cpp - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "environment.h"

/* PUBLIC METHODS */

/*
 *  Constructor for Environment 
 */
Environment::Environment()
{
    /* BMP */
    this->bno = new BNO();
    /* BNO */
    this->bmp = new BMP();

    /* GPS */
    this->gps = new GPS(new SoftwareSerial(3, 2)); // gps serial comm pins

    this->time_elapsed = 0;
}

/*
 * initializes all sensors, returns false if any initializations fail return false
 */
bool Environment::init(bool set_baseline)
{
    if (this->bmp->init(set_baseline) && this->bno->init())
        return true;
    else
        return false;
}

/*
 *  updates/queries all sensors, returns false if any fail
 */
bool Environment::update()
{
    this->gps->update();
    if (this->bno->update())
        return true;
    else
        return false;
}

/* 
 * check our altitude measurements with the assumption we are ascending or descending based on flight state, 
 *  grab the correct one or return the average if they're both correct.
 */
float Environment::correct_alt(uint8_t flight_state)
{
    switch (flight_state)
    {
    case 0: // both flight state 0 and 1 are ascending
    case 1:
        if (this->bmp->getAltitude() - this->gps->agl > 15.24) //Altitude converted to meters. =50ft
            return this->bmp->getAltitude();
        else if (this->gps->agl - this->bmp->getAltitude() > 15.24) //Altitude converted to meters. =50ft
            return this->gps->agl;
        else
            return (this->bmp->getAltitude() + this->gps->agl) / 2;
        break;

    case 2: // both flight state 2 and 3 are descending
    case 3:
        if (this->bmp->getAltitude() == 0) // if either are zero during descent, don't trust them
            return this->gps->agl;
        if (this->gps->agl == 0)
            return this->bmp->getAltitude();

        if (this->gps->agl - this->bmp->getAltitude() > 15.24) //Altitude converted to meters. =50ft
            return this->bmp->getAltitude();
        else if (this->bmp->getAltitude() - this->gps->agl > 15.24) //Altitude converted to meters. =50ft
            return this->gps->agl;
        else
            return (this->bmp->getAltitude() + this->gps->agl) / 2;
    }
}

/*
* landing_check checks the altitude 4 times to see if we've actually landed 
*/
bool Environment::landing_check(void)
{
    uint8_t counter = 0;
    while (counter++ < 4 && this->bmp->getAltitude() < 15.24) //Altitude converted to meters. =50ft
    {                                                         // check our altitude 4 times, if we're below 50ft in all of them we're landed
        delay(100);
    }
    if (counter < 3)
    { // we exited our while loop early
        return false;
    }
    return true;
}

/* 
 *  cutdown_check checks 10 consecutive alitude measurements over 2 seconds, 
 *    if all are decreasing return true, if not return false  
 */
bool Environment::cutdown_check(void)
{
    for (int i = 0; i < 10; i++)
    {
        uint16_t prevAltitude = this->bmp->getAltitude(); //Update previous altitude
        delay(200);                                       //.2 second delay
        if (this->bmp->getAltitude() > prevAltitude)      //Are we falling (is our current altitude higher or lower than our previous altitude)?
        {
            return false; //Ascending
        }
    }
    return true; //Falling
}