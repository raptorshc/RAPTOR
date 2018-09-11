/*

*/
#include "Pathfinder.h"

/* PUBLIC METHODS */

/*
 *  Constructor for Pathfinder 
 */
Pathfinder::Pathfinder(Coordinate& current_lat, Coordinate& current_long, Coordinate& final_lat, Coordinate& final_long){
    this->lat_initial = current_lat;
    this->lat_final = final_lat;
    this->long_initial = current_long;
    this->long_final = final_long;
}

/*
 *	findPath acts as the wrapper for the rest of the methods,
 *   accepting inputs of current location and desired location.
 */
 
void Pathfinder::findPath(Coordinate current, Coordinate final){
    path_dmsToDec();                                                            //Convert the coordinates to decimal to make it easier to find the vector and angle.
    
    /* First find the vector between our coordinates */
    this->lat_vec = this->lat_final.decimal - this->lat_initial.decimal;
    this->long_vec = this->long_final.decimal - this->long_initial.decimal;
    
    /* Compute the angle of the vector to find our bearing */
    this->angle = 90 - atan2(this->long_vec,this->lat_vec) * 180/pi;            //atan returns in radians, * 180/pi is converting radians to degrees, 90 - gives bearing.
	if(this->angle < 0)
		this->angle += 360; 													//ensure positive bearing
}

/* PRIVATE METHODS */

/*
 *	coord_dmsToDec calculates a decimal value from the current degrees/minutes/seconds of a coordinate.
 */
void Pathfinder::coord_dmsToDec(Coordinate *c1){
    c1->decimal = c1->degrees + c1->minutes/60 + c1->seconds/3600;
}

/*
 *	path_dmsToDec calls coord_dmsToDec on each coordinate in a Path struct.
 */
void Pathfinder::path_dmsToDec(){
    coord_dmsToDec(this->lat_initial);
    coord_dmsToDec(this->long_initial);
    coord_dmsToDec(this->lat_final);
    coord_dmsToDec(this->long_final);
}