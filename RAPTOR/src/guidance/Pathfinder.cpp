/*

*/
#include "Pathfinder.h"
#include <stdlib.h>

/* PUBLIC METHODS */

/*
 *  Constructor for Pathfinder 
 */
Pathfinder::Pathfinder(Coordinate current_lat, Coordinate current_long, Coordinate final_lat, Coordinate final_long){
    this->_Path->lat_initial = current_lat;
    this->_Path->lat_final = final_lat;
    this->_Path->long_initial = current_long;
    this->_Path->long_final = final_long;
}

/*
 *	findPath acts as the wrapper for the rest of the methods,
 *   accepting inputs of current location and desired location.
 */
 
void Pathfinder::findPath(){
    path_dmsToDec();                                                            //Convert the coordinates to decimal to make it easier to find the vector and angle.
    
    /* First find the vector between our coordinates */
    this->_Path->lat_vec = this->_Path->lat_final.decimal - this->_Path->lat_initial.decimal;
    this->_Path->long_vec = this->_Path->long_final.decimal - this->_Path->long_initial.decimal;
    
    /* Compute the angle of the vector to find our bearing */
    this->_Path->angle = 90 - atan2(this->_Path->long_vec,this->_Path->lat_vec) * 180/pi;            //atan returns in radians, * 180/pi is converting radians to degrees, 90 - gives bearing.
	if(this->_Path->angle < 0)
		this->_Path->angle += 360; 													//ensure positive bearing
}

/*
 *	getAngle returns the angle in the Path struct.
 */
double Pathfinder::getAngle()
{
    return this->_Path->angle;
}

/* PRIVATE METHODS */

/*
 *	coord_dmsToDec calculates a decimal value from the current degrees/minutes/seconds of a coordinate.
 */
void Pathfinder::coord_dmsToDec(Coordinate &c1){
    c1.decimal = c1.degrees + c1.minutes/60 + c1.seconds/3600;
}

/*
 *	path_dmsToDec calls coord_dmsToDec on each coordinate in a Path struct.
 */
void Pathfinder::path_dmsToDec(){
    coord_dmsToDec(this->_Path->lat_initial);
    coord_dmsToDec(this->_Path->long_initial);
    coord_dmsToDec(this->_Path->lat_final);
    coord_dmsToDec(this->_Path->long_final);
}