#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double* S, double* P);


int main()
{
    double a, b, c, X1, X2;
    scanf("%lf %lf %lf", &a, &b, &c);

    if(quadEq(a, b, c, &X1, &X2) == -1)
    {
        fprintf(stderr, "No real roots!\n");
    }
    else
    {
        printf("x1 = %.2lf\n", X1);
        printf("x2 = %.2lf\n", X2);
    }
    return 0;
}

int quadEq(double a, double b, double c, double* X1, double* X2)
{
    double d = (b * b) - (4 * a * c);
    if(d < 0)
    {
        return -1;
    }
    *X1 = (-b + sqrt(d)) / 2 * a;
    *X2 = (-b - sqrt(d)) / 2 * a;
    return 0;

}