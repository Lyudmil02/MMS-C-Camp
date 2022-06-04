#include <stdio.h>
#include <math.h>

int main()
{
    double mass, height, bodyMassIndex, newBodyMassIndex;

    printf("Enter mass: ");
    scanf("%lf", &mass);
    printf("Enter height: ");
    scanf("%lf", &height);

    bodyMassIndex = mass / pow(height, 2);

    newBodyMassIndex = mass / pow(height, 2.5);

    printf("Body mass index is: %.2lf\n", bodyMassIndex);
    printf("Body mass index with new formula is: %.2lf\n", newBodyMassIndex);
    return 0;
}