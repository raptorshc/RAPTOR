/*

*/
#include "continuous_servo.h"
#include "Arduino.h"

#define STOP 1500
#define CCW 1000
#define CW 1900

#define TTR 500

/* Public Methods */
/*
 *	Adjustment acts as the wrapper for the rest of the methods,
 *   accepting inputs of how much you want to turn in degrees (deg) and in what dir (dir).
 */
void ContinuousServo::adjustment(uint8_t dir)
{
	this->writeMicroseconds(STOP); // Stop the servos just in-case they're running already.
	delay(10);
	if (dir == RIGHT){
		this->writeMicroseconds(CW); // If it is a right turn, just use the deflection setting speed.
	}
	else{
		this->writeMicroseconds(CCW); // Otherwise, add 90 to the speed to reverse the direction.
	}
	delay(TTR);

	this->writeMicroseconds(STOP); // Stop the servos once we've reached the deflection setting.
}

/*
 *	reset will reset the servos to the default position after a turn.
 *   Must be called before timeToTurn is used, as it relies on the previous turn's deflection setting.
 */
void ContinuousServo::reset(uint8_t dir)
{
	if (dir == RIGHT)
		adjustment(LEFT);
	else
		adjustment(RIGHT);
}