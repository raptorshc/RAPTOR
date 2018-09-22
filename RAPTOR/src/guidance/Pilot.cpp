/*

*/
#include "Pilot.h"
#include <stdio.h>

#define SRVOL_DTA 6 // Left servo
#define SRVOR_DTA 5 // Right servo

#define STRAIGHT 2
#define RIGHT 1
#define LEFT 0

/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
    this->servoR = new ContinuousServo(RIGHT);
    this->servoL = new ContinuousServo(LEFT);
    this->current_turn = STRAIGHT;
    this->target_turn = STRAIGHT;
}

/*
 *  Method to wake the pilot, giving it the target coordinate.
 */
void Pilot::wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long)
{
    servoR->attach(SRVOR_DTA);
    servoL->attach(SRVOL_DTA);

    this->p = new Pathfinder(curr_lat, curr_long, target_lat, target_long);
    this->p->findPath();
    desired_heading = p->getAngle();
    printf("desired_heading: %f\n", desired_heading);
}

/*
 *  fly will .. 
 */
void Pilot::fly(float curr_angle)
{
    target_turn = find_turn(curr_angle);
    if (target_turn != current_turn)
    {
        if (target_turn == STRAIGHT)
        {
            straight();
        }
        else if (target_turn == LEFT)
        {
            turn_left();
        }
        else
        {
            turn_right();
        }
    }
}

/*
 *  Makes the box take a right turn
 */
void Pilot::turn_right()
{
    if (current_turn == LEFT)
        straight();
    servoR->turn();
    current_turn = RIGHT;
}
/*
* Makes the box take a left turn
*/
void Pilot::turn_left()
{
    if (current_turn == RIGHT)
        straight();
    servoL->turn();
    current_turn = LEFT;
}

void Pilot::straight()
{
    if (current_turn == RIGHT)
    {
        servoR->reset();
    }
    else
    {
        servoL->reset();
    }
    current_turn = STRAIGHT;
}

/* 
 * adjustPath will take in the current and optimal paths and 
 * calculate which way to turn and by how much. 
 * returns if we should turn
 */
int Pilot::find_turn(float curr_angle)
{
    float alpha_angle, beta_angle;

    if (abs(abs(curr_angle - desired_heading) - 360) < 15 || abs(desired_heading - curr_angle) < 15)
        return STRAIGHT; // if the difference between our current and desired heading is less than 15,  continue straight

    alpha_angle = desired_heading + 90; //Alpha angle is in the quadrant to the left of our target angle
    beta_angle = desired_heading + 270; //Beta angle is in the quadrant to the right

    if (alpha_angle > 360)
        alpha_angle -= 360;
    if (beta_angle > 360)
        beta_angle -= 360;
    /* Determine if alpha or beta angle is closer to our current angle, adjust based on that. */
    if (abs(alpha_angle - curr_angle) > abs(beta_angle - curr_angle))
        return RIGHT;
    else
        return LEFT;
}

/* 
 * get_turn returns the current turn of the pilot
 */
int Pilot::get_turn(void)
{
    return current_turn;
}