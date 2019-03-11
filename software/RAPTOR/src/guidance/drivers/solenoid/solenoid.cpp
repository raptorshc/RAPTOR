/*

*/
#include "solenoid.h"
#include <Arduino.h>

#define SOLP_DTA 9 // Parafoil solenoid
#define SOLC_DTA 8 // Cutdown solenoid

#define SWP_PIN A0 // Parafoil solenoid switch
#define SWC_PIN A1 // Cutdown solenoid switch

#define LEDP_DTA A2 // Parafoil solenoid indicator light
#define LEDC_DTA A3 // Cutdown solenoid indicator light

void sol_init(void)
{
    // out pins
    pinMode(SOLP_DTA, OUTPUT); // Set Parafoil solenoid to output
    pinMode(SOLC_DTA, OUTPUT); // Set Cutdown solenoid to output

    // switch pins
    pinMode(SWP_PIN, INPUT); // Set Parafoil switch to input
    pinMode(SWC_PIN, INPUT); // Set Cutdown switch to input

    // led pins
    pinMode(LEDP_DTA, OUTPUT); // Set Parafoil LED to output
    pinMode(LEDC_DTA, OUTPUT); // Set Cutdown LED to output

    digitalWrite(SOLP_DTA, HIGH); // Engage Parafoil solenoid
    digitalWrite(SOLC_DTA, HIGH); // Engage Cutdown solenoid

    digitalWrite(LEDP_DTA, LOW); // turn off parafoil solenoid led
    digitalWrite(LEDC_DTA, LOW); // turn off cutdown solenoid led
}

void cutdown(void)
{
    digitalWrite(SOLC_DTA, LOW);
}

void parafoil_deploy(void)
{
    digitalWrite(SOLP_DTA, LOW);
}

bool cutdown_switch(void)
{
    if (digitalRead(SWC_PIN))
    {
        digitalWrite(LEDC_DTA, HIGH);
        return true;
    }
    else
    {
        digitalWrite(LEDC_DTA, LOW);
        return false;
    }
}

bool parafoil_switch(void)
{
    if (digitalRead(SWP_PIN))
    {
        digitalWrite(LEDP_DTA, HIGH);
        return true;
    }
    else
    {
        digitalWrite(LEDP_DTA, LOW);
        return false;
    }
}