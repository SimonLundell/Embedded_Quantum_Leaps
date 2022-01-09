int count = 0;

int main()
{
    // Dereferencing the address to write values to them, making the LED blink RGB
    *((unsigned int*)0x400FE608U) = 0x20U; // Enables GPIO F
    *((unsigned int*)0x40025400U) = 0x0EU; // Pin-direction setting pin 1,2,3
    *((unsigned int*)0x4002551CU) = 0x0EU; // Digital function register setting pin 1,2,3
    
    
    while (1)
    {
        // Counters to introduce delay, making the LED on board blinking visible to human eye.
        // If on simulator, monitor the addrexx 0x400254FC and see when 0x20 / 0x00.
        *((unsigned int*)0x400253FCU) = 0x02U; // GPIO F Data register bit 1 set, light up the LED
        int counter = 0;
        while (counter < 1000000)
        {
            counter++;
        }
        
        *((unsigned int*)0x400253FCU) = 0x00U; // GPIO F Data register bit 1 clear, turn of LED
        counter = 0;
        while (counter < 1000000)
        {
            counter++;
        }
    }
    
    return 0;
}
