/*

*/
#include "Pilot.h"

#define SRVOL_DTA 6 // Left servo
#define SRVOR_DTA 5 // Right servo

#define STRAIGHT 3

/* PUBLIC METHODS */

/*
 *  Constructor for Pilot 
 */
Pilot::Pilot()
{
    this->servoR = new ContinuousServo(ContinuousServo::RIGHT);
    this->servoL = new ContinuousServo(ContinuousServo::LEFT);
    this->turning = STRAIGHT;
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
}

/*
 *  fly will .. 
 */
void Pilot::fly(float curr_angle)
{
    uint8_t dirTurn = STRAIGHT;
    bool should_turn = shouldTurn(dirTurn, curr_angle);
    if (turning == STRAIGHT)
    {
        if (should_turn)
        {
            if (dirTurn)
            {
                turn_left();
            }
            else
            {
                turn_right();
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
 * test will turn the payload left, right, then straighten out
 */
void Pilot::test(void)
{
}

/* 
 * servoR_status acts as a public accessor for the readMicroseconds method of servoR
 */
uint8_t Pilot::servoR_status(void)
{
    return servoR->readMicroseconds();
}

/* 
 * servoR_status acts as a public accessor for the readMicroseconds method of servoL
 */
uint8_t Pilot::servoL_status(void)
{
    servoL->readMicroseconds();
}

/* PRIVATE METHODS */

/*
 *  Makes the box take a right turn
 */
void Pilot::turn_right()
{
    turning = ContinuousServo::RIGHT;
    servoR->turn();
}
/*
* Makes the box take a left turn
*/
void Pilot::turn_left()
{
    turning = ContinuousServo::LEFT;
    servoL->turn();
}

void Pilot::straight()
{
    if (turning == ContinuousServo::RIGHT)
        servoR->reset();
    else
        servoL->reset();

    turning = STRAIGHT;
}

/* 
 * adjustPath will take in the current and optimal paths and 
 * calculate which way to turn and by how much. 
 * returns if we should turn
 */
bool Pilot::shouldTurn(uint8_t &dirTurn, float curr_angle)
{
    float alpha_angle, beta_angle;

    alpha_angle = desired_heading + 90; //Alpha angle is in the quadrant to the left of our target angle
    beta_angle = desired_heading + 270; //Beta angle is in the quadrant to the right

    /* Determine if alpha or beta angle is closer to our current angle, adjust based on that. */
    if (abs(alpha_angle - curr_angle) > abs(beta_angle - curr_angle))
        dirTurn = ContinuousServo::RIGHT;
    else
        dirTurn = ContinuousServo::LEFT;
    if (abs(curr_angle - desired_heading - 360) < 15 || abs(desired_heading - curr_angle) < 15)
        return false;
    else
        return true;
}