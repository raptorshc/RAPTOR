/*
  Pathfinder.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef Pathfinder_h
#define Pathfinder_h

#include <math.h>
#include "Paths.h"
#define pi 3.141592

class Pathfinder{
public:
    Pathfinder(Coordinate& current_lat, Coordinate& current_long, Coordinate& final_lat, Coordinate& final_long);
    
    void findPath(Coordinate current, Coordinate final);
    
private:
    void coord_dmsToDec(Coordinate *c1);
    void path_dmsToDec();
	Path _Path;
};

#endif