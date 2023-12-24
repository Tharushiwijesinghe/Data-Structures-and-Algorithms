#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent the ArrayList
struct ArrayList {
    int list[MAX_SIZE];
    int count;
};

// Function to create an empty list
void createList(struct ArrayList *L) {
    L->count = 0;
}

// Function to insert an element
void insertList(struct ArrayList *L, int element, int position) {
    if (L->count < MAX_SIZE && position >= 0 && position <= L->count) {
        // Shift elements to make space for the new element
        for (int i = L->count; i > position; i--) {
            L->list[i] = L->list[i - 1];
        }

        // Insert the new element
        L->list[position] = element;
        L->count++;
    } else {
        printf("list is full.\n");
    }
}

// Function to replace an element
void replaceList(struct ArrayList *L, int element, int position) {
    if (position >= 0 && position < L->count) {
        L->list[position] = element;
    } else {
        printf("Invalid position.\n");
    }
}

// Function to delete an element
void deleteList(struct ArrayList *L, int position) {
    if (position >= 0 && position < L->count) {
        // Shift elements to remove the specified element
        for (int i = position; i < L->count - 1; i++) {
            L->list[i] = L->list[i + 1];
        }

        L->count--;
    } else {
        printf("Invalid position.\n");
    }
}

// Function to print the final list and the remaining count
void printList(struct ArrayList *L) {
    printf("Final List L: ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->list[i]);
    }
    printf("\nRemaining count: %d\n", L->count);
}

int main() {
    // Create an empty list
    struct ArrayList L;
    createList(&L);

    // Insert elements
    insertList(&L, 100, 0);
    insertList(&L, 34, 1);
    insertList(&L, 55, 2);
    insertList(&L, 10, 3);

    // Replace an element
    replaceList(&L, 200, 3);

    // Delete elements
    deleteList(&L, 2);  // Delete 55
    deleteList(&L, 1);  // Delete 34

    // Print the final list and remaining count
    printList(&L);

    return 0;
}

