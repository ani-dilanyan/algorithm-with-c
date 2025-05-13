#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};


void printList(struct Node *last)
{
    if (last == NULL)
        return;
    struct Node *head = last->next;
    while (1)
    {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next)
            break;
    }
    printf("\n");
}


struct Node *createNode(int value)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


int main()
{
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);
    struct Node *last = first->next->next;
    last->next = first;
    printList(last);
    return 0;
}