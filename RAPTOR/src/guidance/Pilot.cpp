/*

*/
#include "Pilot.h"
#define LEFT 0;
#define RIGHT 1;
/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
    is_turning = FALSE;
    
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
void Pilot::fly(double curr_angle)
{
    bool dirTurn = false;
    bool should_turn = shouldTurn(&dirTurn, curr_angle);
    if (!is_turning)
    {
        if (should_turn)
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
        if (!should_turn)
            straight();
    }
}

/*
 *  Makes the box take a right turn
 */
void Pilot::rightTurn()
{
    is_turning = true;
    r_Servo.servoAdjustment(RIGHT)
}
/*
* Makes the box take a left turn
*/
void Pilot::leftTurn()
{
    is_turning = true;
    l_Servo.servoAdjustment(LEFT);
}

void Pilot::straight()
{
    is_turning = false
    l_Servo.resetServos(LEFT);
    r_Servo.resetServos(RIGHT); // THis may be backwards im not sure
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
        dirTurn = RIGHT; //right turn
    else
        dirTurn = LEFT; //left turn
    if (abs(curr_angle - desired_heading - 360) < 15 || abs(desired_heading - curr_angle) < 15)
        return false; //The amount of degrees we need to adjust by.
    else
        return true;
}