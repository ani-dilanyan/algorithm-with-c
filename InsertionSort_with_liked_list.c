// Task 2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insert_in_begining(struct Node** head_ref, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}


void print_list(struct Node* start) {
    while (start) {
        printf("%d ", start->data);
        start = start->next;
    }
}


void insertion_sort(struct Node** head) {
    struct Node* sorted = NULL;
    while (*head != NULL) {
        struct Node* current = *head;
        *head = (*head)->next;
        
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
    }
    *head = sorted;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    struct Node* head = NULL;
    for (int i = 0; i < 9; i++) {
        insert_in_begining(&head, arr[i]);
    }

    printf("Original list: ");
    print_list(head);
    printf("\n");

    printf("Sorted list: ");
    insertion_sort(&head);
    print_list(head);

    return 0;
}