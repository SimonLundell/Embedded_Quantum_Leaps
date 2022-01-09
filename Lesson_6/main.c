#include "LM4F120H5QR.h"
// Instead of 2,4,8, shift bit 1,2,3 times (0010,0100,1000)
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main()
{
    // Bitset idiom |=
    // Bit reset idiom &= ~
    SYSCTL_RCGCGPIO_R |= LED_RED; // Enables GPIO F
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); // Pin-direction setting pin 1,2,3
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN); // Digital function register setting pin 1,2,3
    
    GPIO_PORTF_DATA_R |= LED_BLUE; // Turn the blue LED on
    while (1)
    {
        GPIO_PORTF_DATA_R |= LED_RED; // bitwise or-equals to
        int volatile counter = 0; 
        while (counter < 1000000)
        {
            counter++;
        }
        
        GPIO_PORTF_DATA_R &= ~LED_RED; // GPIO F Data register bit 1 clear, turn of LED
        counter = 0;
        while (counter < 1000000)
        {
            counter++;
        }
    }
    
    return 0;
}
