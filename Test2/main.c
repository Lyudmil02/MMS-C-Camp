#include "car.h"
#include "car.c"

#define COUNT 10

int main()
{
    srand(time(NULL));
    car_t cars[COUNT];
    for(int i  = 0; i < COUNT; i++)
    {
        randomName(cars[i].model);
        cars[i].maxspeed = randint(100, 300);
        cars[i].price = randReal(1000.00, 100000.00);
    }
    int n = 0;
    printf("Enter comp: ");
    scanf("%d", &n);

    getComparator(n);

    qsort(cars, COUNT, sizeof(*cars), compPrice_ao);
    //qsort(cars, COUNT, sizeof(*cars), compMaxspeed_ao);
    //qsort(cars, COUNT, sizeof(*cars), compModel_do);

    for(int i  = 0; i < COUNT; i++)
    {
        printf("%d. %s %u %f\n", i + 1, cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}