#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5

typedef struct book
{
    char title[151];
    char author[101];
    int pages;
    double price;
}book_t;


int randint(int,int);
double randReal(double,double);
void randName(char*);

int main(int argc, char **argv){
    srand(time(NULL));
    book_t books[COUNT];
    for(int i = 0; i < COUNT; i++)
    {
        randName(books[i].title);
        randName(books[i].author);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }
    FILE *fp;
    if((fp = fopen(argv[1], "wb")) == NULL)
    {
        fprintf(stderr, "Couldnt open file\n");
        return EXIT_FAILURE;
    }
    
    for(int i = 0; i < COUNT; i++)
    {
        fprintf(fp, "%s %s %d %.2lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
    return 0;
}

void randName(char *name)
{
    int i = 0;
    name[i] = randint('A', 'Z');
    i++;
    int n = randint(5, 10);
    for(int j = 0;j < n; i++, j++)
    {
        name[i] = randint('a', 'z');
    }
    name[i] = randint('A', 'Z');
    i++;
    n = randint(5, 10);
    for(int j = 0; j < n; i++, j++)
    {
        name[i] = randint('a', 'z');
    }
    name[i] = 0;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}