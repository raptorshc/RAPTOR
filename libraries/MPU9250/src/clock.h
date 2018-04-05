#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <wiring.c> // Defines millis()

int get_ms(unsigned long *count)
{
  if (!count)
  {
    return 1;
  }
  count[0] = millis();
  return 0;
}

#endif
