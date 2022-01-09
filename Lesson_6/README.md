Program to keep blue LED on, but blink red LED.

Using bitwise operators for setting / resetting bits.

/*
    unsigned int a = 0x5A5A5A5A;
    unsigned int b = 0xDEADBEEF;
    unsigned int c;
    
    // How it works on unsigned numbers
    c = a | b; // bitwise and
    c = a & b; // bitwise or
    c = a ^ b; // bitwise xor
    c = ~b; // not (twos complement)
    c = b >> 1; // bitshift right. Shifting all bits right with 1 corresponds to divide by 2. LSRS - Logical right shift
    c = b << 3; // bitshift left. left shift by 3 corresponds to int * 2^3
    
    // Signed numbers
    int x = 1024;
    int y = -1024;
    int z;
    
    z = x >> 3; // Shifts 0's into most significant positions. 
    z = y >> 3; // Shifts 1's into most significant positions. ASRS - Arithmetic right shift
    // Above done to preserve the sign. Both correspond to int / 2^3
*/