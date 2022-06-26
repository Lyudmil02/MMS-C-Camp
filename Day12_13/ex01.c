#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned char chekBit(uint16_t);

int main()
{
    char c = '1';
    printf("%c\n", c);
    printf("%d\n", c);
    //printf("%d\n", chekBit(5));
    return 0;
}

unsigned char chekBit(uint16_t num)
{
    int countOnes = 0;
    for(int i = 0; i < sizeof(num) * 8; i++)
    {
        if(num & (1 << i))
        {
            countOnes++;
            if(countOnes > 1)
            {
                return 0;
            }
        }
    }
    if(countOnes == 1)
    {
        return 1;
    }
    return 0;
}