#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

#define ITEMS_COUNT 5

typedef struct item
{
    uint16_t number;
    char description[250];
    double weight;
    double price;
} item_t;

uint16_t randint(int, int);
double randReal(double, double);
char* randomDescription(char*);
double totalItemsWeight(item_t*);
item_t* minPriceItem(item_t*);

int main()
{
    item_t items[ITEMS_COUNT];
    srand(time(NULL));
    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        items[i].number = randint(0, 9);
        randomDescription(items[i].description);
        items[i].weight = randReal(0.100, 100.0);
        items[i].price = randReal(1.00, 1500.00);
    }

    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        printf("%u\n", items[i].number);
        printf("%s\n", items[i].description);
        printf("%lf\n", items[i].weight);
        printf("%lf\n", items[i].price);
    }

    printf("\nTotal weight: %lf\n", totalItemsWeight(items));
    
    item_t* minPrice = minPriceItem(items);
    printf("The cheapest item is: %lf\n", minPrice->price);
    
}

uint16_t randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* randomDescription(char* description)
{
    unsigned index = 0;
    int n = randint(1, 10);
    int m = randint(5, 10);
    description[index++] = randint('A', 'Z');
    for(int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int currRand = randint('a', 'z');
            description[index++] = currRand;
        }
        description[index++] = ' ';
    }
    
    description[index] = '\0';
    return description;
}

double totalItemsWeight(item_t* items)
{
    double totalWeight = 0.0;
    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        totalWeight += items[i].weight;
    }
    if(totalWeight == 0.0)
    {
        return -1;
    }
    return totalWeight;
}

item_t* minPriceItem(item_t* items)
{
    double minNum = INT_MAX;
    int currItemIndex;
    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        if(items[i].price < minNum)
        {
            minNum = items[i].price;
            currItemIndex = i;
        }
    }
    if(minNum == INT_MAX)
    {
        return NULL;
    }
    return &items[currItemIndex];
}