#include <stdio.h>

int binarySearch(int*, size_t, int);

int main()
{
    int arr[5] = {1, 3, 4, 5, 7};
    int key = 2;
    if(binarySearch(arr, 5, key) == -1)
    {
        fprintf(stderr, "Invalid key!\n");
        return -1;
    }
    printf("Index on %d is: %d\n", key, binarySearch(arr, 5, key));
    return 0;
}

int binarySearch(int* array, size_t n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(array[i] == key)
        {
            return i;
        }
    }
    return -1;
}