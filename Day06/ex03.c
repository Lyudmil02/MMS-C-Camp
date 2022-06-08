#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TDOUBLE 2
#define TCHAR 3
#define TFLOAT 4


void printValue(const void*, uint8_t);

int main()
{
    int num = 23;
    double pi = 3.14564;
    char symbol = 'A';
    printValue(&num, TINT);
    printValue(&pi, TDOUBLE);
    printValue(&symbol, TCHAR);

    return 0;
}

void printValue(const void* valuePtr, uint8_t flag)
{
    if(flag == 1)
    {
        printf("Value: %d\n", *(int*)valuePtr);
    }
    else if(flag == 2)
    {
        printf("Value: %lf\n", *(double*)valuePtr);
    }
    else if(flag == 3)
    {
        printf("Value: %c\n", *(char*)valuePtr);
    }
    else if(flag == 4)
    {
        printf("Value: %f\n", *(float*)valuePtr);
    }
}