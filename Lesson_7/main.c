#include "LM4F120H5QR.h"
// Instead of 2,4,8, shift bit 1,2,3 times (0010,0100,1000)
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main()
{
    // Bitset idiom |=
    // Bit reset idiom &= ~
    SYSCTL_RCGCGPIO_R |= (1 << 5); // Enables GPIO F
    SYSCTL_GPIOHBCTL_R |= (1 << 5); // Enables high performance bus, makes all GPIO ports need "_AHB"
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); // Pin-direction setting pin 1,2,3
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN); // Digital function register setting pin 1,2,3
    
    GPIO_PORTF_DATA_BITS_R[LED_BLUE] = LED_BLUE; // Turn the blue LED on
    while (1)
    {
        // All below means the same thing
        //*((unsigned long volatile*)(0x40025000 + (LED_RED << 2))) = LED_RED; // Bitwise arithmatic
        //*(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED; // Pointer arithmatic
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED; // Array arithmatic
          
        GPIO_PORTF_AHB_DATA_R |= LED_RED; // bitwise or-equals to
        int volatile counter[2] = {0,0}; 
        while (counter[0] < 1000000)
        {
            counter[0]++;
        }
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        while ((*counter + 1) < 1000000) // Dereferencing a pointer and incrementing, same as counter[1]
        {
            counter[1]++;
        }
    }
    
    return 0;
}
