#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef int stackEntry;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct {
    int top;
    stackEntry entry[N];
}Stack;

void createStack(Stack* s){
    s -> top = -1;
    printf("Stack created....");
}

Boolean isEmpty(const Stack* s){
    return (s -> top == -1);
}

Boolean isFull(const Stack* s){
    return (s -> top == N-1);
}

void push(stackEntry item, Stack* s){
    if(!isFull(s)){
        s -> top++;
        s -> entry[s -> top] = item;
    }else {
        printf("Stack is Full");
    }
}

void pop(Stack* s){
    if(!isEmpty(s)){
        s -> top--;
    }else {
        printf("Stack is Empty");
        exit(1);
    }
}

stackEntry peek(Stack* s){
    return (s ->entry[s -> top]);
}

void main(){

    Stack myStack;
    stackEntry pushedValue, x;

    int choice;


    // createStack(&myStack);

    // for(int i = 0; i < N; i++){
    //     printf("\n\nEnter values to push to stack: ");
    //     scanf("%d",&pushedValue);
    //     push(pushedValue, &myStack);
    // }

    // pushedValue = 32;

    // push(pushedValue, &myStack);

    // stackEntry x = peek(&myStack);
    // printf("\nPeeked value is %d", x);

    // pop(&myStack);



    do {


        printf("\n\nOperations on stack......\n");
        printf("Select \n\t1). Create stack\n\t2). Push element to the stack\n\t3). Pop element from the stack\n\t4). Peek the top element\n\t5). Exit\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                createStack(&myStack);
                break;
            case 2:
                printf("\nEnter value to push to stack: ");
                scanf("%d",&pushedValue);
                push(pushedValue, &myStack);
                break;
            case 3:
                pop(&myStack);
                printf("\n\nTop element is popped...\n");
                break;
            case 4:
                x = peek(&myStack);
                printf("\nPeeked value is %d\n", x);
                break;
            case 5:
                printf("Exit the program");
                break;
            default:
                printf("\nInvalid entry\n");

        }
    }while (choice != 5);

}
