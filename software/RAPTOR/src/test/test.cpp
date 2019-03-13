/*
*
*/
#include "test.h"

int readRC(uint8_t pin)
{
    return (1730 - pulseIn(pin, HIGH, 20000)) / 2.55; // TODO change based on needed output
}

/*
 * custom_angle returns an angle parsed from user input
 */
float custom_angle(void)
{
    Serial.print("\nPlease input an angle: ");
    while (Serial.available() == 0)
        ; // wait for user input
    float angle = Serial.parseFloat();
    return angle;
}