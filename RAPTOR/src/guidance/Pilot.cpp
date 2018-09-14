/*

*/
#include "Pilot.h"

/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
}

/*
 *  Method to wake the pilot, giving it the target coordinate.
 */
void Pilot::wake(Coordinate *target_lat, Coordinate *target_long, Coordinate *curr_lat, Coordinate *curr_long)
{
    p = new Pathfinder(curr_lat, curr_long, target_lat, target_long);
    p.findPath();
    desired_heading = p.getAngle();
}

/*
 *  Constructor for Pilot 
 */
void Pilot::fly(double altitude, double curr_angle)
{
    bool dirTurn = false;
    bool _turn = shouldTurn(&dirTurn, curr_angle);
    if (!is_turning)
    {
        if (_turn)
         {
             if(dirTurn)
             {
                 leftTurn();
             }
             else 
             {
                 rightTurn();
             }
         }  
    }
    else
    {
        if (!(_turn))
            straight();
    }
}

/*
 *  Makes the box take a right turn
 */
void Pilot::rightTurn()
{
    is_turning = true;
}
/*
* Makes the box take a left turn
*/
void Pilot::leftTurn()
{
    is_turning = true;
}

void Pilot::straight()
{
    is_turning = false
}

/* 
 * adjustPath will take in the current and optimal paths and 
 * calculate which way to turn and by how much. 
 * returns if we should turn
 * dirTurn is true for a right turn false for a left turn
 */
bool Pilot::shouldTurn(bool &dirTurn, double curr_angle)
{
    float alpha_angle, beta_angle;

    alpha_angle = desired_heading + 90; //Alpha angle is in the quadrant to the left of our target angle
    beta_angle = desired_heading + 270; //Beta angle is in the quadrant to the right

    /* Determine if alpha or beta angle is closer to our current angle, adjust based on that. */
    if (abs(alpha_angle - curr_angle) > abs(beta_angle - curr_angle))
        *dirTurn = false; //left if we are to the right of the target
    else
        *dirTurn = true; //right if we are to the left, if current = -target, we will be turning right
    if (abs(alpha_angle < 15) || abs(beta_angle < 15)
        return false; //The amount of degrees we need to adjust by.
    else
        return true;
}