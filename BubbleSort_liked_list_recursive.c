#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swapNodes(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void RecursiveBubbleSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 0;

    while (current->next != NULL) {
        if (current->data > current->next->data) {
            swapNodes(current, current->next);
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        return;
    }


    RecursiveBubbleSort(head);
}

void insertAtBegin(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int data[] = {1, 3, 5, 7, 6, 2};
    int size = sizeof(data) / sizeof(data[0]);

    struct Node* start = NULL;
    for (int i = 0; i < size; i++) {
        insertAtBegin(&start, data[i]);
    }

    printf("Original linked list: ");
    printList(start);

    RecursiveBubbleSort(start);

    printf("Sorted linked list: ");
    printList(start);

    return 0;
}
