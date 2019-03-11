/*
  pilot.cpp - 
	DESCRIPTION NEEDED.
	Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#include "pilot.h"
#include <stdio.h>
#include <Arduino.h>

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
 *  Method to wake the pilot, giving it the current and target coordinates.
 */
void Pilot::wake(Coordinate current, Coordinate target)
{
    this->p = new Pathfinder(current, target);
    this->p->find_path();
    desired_heading = p->get_angle();

    Serial.print("Desired heading:");
    Serial.print(desired_heading);
    Serial.print("\n");
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

/* 
 * servo_init initializes both the left and right servos
 */
void Pilot::servo_init(void)
{
    this->servoR = new ContinuousServo(ContinuousServo::RIGHT, SRVOR_DTA);
    this->servoL = new ContinuousServo(ContinuousServo::LEFT, SRVOL_DTA);
}

/* 
 * sleep shuts down the pilot and sets the payload straight
 */
void Pilot::sleep(void)
{
    straight();
}
/* PRIVATE METHODS */

/* 
 * find_turn takes the current angle and finds the correct 
 * turn based on basic heading math
 */
int Pilot::find_turn(float curr_angle)
{
    float alpha_angle, beta_angle;

    if (abs(abs(curr_angle - desired_heading) - 360) < 15 || abs(desired_heading - curr_angle) < 15)
        return STRAIGHT; // if the difference between our current and desired heading is less than 15,  continue straight

    alpha_angle = desired_heading + 90; // alpha angle is in the quadrant to the left of our target angle
    beta_angle = desired_heading + 270; // beta angle is in the quadrant to the right

    if (alpha_angle > 360)
        alpha_angle -= 360;
    if (beta_angle > 360)
        beta_angle -= 360;

    /* Determine if alpha or beta angle is closer to our current angle, adjust based on that. */
    float alpha_dif = abs(alpha_angle - curr_angle);
    float beta_dif = abs(beta_angle - curr_angle);

    /* As we have created a straight line across the graph, neither difference should be greater than 180 degrees */
    if (alpha_dif > 180)
        alpha_dif = 360 - alpha_dif;
    if (beta_dif > 180)
        beta_dif = 360 - beta_dif;

    /* If we are closer to the left, turn right, and vice versa */
    if (alpha_dif > beta_dif)
        return ContinuousServo::RIGHT;
    else
        return ContinuousServo::LEFT;
}

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

/*
* Straightens out the payload
*/
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