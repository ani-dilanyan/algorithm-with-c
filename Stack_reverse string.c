#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


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


void push(Stack *s, char c) {
    if(isFull(s)) {
        printf("STACK FULL\n");
    } else {
        s->top++;
        s->arr[s->top] = c;
    }
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return '\0';
    } else {
        s->top--;
        return s->arr[s->top];
    }
}


void reverseString(char str[]) {
    Stack stack;
    init(&stack);


    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }


    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}


int main() {
    char str[] = "hello";
    
    printf("Original: %s\n", str);
    reverseString(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}