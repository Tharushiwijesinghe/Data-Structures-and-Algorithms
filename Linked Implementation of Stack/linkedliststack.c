#include <stdio.h>
#include <stdlib.h>

typedef int StackEntry;

typedef struct node
{
      StackEntry entry;
      struct node *next;
}Node;

typedef enum {TRUE,FALSE} Boolean;

typedef struct
{
    int no_element;
    Boolean full;
    Node *top;
}Stack;

//create stack
void CreateStack(Stack *s)
{
    s->top = NULL;
    s->no_element = 0;
    s->full = FALSE;
}

//isStackEmpty
Boolean isStackEmpty(const Stack *s)
{
    return(s->top == NULL);
}

//isStackFull
Boolean isStackFull(const Stack *s)
{
    return(s->full);
}

//push
void push (StackEntry item, Stack *s)
{
    Node *np;
    np = (Node*)malloc(sizeof(Node));

    if(np==NULL)
    {
        printf("Not enough memory");
        s->full = TRUE;
    }

    else
    {
        np-> entry = item;
        np->next = s->top;
        s->top = np;
        s->no_element++;
    }
}

//pop
void pop(StackEntry *item, Stack *s)
{
    Node *np;
    *item = s->top->entry;
    np = s->top;
    s-> top = s->top->next;
    s->no_element--;
    free(np);
}

void DestroyStack(Stack *s)
{
    free(s);
}

int main() {
    Stack myStack;
    CreateStack(&myStack);

    push(1, &myStack);
    push(2, &myStack);
    push(3, &myStack);
    push(13, &myStack);
    push(43, &myStack);

    int poppedItem;
    pop(&poppedItem, &myStack);
    printf("Popped item: %d\n", poppedItem);

    DestroyStack(&myStack);

    return 0;
}
