#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int head, tail;
    int items[MAX];
} Queue;

void initialize(Queue *queue) {
    queue->head = -1;
    queue->tail = -1;
}

bool isEmpty(Queue *queue) {
    return queue->head == -1;
}

bool isFull(Queue *queue) {
    return queue->tail == MAX - 1;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->head = 0;
    }
    queue->tail++;
    queue->items[queue->tail] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", queue->items[queue->head]);
    if (queue->head == queue->tail) {
        initialize(queue);
    } else {
        queue->head++;
    }
}


int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}
