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


void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = queue->front;
    printf("Queue elements: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


bool isPalindrome(Queue* queue) {
    if (isEmpty(queue)) {
        return true;
    }

    Node* left = queue->front;
    Node* right = queue->rear;

    while (left != right && left->prev != right) {
        if (left->value != right->value) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}



int main() {
    Queue queue;
    initQueue(&queue);


    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 2);
    enqueue(&queue, 1);

    printQueue(&queue);
    if (isPalindrome(&queue)) {
        printf("Result: The queue is a palindrome.\n");
    } else {
        printf("Result: The queue is NOT a palindrome.\n");
    }



    Queue queue2;
    initQueue(&queue2);

    enqueue(&queue2, 1);
    enqueue(&queue2, 2);
    enqueue(&queue2, 3);
    enqueue(&queue2, 4);
    enqueue(&queue2, 5);

    printQueue(&queue2);
    if (isPalindrome(&queue2)) {
        printf("Result: The queue is a palindrome.\n");
    } else {
        printf("Result: The queue is NOT a palindrome.\n");
    }

    return 0;
}
