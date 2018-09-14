/*
  Pilot.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#include "Pathfinder.h"
#include "continuous_servo.h"

class Pilot{
public:
    Pilot();
    
	void wake(Coordinate &target);
	void fly(float altitude, float angle);
    
private:
	Coordinate _target;
	double desired_heading;
	int is_turning;
	ContinuousServo l_Servo, r_Servo;
	Pathfinder p;
	
	void rightTurn();
	void leftTurn();
	void straight();
    
};

#endif