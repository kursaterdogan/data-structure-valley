#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 81

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    int cnt;
    node *top;
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
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int key)
{
    if (stk->cnt == STACKSIZE)
        printf("Stack is full\n");
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = key;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(stack *stk)
{
    if (stk->cnt == 0)
    {
        printf("Stack is empty\n");
        return -101;
    }
    else
    {
        int x = stk->top->data;
        node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt--;
        return x;
    }
}