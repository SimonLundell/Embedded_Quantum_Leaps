
int main()
{
    int count = 0;
    while (count < 21)
    {
        if ((count & 1) != 0) // Bitwise and
        {
          /* Do something when counter is odd*/
        }
        else
        {
          /* Do something else when counter is even */
        }
        count++;
    }
    
    return 0;
}
