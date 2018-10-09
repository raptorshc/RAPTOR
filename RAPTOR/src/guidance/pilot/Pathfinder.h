/*
  pathfinder.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef PATHFINDER_h
#define PATHFINDER_h

#include <math.h>

#define pi 3.141592

struct Coordinate
{
    double latitude, longitude;
};

struct Path
{
    Coordinate current, target;

    double lat_vec, long_vec;
    float angle, distance;
};

class Pathfinder
{
  public:
    Pathfinder(Coordinate current, Coordinate target);

    void find_path(void);

    void adjust_path(Path path_target, Path path_current, PathAdjustment *adjustment);

    float get_angle(void);
    float get_distance(void);

  private:
    Path path;
};

#endif