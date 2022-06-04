#include <stdio.h>
#include <math.h>

int main()
{
    double r, h, v;
    printf("R = ");
    scanf("%lf", &r);
    printf("H = ");
    scanf("%lf", &h);
    v = M_PI * pow(r, 2) * h;
    printf("Capacity is: %.2lf\n", v);
    return 0;
}
