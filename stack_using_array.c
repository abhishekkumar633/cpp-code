#include <stdio.h>
#include <stdbool.h>
#define MAX 100 // Maximum size of the stack

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;  // Return -1 to indicate an error
    } else {
        return stack->arr[stack->top--];
    }
}

// Peek the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;  // Return -1 to indicate an error
    } else {
        return stack->arr[stack->top];
    }
}

// Main function to demonstrate the stack
int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));  // Attempt to pop from an empty stack

    return 0;
}
