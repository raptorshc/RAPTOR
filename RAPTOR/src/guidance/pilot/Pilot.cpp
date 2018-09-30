/*

*/
#include "Pilot.h"
#include <stdio.h>

#define SRVOR_DTA 6 // Right servo
#define SRVOL_DTA 5 // Left servo

#define STRAIGHT 2

/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
    this->current_turn = STRAIGHT;
    this->target_turn = STRAIGHT;
}

/*
 *  Method to wake the pilot, giving it the target coordinate.
 */
void Pilot::wake(Coordinate target_lat, Coordinate target_long, Coordinate curr_lat, Coordinate curr_long)
{
    this->p = new Pathfinder(curr_lat, curr_long, target_lat, target_long);
    this->p->findPath();
    desired_heading = 358.0;//p->getAngle();
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
        else if (target_turn == ContinuousServo::LEFT)
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
 * servoR_status acts as a public accessor for the read method of servoR
 */
int Pilot::servoR_status(void)
{
    return servoR->readMicroseconds();
}

/* 
 * servoR_status acts as a public accessor for the read method of servoL
 */
int Pilot::servoL_status(void)
{
    return servoL->readMicroseconds();
}

/* 
 * get_turn returns the current turn of the pilot
 */
int Pilot::get_turn(void)
{
    return current_turn;
}

/* 
 * servo_test turns and resets both servos to indicate servo power and attachment
 */
void Pilot::servo_test(void)
{   
    servoL->turn();
    delay(500);
    servoL->reset();

    delay(1000);

    servoR->turn();
    delay(500);
    servoR->reset();
}

void Pilot::servo_init(void)
{
    this->servoR = new ContinuousServo(ContinuousServo::RIGHT, SRVOR_DTA);
    this->servoL = new ContinuousServo(ContinuousServo::LEFT, SRVOL_DTA);   
}

void Pilot::sleep(void)
{
    straight();
}
/* PRIVATE METHODS */

/*
 *  Makes the box take a right turn
 */
void Pilot::turn_right()
{
    if (current_turn == ContinuousServo::LEFT)
        straight();
    servoR->turn();
    current_turn = ContinuousServo::RIGHT;
}
/*
* Makes the box take a left turn
*/
void Pilot::turn_left()
{
    if (current_turn == ContinuousServo::RIGHT)
        straight();
    servoL->turn();
    current_turn = ContinuousServo::LEFT;
}

void Pilot::straight()
{
    if (current_turn == ContinuousServo::RIGHT)
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
        return ContinuousServo::RIGHT;
    else
        return ContinuousServo::LEFT;
}