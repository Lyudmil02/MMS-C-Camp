#include <stdio.h>

int main()
{
    double num1, num2, num3, maxNum = 0;

    scanf("%lf", &num1);
    scanf("%lf", &num2);
    scanf("%lf", &num3);

    if(num1 > num2 && num1 > num3)
    {
        maxNum = num1;
    }
    else if(num2 > num1 && num2 > num3)
    {
        maxNum = num2;
    }
    else if(num3 > num1 && num3 > num2)
    {
        maxNum = num3;
    }

    printf("Max number is: %.2lf\n", maxNum);

}