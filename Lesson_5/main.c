#include "LM4F120H5QR.h"
/* Macros resolved at compile time */
// #define GPIO_PORTF_DATA_R (*((volatile unsigned long*)(0x400253FC))) From .h of pcb-supplier

int main()
{
    // Using names from supplier .h file
    SYSCTL_RCGCGPIO_R = 0x20U; // Enables GPIO F
    GPIO_PORTF_DIR_R = 0x0EU; // Pin-direction setting pin 1,2,3
    GPIO_PORTF_DEN_R = 0x0EU; // Digital function register setting pin 1,2,3
    
    while (1)
    {
        GPIO_PORTF_DATA_R = 0x02U; // GPIO F Data register bit 1 set, light up the LED
        int volatile counter = 0; // forcing the program to run loop even with higher optimization 
        while (counter < 1000000)
        {
            counter++;
        }
        
        GPIO_PORTF_DATA_R = 0x00U; // GPIO F Data register bit 1 clear, turn of LED
        counter = 0;
        while (counter < 1000000)
        {
            counter++;
        }
    }
    
    return 0;
}
