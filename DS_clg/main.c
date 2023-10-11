#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to add a new node to the end of the doubly linked list
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
    } else {
        struct Node* last = *head_ref;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to delete the first node and append it to the end
void deleteFirstAndAppend(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        // No or only one element in the list, nothing to do
        return;
    }

    struct Node* first = *head_ref;
    struct Node* second = first->next;

    // Update the head to point to the second node
    *head_ref = second;

    // Update the second node's prev pointer to NULL
    second->prev = NULL;

    // Find the last node in the list
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Append the first node to the end
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Add elements to the doubly linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original List: ");
    printList(head);

    // Delete the first element and append it to the end
    deleteFirstAndAppend(&head);

    printf("Modified List: ");
    printList(head);

    // Free memory (optional but good practice)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
