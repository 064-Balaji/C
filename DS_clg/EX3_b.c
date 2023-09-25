#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

void fun(struct node* start) {
    if (start == NULL)
        return;

    printf("%d ", start->data);

    if (start->next != NULL) {
        if (start->next->next != NULL) {
            fun(start->next->next);
        }
        printf("%d ", start->data);
    }
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int num;

    for (int i = 1; i <= 5; i++) {
        printf("Enter %d element: ", i);
        scanf("%d", &num);

        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        new_node->data = num;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    printf("Original List:\n");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");

    printf("Output of fun() function:\n");
    fun(head);

    // Free memory (optional but good practice)
    while (head != NULL) {
        struct node* next_node = head->next;
        free(head);
        head = next_node;
    }

    return 0;
}
