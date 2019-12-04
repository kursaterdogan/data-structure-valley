#include <stdio.h>
#include <stdlib.h>

// dequeue front | enqueue rear->next = NULL | cnt

#define QUEUESIZE 10

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct 
{
    struct node *front;
    struct node *rear;
    int cnt;
} queue;

void initialize(queue *q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
}

void enqueue(queue *q, int key)
{
    if (q->cnt == QUEUESIZE)
        printf("Queue is full\n");
    else
    {
        struct node *temp = (node *)malloc(sizeof(node));
        temp->data = key;
        temp->next = NULL;
        if (q->cnt == 0)
            q->front = q->rear = temp;
        else
        {
            q->rear->next = temp;
            q->rear = temp;
        }
        q->cnt++;
    }
}

int dequeue(queue *q)
{
    if (q->cnt == 0)
    {
        printf("Queue is empty\n");
        return -99;
    }
    else
    {
        struct node *temp = q->front;
        int x = temp->data;
        q->front = q->front->next; // temp -> next
        free(temp);
        q->cnt--;
        if (q->cnt == 0)
        {
            q->rear = NULL;
        }
        return x;
    }
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    initialize(q);
    enqueue(q, 1);
    enqueue(q, 2);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    enqueue(q, 1);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
}