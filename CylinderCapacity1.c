#include <stdio.h>
#include <math.h>

int main()
{
    double r, h, l, v, area;
    printf("R = ");
    scanf("%lf", &r);
    printf("L = ");
    scanf("%lf", &l);
    printf("H = ");
    scanf("%lf", &h);

    area = pow(cos((r - h) / r), -1) * pow(r, 2) - (r - h) * sqrt(2 * r * h - pow(h, 2));
    v = area * l;
    printf("Capacity is: %.2lf\n", v);
    return 0;
}
