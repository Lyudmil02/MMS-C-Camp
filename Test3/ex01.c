#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 5

typedef struct point
{
    double x;
    double y;
} point_t;

typedef struct rectangle
{
    point_t A;
    point_t B;
} rectangle_t;

double randReal(double, double);
double areaRects(rectangle_t*);
void filterRects(rectangle_t**, double, double);

int main()
{
    point_t p1, p2;
    rectangle_t* rect = malloc(sizeof(rectangle_t) * COUNT);

    for(int i = 0; i < COUNT; i++)
    {
        rect[i].A.x = randReal(-10, 10);
        rect[i].A.y = randReal(-10, 10);

        rect[i].B.x = randReal(-10, 10);
        rect[i].B.y = randReal(-10, 10);
    }

    for(int i = 0; i < COUNT; i++)
    {
        printf("Rectangle %d\nPoint A: x = %f / y = %f\nPoint B: x = %f / y = %f\n", i + 1, rect[i].A.x, rect[i].A.y, rect[i].B.x, rect[i].B.y);
    }
    printf("Areas on rectangles is: %lf\n", areaRects(rect));
    free(rect);
    return 0;
}

double areaRects(rectangle_t* list)
{
    rectangle_t* current = list;
    double areas = 0.0;
    for(int i = 0; i < COUNT; i++)
    {
        double a = fabs(current[i].A.x - current[i].B.x);
        double b = fabs(current[i].A.y) + fabs(current[i].B.y);
        areas += (2 * a) + (2 * b);
    }
    return areas;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void filterRects(rectangle_t** list, double min, double max)
{
    
}
