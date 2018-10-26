/*
  pathfinder.h - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "pathfinder.h"
#include <stdlib.h>

/* PUBLIC METHODS */

/*
 *  Constructor for Pathfinder 
 */
Pathfinder::Pathfinder(Coordinate current, Coordinate target)
{
    this->path.current = current;
    this->path.target = target;
}

/*
 *	find_path acts as the wrapper for the rest of the methods,
 *   accepting inputs of current location and desired location.
 */
void Pathfinder::find_path()
{
    /* First find the vector between our coordinates */
    this->path.lat_vec = this->path.target.latitude - this->path.current.latitude;
    this->path.long_vec = -1.0 * (this->path.target.latitude) - -1.0 * (this->path.current.longitude);

    /* Compute the angle of the vector to find our bearing */
    this->path.angle = atan2(this->path.long_vec, this->path.lat_vec) * 180.0 / pi; //atan returns in radians, * 180/pi is converting radians to degrees, 90 - gives bearing.
    if (this->path.angle < 0)
        this->path.angle += 360; //ensure positive bearing

    /* Compute the magnitude of the vector to find the distance */
    this->path.distance = sqrt((this->path.long_vec * this->path.long_vec) + (this->path.lat_vec * this->path.lat_vec));
}

/*
 *	get_angle returns the angle in the Path struct.
 */
float Pathfinder::get_angle()
{
    return this->path.angle;
}

/*
 *	get_distance returns the distance in the Path struct.
 */
float Pathfinder::get_distance()
{
    return this->path.distance;
}

/* PRIVATE METHODS */