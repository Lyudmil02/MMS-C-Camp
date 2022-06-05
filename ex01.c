#include <stdio.h>

int main()
{
    double num1, num2, result = 0;
    char sign;
    
    while(scanf("%lf %c %lf", &num1, &sign, & num2) != EOF)
    {
        if(sign == '+')
        {
            result = num1 + num2;
        }
        else if(sign == '-')
        {
            result = num1 - num2;
        }
        else if(sign == '*')
        {
            result = num1 * num2;
        }
        else if(sign == '/')
        {
            result = num1 / num2;
        }
        else
        {
            fprintf(stderr, "Invalid operation!\n");
            continue;
        }
        printf("Result = %.2lf\n", result);
    }
    
}