#include "src/raptor.h"
#include <Streaming.h>
#include <avr/wdt.h>

Raptor *raptor;

// #define RC_TEST

void setup()
{
    wdt_enable(WDTO_2S); // TODO MAKE SURE WE'RE PATTING THE DOG IN THE FINAL CODE
    raptor = new Raptor();
}

void loop()
{
    // #ifdef RC_TEST
    //     raptor->rc_test();
    // #endif
    raptor->launch();
    // raptor->ascent();
    // raptor->descent();
    // raptor->landed();
}

/*
 *  interrupt each millisecond to read from the GPS.
 */
SIGNAL(TIMER0_COMPA_vect)
{
    wdt_reset(); // pat the dog
    // static int counter = 0;
    // Serial << "reading gps " << counter++ << "\n";
    char c = raptor->environment->gps->read();
    if(c) UDR0 = c;
}