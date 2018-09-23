/*
  Pilot.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#define TESTPILOT

#include "Pathfinder.h"
#include "../../drivers/servo/continuous_servo.h"
#include "Arduino.h"

class Pilot
{
public:
	Pilot();

	void wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long);
	void fly(float curr_angle);

	uint8_t servoR_status(void);
	uint8_t servoL_status(void);
	int get_turn(void);

	void servo_test(void);

private:
	Coordinate _target;
	float desired_heading;
	int current_turn; // uses ContinuousServo settings for 0 and 1, 2 is straight
	int target_turn;	// also uses ContinuousServo settings
	ContinuousServo *servoR, *servoL;
	Pathfinder *p;

	void turn_right();
	void turn_left();
	void straight();
	int find_turn(float curr_angle);
};

#endif