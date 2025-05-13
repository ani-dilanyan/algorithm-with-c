#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


typedef struct Node {
    char name[MAX];
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct {
    Node* front;
    Node* rear;
} Queue;


void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}


bool isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return true;
    }
    free(temp);
    return false;
}


void addCustomer(Queue* queue, const char* name) {
    if (isFull()) {
        printf("Memory allocation failed! Queue is full.\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX - 1);
    newNode->name[MAX - 1] = '\0';
    newNode->next = NULL;
    newNode->prev = queue->rear;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Customer added: %s\n", name);
}


void serveCustomer(Queue* queue) {
    if (isEmpty(queue)) {
        printf("No customers in queue.\n");
        return;
    }
    Node* temp = queue->front;
    printf("Customer served: %s\n", temp->name);
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }
    free(temp);
}

void viewCurrentCustomer(Queue* queue) {
    if (isEmpty(queue)) {
        printf("No customers in queue!\n");
    } else {
        printf("Current customer: %s\n", queue->front->name);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    addCustomer(&queue, "Ivan");
    addCustomer(&queue, "Maria");
    viewCurrentCustomer(&queue);
    serveCustomer(&queue);
    viewCurrentCustomer(&queue);
    
    return 0;
}