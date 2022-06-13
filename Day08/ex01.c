#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t my_strlen(char*);
size_t my_strnlen(char*, size_t);
char* my_strcpy(char*, const char*);
char* my_strncpy(char*, const char*, size_t);
char* my_strcat(char*, char*);
char* my_strncat(char*, char*, size_t);
int my_strcmp(const char*, const char*);
int my_strncmp(const char* str1, const char* str2, size_t n);

int main()
{
    char str1[20] = "aaa";
    char str2[20] = "aar";
    // printf("%ld %ld\n", strlen(str1), strnlen(str1, 13));
    // printf("%ld %ld\n", my_strlen(str1), my_strnlen(str1, 13));

    // printf("String 2 is: %s\n", str2);
    // printf("String 1 is: %s\n", str1);
    // printf("String 2 is: %s\n", my_strncpy(str2, str1, 13));

    // printf("String 1 is: %s\n", str1);
    // printf("String 2 is: %s\n", str2);
    // printf("String 1 + string 2 is: %s\n", my_strcat(str1, str2));

    // printf("String 1 is: %s\n", str1);
    // printf("String 2 is: %s\n", str2);
    // printf("String 1 + string 2 is: %s\n", my_strncat(str1, str2, 2));

    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", my_strcmp(str1, str2));

    printf("%d\n", strncmp(str1, str2, 2));
    printf("%d\n", my_strncmp(str1, str2, 2));

    return 0;
}

size_t my_strlen(char* str)
{
    size_t i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

size_t my_strnlen(char* str, size_t n)
{
    size_t count = 0;
    for(int i = 0; i < n; i++)
    {
        count++;
    }
    return count;
}

char* my_strcpy(char* dest, const char* src)
{
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* my_strncpy(char* dest, const char* src, size_t n)
{
    int i = 0;
    while(src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* my_strcat(char* dest, char* src)
{
    size_t i = 0;
    size_t currIndex = my_strlen(dest);
    for(; i < my_strlen(src); i++)
    {
        dest[currIndex + i] = src[i];
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}

char* my_strncat(char* dest, char* src, size_t n)
{
    size_t i = 0;
    size_t currIndex = my_strlen(dest);
    size_t count = 0;
    for(; i < my_strlen(src) && n > count; i++)
    {
        dest[currIndex + i] = src[i];
        count++;
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}

int my_strcmp(const char* str1, const char* str2)
{
    int i = 0, flag = 0;
    while(flag == 0)
    {
        if(*(str1 + i) > *(str2 + i))
        {
            flag = abs(str1[i] - str2[i]);
            break;
        }
        else if(*(str1 + i) < *(str2 + i))
        {
            flag = (-1) * abs(str2[i] - str1[i]);
            break;
        }
        if(*(str1 + i) == '\0')
        {
            break;
        }
        i++;
    }
    return flag;
}

int my_strncmp(const char* str1, const char* str2, size_t n)
{
    int i = 0, flag = 0;
    while(flag == 0 && i < n)
    {
        if(*(str1 + i) > *(str2 + i))
        {
            flag = abs(str1[i] - str2[i]);
            break;
        }
        else if(*(str1 + i) < *(str2 + i))
        {
            flag = (-1) * abs(str2[i] - str1[i]);
            break;
        }
        if(*(str1 + i) == '\0')
        {
            break;
        }
        i++;
    }
    return flag;
}