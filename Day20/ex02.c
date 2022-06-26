#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* sortNums(void*);
int cmpInt(const void*, const void*);

int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        printf("Invalid arguments");
        return EXIT_FAILURE;
    }
    pthread_t* threads = malloc(sizeof(pthread_t) * (argc - 1));
    for(int i = 1, j = 0; i < argc; i++, j++)
    {
        FILE* fp = fopen(argv[i], "rb+");
        if(!fp)
        {
            perror("couldn't open file");
            return EXIT_FAILURE;
        }
        if(pthread_create(threads+j, NULL, sortNums, fp))
        {
            perror("creating");
            return EXIT_FAILURE;
        }
    }
    for(int i = 0; i < argc - 1; i++)
    {
        if(pthread_join(threads[i], NULL))
        {
            perror("joinning");
            return EXIT_FAILURE;
        }
    }
    return 0;
}

void* sortNums(void* arg)
{
    FILE* fp = (FILE*)arg;
    int countNumbers = 0;
    int readNumber;
    while(fread(&readNumber, sizeof(int), 1, fp) != EOF)
    {
        countNumbers++;
    }
    rewind(fp);
    int* numbers = malloc(sizeof(int) * countNumbers);
    if(!numbers)
    {
        perror("malloc");
    }
    for(int i = 0; i < countNumbers; i++)
    {
        fread(numbers+i, sizeof(int), 1, fp);
    }
    rewind(fp);
    qsort(numbers, countNumbers, sizeof(int), cmpInt);
    for(int i = 0; i < countNumbers; i++)
    {
        fwrite(numbers+i, sizeof(int), 1, fp);
    }
    free(numbers);
    fclose(fp);
}

int cmpInt(const void* el1, const void* el2)
{
    int num1 = *(int*)el1;
    int num2 = *(int*)el2;
    return num1 - num2;
}