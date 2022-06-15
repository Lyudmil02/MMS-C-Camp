#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(void)
{
    char number[501];
    fgets(number, 500, stdin);
    number[strlen(number) - 1] = '\0';

    for(int i = 0; i < strlen(number); i++)
    {
        if(number[i] < '0' || number[i] > '9')
        {
            fprintf(stderr, "%s Invalid input\n", number);
            return EXIT_FAILURE;
        }
        if(i & 1)
        {
            switch(number[i])
            {
                case '0':
                    number[i] = '!';
                    break;
                case '1':
                    number[i] = '#';
                    break;
                case '2':
                    number[i] = '/';
                    break;
                case '3':
                    number[i] = '~';
                    break;
                case '4':
                    number[i] = '=';
                    break;  
                case '5':
                    number[i] = '`';
                    break;
                case '6':
                    number[i] = '\\';
                    break;
                case '7':
                    number[i] = '>';
                    break;
                case '8':
                    number[i] = '.';
                    break;
                case '9':
                    number[i] = ',';
                    break;  
            }
        }
        else
        {
            number[i] += 'A' - '0';
        }
    }
    printf("%s\n", number);
    return EXIT_SUCCESS;
}