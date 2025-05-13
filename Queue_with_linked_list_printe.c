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
} PrinterQueue;


void initQueue(PrinterQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


bool isEmpty(PrinterQueue* queue) {
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


void add(PrinterQueue* queue, const char* name) {
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
    printf("Add document: %s\n", name);
}


void processNext(PrinterQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = queue->front;
    printf("Print document: %s\n", temp->name);
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }
    free(temp);
}


void viewStatus(PrinterQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current queue: ");
    Node* temp = queue->front;
    while (temp) {
        printf("%s, ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    PrinterQueue queue;
    initQueue(&queue);

    add(&queue, "report.pdf");
    add(&queue, "thesis.docx");
    viewStatus(&queue);
    processNext(&queue);
    viewStatus(&queue);
    processNext(&queue);
    viewStatus(&queue);
    
    return 0;
}
