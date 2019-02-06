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

  float get_angle(void);
  float get_distance(void);

private:
  Path path;
};

#endif