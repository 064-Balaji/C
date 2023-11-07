#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_odd(struct node* head) {
    int position = 1;  // Start at the first position (1-based index)

    struct node* current = head;

    while (current != NULL) {
        if (position % 2 == 1) {
            printf("%d -> ", current->data);
        }
        position++;
        current = current->next;
    }

    printf("Null\n");
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
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");

    printf("Elements at odd positions:\n");
    print_odd(head);

    while (head != NULL) {
        struct node* next_node = head->next;
        free(head);
        head = next_node;
    }

    return 0;
}
