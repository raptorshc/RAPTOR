/*
  pilot.h - 
		DESCRIPTION NEEDED.
		Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#define TESTPILOT

#include "pathfinder.h"
#include "../drivers/servo/continuous_servo.h"
#include "Arduino.h"

class Pilot
{
  public:
	Pilot();

	void wake(Coordinate current, Coordinate target);
	void fly(float curr_angle);

	/* Mutators */
	void servo_test(void);
	void servo_init(void);
	void sleep(void);

	/* Accessors */
	int servoR_status(void);
	int servoL_status(void);
	int get_turn(void);

  private:
	float desired_heading;

	int current_turn, target_turn; // uses ContinuousServo settings for 0 (left) and 1 (right), 2 is straight

	ContinuousServo *servoR, *servoL;
	Pathfinder *p;

	int find_turn(float curr_angle);

	/* Turning Methods */
	void turn_right();
	void turn_left();
	void straight();
};

#endif