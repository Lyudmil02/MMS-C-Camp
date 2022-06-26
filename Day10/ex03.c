#include <stdio.h>
#include <stdint.h>

#define PRINTBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))
#define CHECKBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))
#define SETBIT(mask, bit) ((mask) |= ((1) << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= (~(1 << bit)))

int clearBit(uint32_t*, size_t, size_t);
int setBit(uint32_t*, size_t, size_t);
int checkBit(uint32_t*, size_t, unsigned, size_t);

int main()
{
    uint32_t maskArr[] = {3, 16, 33};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 31; j >= 0; j--)
        {
            printf("%d", PRINTBIT(maskArr[i], j));
        }
        putchar('\n');
    }
    if(clearBit(maskArr, 3, 0) == -1)
    {
        printf("Invalid bit!\n");
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 31; j >= 0; j--)
            {
                printf("%d", PRINTBIT(maskArr[i], j));
            }
            putchar('\n');
        }
    }
    if(setBit(maskArr, 3, 30) == -1)
    {
        printf("Invalid bit!\n");
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 31; j >= 0; j--)
            {
                printf("%d", PRINTBIT(maskArr[i], j));
            }
            putchar('\n');
        }
    }
    int bit = checkBit(maskArr, 3, 1, 30);
    if(bit == -1)
    {
        printf("Invalid bit!\n");
    }
    else
    {
        printf("%d\n", bit);
    }
    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    if((bit > 31 && bit < 0) || nitems < 0)
    {
        return -1;
    }
    for(int i = 0; i < nitems; i++)
    {
        CLEARBIT(maskArr[i], bit);
    }
    return 0;
}

int setBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    if((bit > 31 && bit < 0) || nitems < 0)
    {
        return -1;
    }
    for(int i = 0; i < nitems; i++)
    {
        SETBIT(maskArr[i], bit);
    }
    return 0;
}

int checkBit(uint32_t* maskArr, size_t nitems, unsigned index, size_t bit)
{
    if((bit > 31 && bit < 0) || nitems < 0 || index < 0 || index >= nitems)
    {
        return -1;
    }
    return CHECKBIT(maskArr[index], bit);
}