/*

*/
#include "continuous_servo.h"
#include "Arduino.h"

#define RIGHT 1 // Direction of the turn
#define LEFT 0  //Direction of the turn
#define SERVO_STOP 90
#define TTR 100

/* Public Methods */

/*
 *	Constructor for ContinuousServo
 */
ContinuousServo::ContinuousServo() {}

/*
 *	servoAdjustment acts as the wrapper for the rest of the methods,
 *   accepting inputs of how much you want to turn in degrees (deg) and in what dir (dir).
 */
void ContinuousServo::servoAdjustment(float deg, int dir)
{
	int duration = timeToTurn(deg);

	manualAdjustment(dir);
	delay(duration); // run a delay for the required duration in milliseconds
	//busyDelay(duration); *******TODO
	// Did it work
	resetServos(dir);
}

/* Private Methods */

/*
 *	timeToTurn calculates the duration of the turn in milliseconds based on the degrees given in servoAdjustment.
 *	 The function will select a deflection setting for the user, based on if the turn will take more or less than a second to execute.
 */
int ContinuousServo::timeToTurn(float degree)
{
	if (degree / float(_dPSH) >= 1)
	{ // If the turn takes more than one second, use high deflection
		_currentdef = HIGH;
		return degree / _dPSH;
	}
	else
	{ // Otherwise use low deflection
		_currentdef = LOW;
		return degree / _dPSL;
	}
}

/*
 *	resetServos will reset the servos to the default position after a turn.
 *   Must be called before timeToTurn is used, as it relies on the previous turn's deflection setting.
 */
void ContinuousServo::resetServos(int dir)
{
	if (dir == RIGHT)
		manualAdjustment(LEFT);
	else
		manualAdjustment(RIGHT);
}

/*
 *	manualAdjustment adjusts the servos so that they achieve the necessary deflection setting
 *   for the input direction.
 */
void ContinuousServo::manualAdjustment(int dir)
{
	this->write(SERVO_STOP); // Stop the servos just in-case they're running already.
	if (_currentdef == HIGH)
	{ // Check deflection setting set by timeToTurn
		if (dir == RIGHT)
			this->write(0); // If it is a right turn, just use the deflection setting speed.
		else
			this->write(180); // Otherwise, add 90 to the speed to reverse the direction.
		delay(500);
	}
	else
	{ // deflection is LOW
		if (dir == RIGHT)
			this->write(0);
		else
			this->write(180);
	}
	if (dir == RIGHT)
		delay(20);			 // *RAPTOR* account for difference in rotation speeds
	delay(_ttr);			 // Delay the set amount of time to get to the deflection setting.
	this->write(SERVO_STOP); // Stop the servos once we've reached the deflection setting.
}