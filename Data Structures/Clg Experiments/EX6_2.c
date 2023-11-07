#include <stdio.h>
#include <stdlib.h>

// Structure for a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if a stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an element onto a stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from a stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Structure for a queue
struct Queue {
    struct Stack* stack1; // For enqueue (push)
    struct Stack* stack2; // For dequeue (pop)
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int item) {
    push(queue->stack1, item);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue(100);
    int choice, item;

    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}