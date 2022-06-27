#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct{
    char row[5];
    int nRow;
    int *numbers;
    int count;
}row_t;

void *sort(void *);
int compareInt(const void*, const void*);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    pthread_t* threads = malloc(sizeof(pthread_t) * n);
    row_t* rows = malloc(sizeof(row_t) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", rows[i].row);
        scanf("%d", &rows[i].nRow);
        rows[i].numbers = malloc(sizeof(int) * m);
        rows[i].count = m;
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &rows[i].numbers[j]);
        }
        pthread_create(&threads[i], NULL, sort, (void*)&rows[i]);
    }
    char file[50];
    scanf("%s", file);
    FILE* fp = fopen(file, "w");
    for(int i = 0; i < n; i++)
    {
        fprintf(fp, "%s ", rows[i].row);
        fprintf(fp, "%d ", rows[i].nRow);
        for(int j = 0; j < m; j++)
        {
            fprintf(fp, "%d ", rows[i].numbers[j]);
        }
        fputc('\n', fp);
    }
    for(int i = 0; i < n; i++)
    {
        free(rows[i].numbers);
    }
    for(int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }
    free(rows);
    fclose(fp);
    return 0;
}

int compareInt(const void* elem1, const void* elem2)
{
    int number1 = *((int*)elem1);
    int number2 = *((int*)elem2);
    return number1 - number2;
}

void *sort(void * arg)
{
    qsort(((row_t*)arg)->numbers, ((row_t*)arg)->count, sizeof(int), compareInt);
}