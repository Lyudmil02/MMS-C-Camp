#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double* P);

int main()
{
    double a, b, c, S, P;

    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        if(triangle(a, b, c, &S, &P) == -1)
        {
            fprintf(stderr, "Invalid triangle sides!\n");
            continue;
        }
        triangle(a, b, c, &S, &P);
        printf("S = %.2lf\n", S);
        printf("P = %.2lf\n", P);
    }
}

int triangle(double a, double b, double c, double* S, double* P)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return -1;
    }
    *P = a + b + c;
    double p = *P / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}
