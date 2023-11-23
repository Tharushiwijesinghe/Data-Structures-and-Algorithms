#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0

typedef char DqueueElement;

typedef struct Dqueue
{
    DqueueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
} Dqueue;

void createDqueue(Dqueue *dq)
{
    dq->count = 0;
    dq->front = 0;
    dq->rear = -1;
    printf("\nDequeue is created successfully.\n");

}

int IsDqueueEmpty(Dqueue *dq)
{
    return (dq->count == 0) ? TRUE : FALSE;
}

int IsDqueueFull(Dqueue *dq)
{
    return (dq->count == MAXQUEUE) ? TRUE : FALSE;
}


// AppendRear
void AppendRear(Dqueue *dq, DqueueElement x)
{
    if (IsDqueueFull(dq))
    {
        printf("Dqueue Full\n");
        exit(1);
    }
    else
    {
        dq->items[++(dq->rear)] = x;
        dq->count++;
    }
}

// AppendFront

void AppendFront(Dqueue *dq, DqueueElement x)
{
    if (IsDqueueFull(dq))
    {
        printf("Queue Full\n");
        exit(1);
    }
    else
    {
        if (IsDqueueEmpty(dq))
        {
            dq->items[dq->front] = x;
            dq->rear++;
        }
        else
        {
            if (dq->front == 0)
            {
                for (int i = dq->rear; i >= dq->front; i--)
                    dq->items[i + 1] = dq->items[i];
                dq->rear++;
                dq->items[dq->front] = x;
            }
            else
            {
                dq->items[--(dq->front)] = x;
            }
        }
        dq->count++;
    }
}

int main()
{
    Dqueue dq;
    DqueueElement ch;

    createDqueue(&dq);

    AppendRear(&dq, 'B');
    AppendRear(&dq, 'G');
    AppendRear(&dq, 'L');
    AppendRear(&dq, 'J');
    AppendRear(&dq, 'M');
    AppendRear(&dq, 'P');

    printf("\n");
    AppendFront(&dq, 'Z');
    AppendFront(&dq, 'D');

    printf("Items of the dequeue: ");

    for (int i = dq.front; i <= dq.rear; i++)
    {
        printf("%c ", dq.items[i]);
    }

    return 0;
}

