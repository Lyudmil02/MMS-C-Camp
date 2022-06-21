#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

void print(node_t*, int);

int main()
{
    int n;
    scanf("%d", &n);
    node_t* head = malloc(sizeof(node_t) * n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &head[i].data);
    }

    print(head, n);
    return 0;
}

void print(node_t* cll, int n)
{

    for(int i = 0; i < n; i++)
    {
        printf("%d ", cll[i].data);
    }
    putchar('\n');
}