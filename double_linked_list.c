#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void forwardTraversal(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void backwardTraversal(struct Node *tail)
{
    struct Node *curr = tail;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}


struct Node *createNode(int data)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


int main()
{
    struct Node *head = createNode(1);
    struct Node *second = createNode(2);
    struct Node *third = createNode(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    printf("Forward Traversal:\n");
    forwardTraversal(head);
    printf("Backward Traversal:\n");
    backwardTraversal(third);
    return 0;
}