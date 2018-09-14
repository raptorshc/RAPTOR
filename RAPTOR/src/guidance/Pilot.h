/*
  Pilot.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#include "Pathfinder.h"
#include "../drivers/servo/continuous_servo.h"

class Pilot{
public:
    Pilot();
    
	void wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long);
	void fly(double curr_angle);
	double getAngle();
    
private:
	Coordinate _target;
	double desired_heading;
	bool is_turning;
	ContinuousServo servoR, servoL;
	Pathfinder *p;

	void rightTurn();
	void leftTurn();
	void straight();
	bool shouldTurn(bool &dirTurn, double curr_angle);
    
};

#endif