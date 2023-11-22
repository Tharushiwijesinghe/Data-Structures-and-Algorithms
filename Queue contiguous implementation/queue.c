#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define MAXQUEUE 10
typedef int QueueElement;

typedef struct queue
{
    QueueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
} Queue;

void CreateQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q)
{
    return (q->rear < q->front) ? TRUE : FALSE;
}

int isQueueFull(Queue *q)
{
    return (q->rear == MAXQUEUE - 1) ? TRUE : FALSE;
}

void Append(QueueElement x, Queue *q )
{
    if (isQueueFull(q))
    {
        printf("Queue Full\n");
        exit(1);
    }
    else
    {
        q->items[++(q->rear)] = x;
        q->count++;
    }
}

void Serve(Queue *q, QueueElement *x)
{
    if (isQueueEmpty(q))

       {
         printf("Queue is Empty, underflow\n");
         exit(1);
       }

    else
        {
        *x = q->items[(q->front)++];
        q->count--;
        printf("Served from Queue: %d\n", *x);
        printf("\n");
        }
}

int main()
{
    Queue Q;
    QueueElement queueItem;

    CreateQueue(&Q);

    Append(50, &Q);
    Append(100, &Q);
    Append(125, &Q);
    Serve(&Q,&queueItem);
    Append(15, &Q);

    return 0;
}


