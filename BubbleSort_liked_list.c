#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void insertB(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}


void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


void printList(struct Node* start) {
    struct Node *tmp = start;
    printf("\n");
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}


void bubbleSort(struct Node* start) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (start == NULL) {
        return;
    }

    do{
        swapped = 0;
        ptr1 = start;
            while (ptr1->next != lptr){
                if(ptr1->data > ptr1->next->data){
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1 -> next;
            }
        lptr = ptr1;
    } while (swapped);
    }




int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* start = NULL;
    for (int i = 0; i < size; i++) {
        insertB(&start, arr[i]);
    }

    printList(start);
    bubbleSort(start);
    printList(start);

    return 0;
}
