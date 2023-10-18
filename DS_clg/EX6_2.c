#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return (stack->top == -1);
}

int is_full(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack* stack, int item) {
    if (!is_full(stack)) {
        stack->arr[++stack->top] = item;
    }
}

int pop(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

void init_queue(struct Queue* queue) {
    initialize(&queue->stack1);
    initialize(&queue->stack2);
}

void enqueue(struct Queue* queue, int item) {
    push(&queue->stack1, item);
}

int dequeue(struct Queue* queue) {
    if (is_empty(&queue->stack2)) {
        if (is_empty(&queue->stack1)) {
            return -1;
        }
        while (!is_empty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

void print_queue(struct Queue* queue) {
    printf("Queue contents: ");
    for (int i = 0; i <= queue->stack1.top; i++) {
        printf("%d ", queue->stack1.arr[i]);
    }
    for (int i = 0; i <= queue->stack2.top; i++) {
        printf("%d ", queue->stack2.arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    init_queue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    print_queue(&queue);  // Before dequeue

    int dequeued_item = dequeue(&queue);
    printf("Dequeued item: %d\n", dequeued_item);

    print_queue(&queue);  // After dequeue

    return 0;
}
