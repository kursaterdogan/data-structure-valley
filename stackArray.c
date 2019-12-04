#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 13

typedef struct
{
    int data[STACKSIZE];
    int top;
} stack;

void reset(stack *stk);
void push(stack *stk, int key);
int pop(stack *stk);

int main()
{
    stack *stk = (stack *)malloc(sizeof(stack));
    reset(stk);

    int i;

    for (i = 0; i <= STACKSIZE; i++)
    {
        push(stk, i);
    }

    for (i = 0; i <= STACKSIZE; i++)
    {
        printf("%d\n", pop(stk));
    }
    return 0;
}

void reset(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, int key)
{
    if (stk->top == STACKSIZE - 1)
        printf("Stack is full\n");
    else
        stk->data[++stk->top] = key;
}

int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty\n");
        return -101;
    }
    else
        return stk->data[stk->top--];
}
