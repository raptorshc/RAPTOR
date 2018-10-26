/*
  environment.cpp - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "environment.h"
#include <Streaming.h>

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
    SoftwareSerial *gps_serial = new SoftwareSerial(3, 2); // GPS serial comm pins
    this->gps = new GPS(*gps_serial);
}

/*
 * initializes all sensors, returns false if any initializations fail return false
 */
bool Environment::init(uint8_t flight_state)
{
    this->gps->init();
    if (this->bmp->init(flight_state) && this->bno->init())
        return true;
    else
        return false;
}

/*
 *  updates/queries all sensors, returns false if any fail
 */
bool Environment::update()
{
    this->gps->read();
    if (this->bmp->update() && this->bno->update())
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
        if (this->bmp->altitude - this->gps->agl > 50)
            return this->bmp->altitude;
        else if (this->gps->agl - this->bmp->altitude > 50)
            return this->gps->agl;
        else
            return (this->bmp->altitude + this->gps->agl) / 2;
        break;

    case 2: // both flight state 2 and 3 are descending
    case 3:
        if (this->bmp->altitude == 0) // if either are zero during descent, don't trust them
            return this->gps->agl;
        if (this->gps->agl == 0)
            return this->bmp->altitude;

        if (this->gps->agl - this->bmp->altitude > 50)
            return this->bmp->altitude;
        else if (this->bmp->altitude - this->gps->agl > 50)
            return this->gps->agl;
        else
            return (this->bmp->altitude + this->gps->agl) / 2;
    }
}

/*
* landing_check checks the altitude 4 times to see if we've actually landed 
*/
bool Environment::landing_check(void)
{
    uint8_t counter = 0;
    while (counter++ < 4 && this->bmp->altitude < 50)
    { // check our altitude 4 times, if we're below 50ft in all of them we're landed
        delay(100);
        this->bmp->update();
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
        uint16_t prevAltitude = this->bmp->altitude; //Update previous altitude
        delay(200);                                  //.2 second delay
        if (this->bmp->update())
            if (this->bmp->altitude > prevAltitude) //Are we falling (is our current altitude higher or lower than our previous altitude)?
            {
                return false; //Ascending
            }
    }
    return true; //Falling
}

/*
* print_data  
*/
void Environment::print_data()
{
    this->bno->update();

    /* Let's spray the OpenLog with a hose of data */
    // Serial << timeElapsed << F(",")
    Serial << this->bmp->temperature << F(",") << this->bmp->pressure << F(",") << this->bmp->altitude << F(",")
           << this->gps->latitude << F(",") << this->gps->longitude << F(",") << this->gps->angle << F(",")
           << this->bno->data.orientation.x << F(",") << this->bno->data.orientation.y << F(",") << this->bno->data.orientation.z << F(",");
    //    << cutdown_switch() << F(",") << parafoil_switch() << F(",")
    //    << pilot.get_turn() << F(",") << flight_state << "\n"; // write everything to SD card
}

/* PRIVATE METHODS */
