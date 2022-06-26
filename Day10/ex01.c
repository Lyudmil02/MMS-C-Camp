#include <stdio.h>
#include <stdint.h>

#define PRINTBIT(mask, bit) (((mask) & ((1UL) << (bit))) >> (bit))

typedef union real
{
    double num;
    uint64_t bits;
}real_t;


int main()
{
    real_t rNum;
    printf("Enter a number: ");
    scanf("%lf", &(rNum.num));
    for(int i = 63; i >= 0; i--)
    {
        printf("%lu", PRINTBIT(rNum.bits, i));
        //printf("%lu", (rNum.bits & (1UL << i)) >> i);
    }
    putchar('\n');
    return 0;
}