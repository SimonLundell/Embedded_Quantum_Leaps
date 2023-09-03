#include "delay.h"

void delay(unsigned int iter) {
  int volatile counter = 0;
  while (counter < iter)
  {
        counter++;
  }
}