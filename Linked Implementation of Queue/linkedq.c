#include <stdio.h>

typedef int QueueElement;

typedef struct node
{
    QueueElement entry;
    struct node *next;
}QueueNode;

typedef enum {TRUE,FALSE}Boolean;

typedef struct
{
    QueueNode *rear;
    QueueNode *front;
    int count;
    Boolean full;
}Queue;

void CreateQueue(Queue *q)
{
    q->count=0;
    q->full=FALSE;
    q->rear=q->front=NULL;
}

Boolean isQueueEmpty(const Queue *q)
{
    return(q->rear==NULL&&q->front==NULL);
}

Boolean isQueueFull(const Queue *q)
{
    return(q->full);
}

void Append(QueueElement x, Queue *q)
{
    QueueNode *np;
    np = (QueueNode*)malloc(sizeof(QueueNode));

    if(np == NULL)
    {
        printf("Not enough memory");
        q->full = TRUE;
    }
    else
    {
        np->entry = x;
        np->next = NULL;

        if(isQueueEmpty(q))
        {
            q->rear = q->front= np;
            q->rear = np;
        }

        q->count++;
    }
}

void Serve(QueueElement *x, Queue *q)
{
    QueueNode *np;
    if(isQueueEmpty(q))
    {
        printf("Queue is empty");
        q->full = FALSE;
    }
    else
    {
        *x = q->front->entry;
        np=q->front;
        q->front = q->front->next;
        q->count--;

        if(q->front==NULL)
            q->rear=NULL;

                free(np);
    }
}

int main()
{
    Queue myQueue;
    QueueElement servedItem;

    CreateQueue(&myQueue);

    Append(1, &myQueue);
    Append(2, &myQueue);
    Append(3, &myQueue);

    Serve(&servedItem, &myQueue);
    printf("Served item: %d\n", servedItem);

    return 0;
}
