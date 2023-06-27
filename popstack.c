#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = element;
    printf("Pushed %d onto the stack.\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    }

    int poppedElement = stack->data[stack->top];
    stack->top--;
    return poppedElement;
}

// Function to display all elements in the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main() {
    struct Stack stack;
    int element;

    // Initialize the stack
    initialize(&stack);

    // Read elements to be pushed until user enters -1
    printf("Enter elements to be pushed (enter -1 to stop):\n");
    scanf("%d", &element);

    while (element != -1) {
        push(&stack, element);
        scanf("%d", &element);
    }

    // Pop an element from the stack
    printf("Enter an element to pop from the stack:\n");
    scanf("%d", &element);
    int poppedElement = pop(&stack);
    if (poppedElement != -1) {
        printf("Popped %d from the stack.\n", poppedElement);
    }

    // Display all elements in the stack
    displayStack(&stack);

    return 0;
}
