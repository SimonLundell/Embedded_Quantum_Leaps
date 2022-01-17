#include "LM4F120H5QR.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void delay(unsigned int iter); // "Prototype". Used together with prototype setting in compiler to preserve bw-compat.

void delay(unsigned int iter) {
  int volatile counter = 0;
  while (counter < iter)
  {
        counter++;
  }
}

// When running the program, check the SP register, which is the call stack.
// The stack holds the variables of the functions, and the return addresses of the functions

int main()
{
    SYSCTL_RCGCGPIO_R |= (1 << 5); 
    SYSCTL_GPIOHBCTL_R |= (1 << 5); 
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); 
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN); 
    
    GPIO_PORTF_DATA_BITS_R[LED_BLUE] = LED_BLUE; 
    while (1)
    {

        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED; 
          
        GPIO_PORTF_AHB_DATA_R |= LED_RED; 
        delay(1000000);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        delay(1000000);
    }
    
    return 0;
}
