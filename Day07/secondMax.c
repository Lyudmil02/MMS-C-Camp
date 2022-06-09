#include <stdio.h>
#include <limits.h>
#include <string.h>

int secondMax(int*, size_t, int*);

int main()
{
    int sm;
    int arr[] = {12, 34, 5, 70, 46};
    if(secondMax(arr, 5, &sm) == 1)
    {
        fprintf(stderr, "Array does not have second max number!\n");
        return 0;
    }
    printf("%d\n", secondMax(arr, 5, &sm));
    return 0;
}

int secondMax(int* arr, size_t n, int* secondMax)
{
    int maxNum = INT_MIN;
    *secondMax = INT_MIN;

    if(n == 1 || n == 0)
    {
        return 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > *secondMax && arr[i] < maxNum)
        {
            *secondMax = arr[i];
        }
    }

    if(*secondMax == INT_MIN)
    {
        return 1;
    }
    return *secondMax;
}
