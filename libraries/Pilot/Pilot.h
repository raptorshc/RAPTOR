/*
  Pilot.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PILOT_h
#define PILOT_h

#include "Pathfinder.h"
#include "Paths.h"

class Pilot{
public:
    Pilot();
    
	void wake(Coordinate &launch);
	void fly(altitude, angle);
    
private:
	Coordinate &launch;
	float current_heading, desired_heading;
	int is_turning;
	
	void rightTurn();
	void leftTurn();
	void shouldTurn();
    
};

#endif