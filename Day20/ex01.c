#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* routine(void*);
void randName(char *);
int randint(int, int);

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    pthread_t* threads = malloc(n * sizeof(pthread_t));
    if(!threads)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }
    for(int i = 0; i < n; i++)
    {
        srand(time(NULL) + i);
        if(pthread_create(threads+i, NULL, routine, NULL))
        {
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for(int i = 0; i < n; i++)
    {
        char* str;
        if(pthread_join(threads[i], (void**)&str))
        {
            perror("join");
            return EXIT_FAILURE;
        }
        printf("%s\n", str);
        free(str);
    }
    free(threads);
    return 0;
}

void* routine(void* arg)
{
    char* str = malloc(sizeof(char) * 11);
    randName(str);
    return str;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void randName(char *name)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        int flag = randint(0, 1);
        if(flag)
        {
            name[i] = randint('a', 'z');
        }
        else
        {
            name[i] = randint('A', 'Z');
        }
    }
    name[i] = 0;
}