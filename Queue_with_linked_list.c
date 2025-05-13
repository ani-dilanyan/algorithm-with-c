#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int value;
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


void enqueue(Queue* queue, int value) {
    if (isFull()) {
        printf("Memory allocation failed! Queue is full.\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = queue->rear;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Enqueued: %d\n", value);
}


void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = queue->front;
    printf("Dequeued: %d\n", temp->value);
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }
    free(temp);
}


void peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue->front->value);
    }
}




int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    peek(&queue);
    dequeue(&queue);
    peek(&queue);
    
    return 0;
}
