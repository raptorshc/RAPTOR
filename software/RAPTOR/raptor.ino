#include "src/raptor.h"
Raptor *raptor;

#define RC_TEST

void setup()
{
    raptor = new Raptor();
}

void loop()
{
    #ifdef RC_TEST
        raptor->rc_test();
    #endif
    raptor->launch();
    raptor->ascent();
    raptor->descent();
    raptor->landed();
}