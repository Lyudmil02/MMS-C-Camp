#include <stdio.h>
#include <stdint.h>

#define CHECKBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))

typedef union shortnum
{
    uint16_t num;
    uint8_t byte[2];
}shortNum_t;


void swapBytes(shortNum_t*);

int main()
{
    shortNum_t shortNum;
    shortNum.num = 0b0000100011110111U;
    for(int i = 15; i >= 0; i--)
    {
        printf("%d", CHECKBIT(shortNum.num, i));
    }
    putchar('\n');
    swapBytes(&shortNum);
    for(int i = 15; i >= 0; i--)
    {
        printf("%d", CHECKBIT(shortNum.num, i));
    }
    putchar('\n');
    return 0;
}