/*

*/
#include "Pathfinder.h"

/* PUBLIC METHODS */

/*
 *  Constructor for Pathfinder 
 */
Pathfinder::Pathfinder(Coordinate& current_lat, Coordinate& current_long, Coordinate& final_lat, Coordinate& final_long){
    _Path.lat_initial = current_lat;
    _Path.lat_final = final_lat;
    _Path.long_initial = current_long;
    _Path.long_final = final_long;
}

/*
 *	servoAdjustment acts as the wrapper for the rest of the methods,
 *   accepting inputs of how much you want to turn in degrees (deg) and in what dir (dir).
 */
 
void Pathfinder::findPath(Coordinate current, Coordinate final){
    path_dmsToDec();                                                            //Convert the coordinates to decimal to make it easier to find the vector and angle.
    
    /* First find the vector between our coordinates */
    _Path.lat_vec = _Path.lat_final.decimal - _Path.lat_initial.decimal;
    _Path.long_vec = _Path.long_final.decimal - _Path.long_initial.decimal;
    
    /* Compute the angle of the vector to find our bearing */
    _Path.angle = atan2(_Path.long_vec,_Path.lat_vec) * 180/pi;                 //atan returns in radians, * 180/pi is converting radians to degrees.
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
    coord_dmsToDec(&_Path.lat_initial);
    coord_dmsToDec(&_Path.long_initial);
    coord_dmsToDec(&_Path.lat_final);
    coord_dmsToDec(&_Path.long_final);
}