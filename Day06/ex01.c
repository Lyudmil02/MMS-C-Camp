#include <stdio.h>

int sqrtOfNum(int);

int main()
{
    int num;
    scanf("%d", &num);
    if(sqrtOfNum(num) == -1)
    {
        fprintf(stderr, "Invalid!\n");
        return 0;
    }
    printf("%d\n", sqrtOfNum(num));
    return 0;
}

int sqrtOfNum(int num)
{
    int temp = 1;
    while(1)
    {
        if((temp * temp) == num)
        {
            return temp;
        }
        else if((temp * temp) > num)
        {
            return -1;
        }
        temp++;
    }
}