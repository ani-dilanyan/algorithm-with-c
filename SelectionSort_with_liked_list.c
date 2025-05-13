// Task 1
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insert_in_begining(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}


void print_list(struct Node* start) {
    struct Node *tmp = start;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}


void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


void selection_sort(struct Node* start) {
    struct Node *current, *min, *temp;
    for (current = start; current != NULL; current = current->next) {
        min = current;
        temp = current->next;
        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current) {
            swap(current, min);
        }
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* start = NULL;
    for (int i = 0; i < size; i++) {
        insert_in_begining(&start, arr[i]);
    }

    printf("Original list: ");
    print_list(start);

    selection_sort(start);

    printf("Sorted list: ");
    print_list(start);
    return 0;
}
