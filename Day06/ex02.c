#include <stdio.h>
#include <math.h>

double power(double, int);
double sine(int);
int fact(int);


int main()
{
    int deg = 45;
    printf("sin(%d) = %.3lf\n", deg, sine(deg));
}

double sine(int deg) {
    deg %= 360;
    double rad = deg * 3.14159 / 180;
    double sin = 0;

    for(int i = 0; i < 5; i++) 
    {
        sin += power(-1, i) * power(rad, 2 * i + 1) / fact(2 * i + 1);
    }
    return sin;
}

double power(double num, int pow)
{
    if(pow <= 0)
    {
        return 1;
    }
    return num * power(num, pow - 1);
}

int fact(int num)
{
    return num <= 0 ? 1 : num * fact(num - 1);
}