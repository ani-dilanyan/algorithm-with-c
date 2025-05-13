#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


struct Node* FindMiddle(struct Node* head) {
    if (head==NULL) {
        return head;
    }

    struct Node* mid = head;
    struct Node* double_steps = head->next;
    
    while (double_steps && double_steps->next) {
        mid = mid->next;
        double_steps = double_steps->next->next;
    }
    return mid;
}


struct Node* merge(struct Node* left, struct Node* right) {
    if (left==NULL) {
        return right;
    }
    
    if (right==NULL) {
        return left;
    }
    
    struct Node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}


struct Node* mergeSort(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    
    struct Node* middle = FindMiddle(head);
    struct Node* nextOfMiddle = middle->next;
    middle->next = NULL;
    
    struct Node* left_list = mergeSort(head);
    struct Node* right_list = mergeSort(nextOfMiddle);
    
    return merge(left_list, right_list);
}


int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 9);

    
    printList(head);
    head = mergeSort(head);
    printList(head);
    
    return 0;
}