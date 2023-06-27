#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to insert an element into the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
    printf("Enqueued %d into the queue.\n", element);
}

// Function to display all elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue:\n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d\n", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

int main() {
    struct Queue queue;
    int element;

    // Initialize the queue
    initialize(&queue);

    // Read elements to be enqueued until user enters -1
    printf("Enter elements to be enqueued (enter -1 to stop):\n");
    scanf("%d", &element);

    while (element != -1) {
        enqueue(&queue, element);
        scanf("%d", &element);
    }

    // Display all elements in the queue
    displayQueue(&queue);

    return 0;
}
