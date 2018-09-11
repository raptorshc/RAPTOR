/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Path Adjustment.h"
#include <math.h>

/* adjustPath will take in the current and optimal paths and calculate which way to turn and by how much. */
void adjustPath(Path path_target, Path path_current, PathAdjustment *adjustment){
    float alpha_angle, beta_angle;
        
    alpha_angle = path_target.angle + 90;  //Alpha angle is in the quadrant to the left of our target angle
    beta_angle = path_target.angle + 270;   //Beta angle is in the quadrant to the right
    
    /* Determine if alpha or beta angle is closer to our current angle, adjust based on that. */
    if(abs(alpha_angle - path_current.angle) > abs(beta_angle - path_current.angle))
        adjustment->rotation = 0;   //left if we are to the right of the target
    else
        adjustment->rotation = 1;   //right if we are to the left, if current = -target, we will be turning right
    
    adjustment->degrees = abs(path_target.angle - path_current.angle); //The amount of degrees we need to adjust by.
}