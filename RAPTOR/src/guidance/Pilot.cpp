/*

*/
#include "Pilot.h"

#define SRVOL_DTA 6 // Left servo
#define SRVOR_DTA 5 // Right servo

#define RIGHT 1
#define LEFT 0

/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
    is_turning = false;
}

/*
 *  Method to wake the pilot, giving it the target coordinate.
 */
void Pilot::wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long)
{
    servoR.attach(SRVOR_DTA);
    servoL.attach(SRVOL_DTA);

    this->p = new Pathfinder(curr_lat, curr_long, target_lat, target_long);
    this->p->findPath();
    desired_heading = p->getAngle();
}

/*
 *  fly will .. 
 */
void Pilot::fly(float curr_angle)
{
    bool dirTurn = false;
    bool should_turn = shouldTurn(dirTurn, curr_angle);
    if (!is_turning)
    {
        if (should_turn)
        {
            if (dirTurn)
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
    servoR.Adjustment(RIGHT);
}
/*
* Makes the box take a left turn
*/
void Pilot::leftTurn()
{
    is_turning = true;
    servoL.Adjustment(LEFT);
}

void Pilot::straight()
{
    is_turning = false;
}

/* 
 * adjustPath will take in the current and optimal paths and 
 * calculate which way to turn and by how much. 
 * returns if we should turn
 * dirTurn is true for a right turn false for a left turn
 */
bool Pilot::shouldTurn(bool &dirTurn, float curr_angle)
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