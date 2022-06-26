#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 5

typedef struct book
{
    char title[151];
    char author[101];
    int pages;
    double price;
}book_t;

typedef struct bookList
{
    book_t value;
    struct bookList* next;
    
}bookList_t;


int randint(int,int);
double randReal(double,double);
void randName(char*);
void push(bookList_t**, book_t);
void printElements_file(bookList_t*, char*);
void listFree(bookList_t**);
bookList_t* sortedMerge(bookList_t*, bookList_t*, int(*)(char*, char*));
void frontBackSplit(bookList_t*, bookList_t**, bookList_t**);
void mergeSort(bookList_t**, int(*)(char*, char*));
int compareTitles(char*, char*);

int main(int argc, char **argv)
{
    FILE *fp;
    if((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Couldnt open file\n");
        return EXIT_FAILURE;
    }
    book_t temp;
    bookList_t *head = NULL;
    for(int i = 0; i < COUNT; i++)
    {
        fread(&temp, sizeof(temp), 1, fp);
        push(&head, temp);
    }
    mergeSort(&head, compareTitles);
    printElements_file(head, argv[2]);
    listFree(&head);
    fclose(fp);
    return 0;
}

bookList_t* sortedMerge(bookList_t* listA, bookList_t* listB, int(*cmp)(char*, char*))
{
    bookList_t* sorted = NULL;
    if (listA == NULL)
    {
        return listB;
    }
    if (listB == NULL)
    {
        return listA;
    }
    if (cmp(listA->value.title, listB->value.title) > 0)
    {
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } 
    else 
    {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(bookList_t* list, bookList_t** front, bookList_t** back)
{
    bookList_t* slow = list;
    bookList_t* fast = list->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast  != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(bookList_t** list, int(*cmp)(char*, char*))
{
    if (*list == NULL || (*list)->next == NULL)
    {
        return;
    }
    bookList_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

int compareTitles(char* t1, char* t2)
{
    return strcmp(t1, t2);
}

void push(bookList_t** head, book_t value)
{
    bookList_t* temp = malloc(sizeof(bookList_t));
    strncpy(temp->value.title, value.title, 150);
    strncpy(temp->value.author, value.author, 100);
    temp->value.pages = value.pages;
    temp->value.price = value.price;
    temp->next = (*head);
    (*head) = temp;
}

void listFree(bookList_t** list)
{
    bookList_t *current = *list, *prev;
    while (current)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void printElements_file(bookList_t* head, char* nameOfFile)
{
    FILE* fp;
    if((fp = fopen(nameOfFile, "w")) == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        fprintf(fp, "%s %s %d %.2lf\n", head->value.title, head->value.author, head->value.pages, head->value.price);
        head = head->next;
    }
    fclose(fp);
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
    name[i] = ' ';
    i++;
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