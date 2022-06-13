#include <stdio.h>

void map(int*, size_t, int (*func)(int));
int currNum_5(int);


int main()
{
    int arr[] = {1, 3, 5, 2, 8};
    map(arr, 5, currNum_5);
    
    return 0;
}

void map(int* array, size_t n, int (*func)(int))
{
    int num;
    for(int i = 0; i < n; i++)
    {
        printf("Number[%d]: %d\n", i, currNum_5(array[i]));
    }
}

int currNum_5(int num)
{
    return num + 5;
}