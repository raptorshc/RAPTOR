#include "src/raptor.h"
Raptor *raptor;

void setup()
{
    raptor = new Raptor();
}

void loop()
{
    raptor->launch();
    raptor->ascent();
    raptor->descent();
    raptor->landed();
}