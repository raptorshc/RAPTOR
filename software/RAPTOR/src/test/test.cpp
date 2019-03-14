/*
*
*/
#include "test.h"

int readRC(uint8_t pin)
{
    float average = 0;
    for(int i = 0; i < 10; i++){
        float result = pulseIn(pin, HIGH, 20000);
        average += result;
    }
    return average / 10;
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