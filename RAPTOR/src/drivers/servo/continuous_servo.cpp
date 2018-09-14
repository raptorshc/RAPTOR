/*

*/
#include "continuous_servo.h"
#include "Arduino.h"

/* Public Methods */

/*
 *	Constructor for ContinuousServo accepts arguments for the pin and the
 *   time to rotate (ttr) in milliseconds.
 */
ContinuousServo::ContinuousServo(int pin){
  _servo.attach(pin);
}

/*
 *	servoAdjustment acts as the wrapper for the rest of the methods,
 *   accepting inputs of how much you want to turn in degrees (deg) and in what dir (dir).
 */
void ContinuousServo::servoAdjustment(float deg, int dir){
	int duration = timeToTurn(deg);		
	
	manualAdjustment(dir);
	delay(duration);	// run a delay for the required duration in milliseconds
	//busyDelay(duration); *******TODO
	// Did it work
	resetServos(dir);
}

/* Private Methods */

/*
 *	timeToTurn calculates the duration of the turn in milliseconds based on the degrees given in servoAdjustment.
 *	 The function will select a deflection setting for the user, based on if the turn will take more or less than a second to execute.
 */
int ContinuousServo::timeToTurn(float degree){
	if(degree / float(_dPSH) >= 1){	// If the turn takes more than one second, use high deflection
		_currentdef = HIGH;
		return degree/_dPSH;
	}
	else{					// Otherwise use low deflection
		_currentdef = LOW;
		return degree/_dPSL;
	}
}

/*
 *	resetServos will reset the servos to the default position after a turn.
 *   Must be called before timeToTurn is used, as it relies on the previous turn's deflection setting.
 */
void ContinuousServo::resetServos(int dir){
	if(dir == RIGHT)
		manualAdjustment(LEFT);
	else
		manualAdjustment(RIGHT);
}

/*
 *	manualAdjustment adjusts the servos so that they achieve the necessary deflection setting
 *   for the input direction.
 */
void ContinuousServo::manualAdjustment(int dir){
	_servo.write(SERVO_STOP);				// Stop the servos just in-case they're running already.
	if(_currentdef == HIGH){				// Check deflection setting set by timeToTurn
		if(dir == RIGHT)					
			_servo.write(0);				// If it is a right turn, just use the deflection setting speed.
		else
			_servo.write(180);				// Otherwise, add 90 to the speed to reverse the direction.
		delay(500);
	}
	else{									// deflection is LOW
		if(dir == RIGHT)
			_servo.write(0);
		else
			_servo.write(180);
	}
	if(dir == RIGHT)
		delay(20); 							// *RAPTOR* account for difference in rotation speeds
	delay(_ttr);							// Delay the set amount of time to get to the deflection setting.
	_servo.write(SERVO_STOP);				// Stop the servos once we've reached the deflection setting.
}