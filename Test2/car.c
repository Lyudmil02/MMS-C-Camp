#include "car.h"

int compMaxspeed_do(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    return car2.maxspeed - car1.maxspeed;
}

int compMaxspeed_ao(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    return car1.maxspeed - car2.maxspeed;
}

int compModel_ao(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    return strcmp(car1.model, car2.model);
}

int compModel_do(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    return strcmp(car2.model, car1.model);
}

int compPrice_ao(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    if (fabs(car1.price - car2.price) < 0.01)
    {
        return 0;
    } 
    else if (car1.price < car2.price)
    {
        return -1;
    }
    return 1;
}

int compPrice_do(const void* car1p, const void* car2p)
{
    car_t car1 = *(car_t*)car1p;
    car_t car2 = *(car_t*)car2p;
    if (fabs(car1.price - car2.price) < 0.01)
    {
        return 0;
    } 
    else if (car1.price > car2.price)
    {
        return -1;
    }
    return 1;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* randomName(char* name)
{
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(4, 10);
    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

int (*getComparator(int n))(const void* car1p, const void* car2p)
{
    switch(n)
    {
        case 1:
            return compModel_ao(car1p, car2p);
        break;
        case 2:
            return compModel_do(car1p, car2p);
        break;
        case 3:
            return compMaxspeed_ao(car1p, car2p);
        break;
        case 4:
            return compMaxspeed_do(car1p, car2p);
        break;
        case 5:
            return compPrice_ao(car1p, car2p);
        break;
        case 6:
            return compPrice_do(car1p, car2p);
        break;
    }
}