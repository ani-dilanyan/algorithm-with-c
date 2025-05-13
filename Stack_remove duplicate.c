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


void push(Stack *s, char ch) {
    if(isFull(s)) {
        printf("STACK FULL\n");
    } else {
        s->top++;
        s->arr[s->top] = ch;
    }
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return '\0';
    } else {
        return s->arr[s->top--];
    }
}


char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}



void stackToString(Stack *s, char result[]) {
    for (int i = 0; i <= s->top; i++) {
        result[i] = s->arr[i];
    }
    result[s->top + 1] = '\0';
}



void removeDuplicates(char str[]) {
    Stack stack;
    init(&stack);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if(str[i] != peek(&stack)){
            push(&stack, str[i]);
        }   
    }

    stackToString(&stack, str);
}



int main() {
    char input[] = "aabbccddeee";
    
    printf("Original string - %s\n", input);
    
    removeDuplicates(input);
    
    printf("Processed string -  %s\n", input);
    
    return 0;
}
