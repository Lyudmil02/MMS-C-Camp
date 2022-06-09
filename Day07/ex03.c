#include <stdio.h>

void arrayEvaluate(int*, size_t, int(*f)(int*,int));
int sum(int* arr, int n);

int main()
{
    
    int arr[] = {1, 2, 13};
    arrayEvaluate(arr, 3, sum);

    return 0;
}


int sum(int* arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int))
{
    printf("Value: %d\n", f(arr, n));
}