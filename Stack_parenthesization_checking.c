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


bool isPair(char start, char end) {
    return ((start == '(' && end == ')') ||
           (start == '[' && end == ']') ||
           (start == '{' && end == '}'));
}


bool isBalanced(const char *expr) {
    Stack s;
    init(&s);
    int i = 0; 
    while (expr[i] != '\0') {
        char current_char = expr[i];
        
        if (current_char == '(' || current_char == '[' || current_char == '{') {
            push(&s, current_char);
        } else if (current_char == ')' || current_char == ']' || current_char == '}') {
            if (isEmpty(&s) || !isPair(pop(&s), current_char)) {
                return false;
            }
        }
        i++;
    }
    return isEmpty(&s);
}



int main() {
    const char *expressions[] = {
        "(([]{}))",
        "({[]})",
        "()()]{}"
    };
    
    for (int i = 0; i < 3; i++) {
        if (isBalanced(expressions[i])) {
            printf("(%d) %s good\n", i+1, expressions[i]);
        } else {
            printf("(%d) %s bad\n", i+1, expressions[i]);
        }
    }
    return 0;
}
