#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COUNT 5

int randint(int, int);
double randReal(double, double);
char* randomName(char*);
int compTitle_ao(const void*, const void*);
int compTitle_do(const void*, const void*);
int compAuthor_ao(const void*, const void*);
int compAuthor_do(const void*, const void*);
int compPages_ao(const void*, const void*);
int compPages_do(const void*, const void*);

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

typedef struct book
{
    char title[150];
    char author[100];
    unsigned int count_pages;
    double price;
} book_t;

int linearSearch(book_t*, int, double);

int main()
{
    book_t books[COUNT];
    srand(time(NULL));
    for(int i = 0; i < COUNT; i++)
    {
        randomName(books[i].title);
        randomName(books[i].author);
        books[i].count_pages = randint(5, 2000);
        books[i].price = randReal(1.00, 1000.00);
    }

    qsort(books, COUNT, sizeof(*books), compTitle_ao);
    //qsort(books, COUNT, sizeof(*books), compAuthor_ao);
    //qsort(books, COUNT, sizeof(*books), compPages_ao);

    for(int i = 0; i < COUNT; i++)
    {
        printf("%d. Title: %s Author: %s Pages: %u Price: %.2lf\n", i + 1, books[i].title, books[i].author, books[i].count_pages, books[i].price);
    }
    if(linearSearch(books, COUNT, 20.50) == -1)
    {
        fprintf(stderr, "Invalid book!\n");
        return -1;
    }
    int index = linearSearch(books, COUNT, 20.50);
    printf("The first book that costs %lf is: %s\n", 20.50, books[index].title);
    return 0;
}

int compTitle_ao(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return strcmp(book1.title, book2.title);
}

int compTitle_do(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return strcmp(book2.title, book1.title);
}

int compAuthor_ao(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return strcmp(book1.author, book2.author);
}

int compAuthor_do(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return strcmp(book2.author, book1.author);
}

int compPages_ao(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return book1.count_pages - book2.count_pages;
}

int compPages_do(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    return book2.count_pages - book1.count_pages;
}

int compPrice_ao(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    if (fabs(book1.price - book2.price) < 0.01)
    {
        return 0;
    } 
    else if (book1.price < book2.price)
    {
        return -1;
    }
    return 1;
}

int compPrice_do(const void* book1p, const void* book2p)
{
    book_t book1 = *(book_t*)book1p;
    book_t book2 = *(book_t*)book2p;
    if (fabs(book1.price - book2.price) < 0.01)
    {
        return 0;
    } 
    else if (book1.price > book2.price)
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
    int n = randint(10, 20);
    for (int i = 1; i < n; i++)
    {
        int currRand = randint('A', 'z');
        if(currRand >= '[' && currRand <= '`')
        {
            i--;
            continue;
        }
        name[index++] = currRand;
    }
    name[index] = '\0';
    return name;
}

int linearSearch(book_t* books, int n, double x)
{

    for(int i = 0; i < n; i++)
    {
        if(books[i].price == x)
        {
            return i;
        }
    }
    return -1;
}