#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 4

// 0 | 1 | 2 | 3 circle

typedef struct
{
    int data[QUEUESIZE];
    int front;
    int rear;
    int cnt;

} queue;

void initialize(queue *q)
{
    q->rear = -1;
    q->front = 0;
    q->cnt = 0;
}

void enqueue(queue *q, int key)
{
    if (q->cnt == QUEUESIZE)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        if (q->rear == QUEUESIZE)
            q->rear = 0;
        q->data[q->rear] = key;
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
        int x = q->data[q->front];
        q->front++;
        if (q->front == QUEUESIZE)
            q->front = 0;
        q->cnt--;
        return x;
    }
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    initialize(q);
    enqueue(q,0);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    printf("%d\n",dequeue(q));
    enqueue(q,5);
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
}