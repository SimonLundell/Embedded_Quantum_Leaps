int count = 0;

int main()
{
    int* p_int;
    p_int = &count;
    while (*p_int < 21)
    {
        (*p_int)++;
    }
    
    p_int = (int*)0x20000002; // sets p_int to address
    *p_int = 0xDEADBEEF; // assigns value to deadbeef, bigger than int.
    /*
    Cortex-M0 would have problems with accessing misaligned data items. 
    Specifically, 32-bit words must be aligned at addresses divisible by 4 and 16-bit half-words must be aligned at addresses divisible by 2. 
    The bigger members of the Cortex-M family (M3/M4/M7) don't have such restrictions
    */
    
    return 0;
}
