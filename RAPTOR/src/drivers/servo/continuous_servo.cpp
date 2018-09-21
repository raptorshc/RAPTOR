/*

*/
#include "continuous_servo.h"
#include <Arduino.h>

/* Public Methods */

/*
 *	adjustment acts as the wrapper for the rest of the methods,
 *   accepting inputs of how much you want to turn in degrees (deg) and in what dir (dir).
 */
void ContinuousServo::adjustment(int dir)
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
void ContinuousServo::reset(int dir)
{
	if (dir == RIGHT)
		adjustment(LEFT);
	else
		adjustment(RIGHT);
}