#include <stdio.h>

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int result = (!num1 && num2) || (num1 && !num2);
    printf("%d\n", result);
}