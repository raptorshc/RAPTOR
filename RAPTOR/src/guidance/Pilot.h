/*
  Pilot.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#include "Pathfinder.h"
#include "../drivers/servo/continuous_servo.h"

class Pilot
{
public:
	Pilot();

	void wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long);
	void fly(float curr_angle);
	void test();

private:
	Coordinate _target;
	float desired_heading;
	uint8_t turning; // uses ContinuousServo settings for 0 and 1, 2 is straight
	ContinuousServo *servoR, *servoL;
	Pathfinder *p;

	void turn_right();
	void turn_left();
	void straight();
	bool shouldTurn(uint8_t &dirTurn, float curr_angle);
};

#endif