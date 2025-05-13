#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 32 

typedef struct {
    char arr[MAX];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


bool isEmpty(Stack *s) {
    return s->top == -1;
}


bool isFull(Stack *s) {
    return s->top == MAX - 1;
}


void push(Stack *s, char newitem) { 
    if (isFull(s)) {
        printf("STACK FULL\n");
    } else {
        s->arr[++s->top] = newitem;
    }
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return '\0';
    }
    return s->arr[s->top--];
}


void stackToString(Stack *s, char result[]) {
    for (int i = 0; i <= s->top; i++) {
        result[i] = s->arr[i];
    }
    result[s->top + 1] = '\0';
}


void decimalToBinary(int num, char result[]) {
    Stack stack;
    init(&stack);

    if (num == 0) {
        strcpy(result, "0");
        return;
    }

    while (num > 0) {
        push(&stack, (num % 2) + '0');
        num /= 2;
    }

    stackToString(&stack, result);
}


int main() {
    int number = 25;
    char binary[MAX];

    decimalToBinary(number, binary);

    printf("Decimal: %d\nBinary: %s\n", number, binary);

    return 0;
}
