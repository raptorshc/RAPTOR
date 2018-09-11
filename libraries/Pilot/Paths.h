/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilities.h
 * Author: Sean Widmier
 *
 * Created on October 1, 2017, 5:48 PM
 */

#ifndef UTILITIES_H
#define UTILITIES_H

typedef struct Coordinate{
    int degrees, minutes, seconds;
    float decimal;
} Coordinate;

typedef struct Path{
    Coordinate lat_initial, long_initial;
    Coordinate lat_final, long_final;
    float lat_vec, long_vec;
    double angle;
} Path;

typedef struct PathAdjustment{
    double degrees; //Amount to turn
    int rotation;   //Which way to turn. 1 is right, 0 is left.
} PathAdjustment;

#endif /* UTILITIES_H */

