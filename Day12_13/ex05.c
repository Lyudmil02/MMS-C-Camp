#include <stdio.h>

#define MAX_SIZE 10

typedef struct
{
    int arr[MAX_SIZE];
    int top;
    int bottom;
}queue_t;

int isEmpty(queue_t*);
int isFull(queue_t*);
void push(queue_t*, int);
int pop(queue_t*);

int main()
{
    queue_t q;
    q.bottom = 0;
    q.top = 0;
    for(int i = 1; i < 16; i++)
    {
        if(isFull(&q))
        {
            push(&q, i);
        }
    }
    for(int i = 0; i < 15; i++)
    {
        if(isEmpty(&q))
        {
            printf("%d ", pop(&q));
        }
    }
    putchar('\n');
    return 0;
}

int pop(queue_t* q)
{
    int value = q->arr[q->top];
    q->top++;
    return value;
}

void push(queue_t* q, int value)
{
    q->arr[q->bottom] = value;
    q->bottom++;
}

int isEmpty(queue_t* q)
{
    if(q->bottom == q->top)
    {
        return 0;
    }
    return 1;
}

int isFull(queue_t* q)
{
    if(q->bottom >= MAX_SIZE)
    {
        return 0;
    }
    return 1;
}