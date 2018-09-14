/*
  Pathfinder.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef Pathfinder_h
#define Pathfinder_h

#include <math.h>
#define pi 3.141592

typedef struct Coordinate{
    int degrees, minutes, seconds;
    float decimal;
}Coordinate;

typedef struct Path{
    Coordinate lat_initial, long_initial;
    Coordinate lat_final, long_final;
    float lat_vec, long_vec;
    double angle;
}Path;

typedef struct PathAdjustment{
    double degrees; //Amount to turn
    int rotation;   //Which way to turn. 1 is right, 0 is left.
}PathAdjustment;

class Pathfinder{
public:
    Pathfinder(Coordinate current_lat, Coordinate current_long, Coordinate final_lat, Coordinate final_long);
    
    void findPath();

    void adjustPath(Path path_target, Path path_current, PathAdjustment *adjustment);
    
private:
    void coord_dmsToDec(Coordinate& c1);
    void path_dmsToDec();
	Path *_Path;
};

#endif