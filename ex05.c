#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask);


int main()
{
    unsigned count = onesCount(411);
    printf("%u\n", count);
    return 0;
}

unsigned onesCount(uint64_t mask)
{
    unsigned count;
    for(int bit = 0; bit < sizeof(mask) * 8 - 1; bit++)
    {
        if((mask & (1<<bit))>>bit == 1UL)
        {
            count++;
        }
    }
    return count;
}
