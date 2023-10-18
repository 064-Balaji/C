#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
void insertNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to group odd nodes together followed by even nodes
struct Node* groupOddEven(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* oddHead = NULL;
    struct Node* evenHead = NULL;
    struct Node* oddTail = NULL;
    struct Node* evenTail = NULL;

    struct Node* current = head;
    int count = 1;

    while (current != NULL) {
        if (count % 2 == 1) {
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        } else {
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        }

        current = current->next;
        count++;
    }

    if (evenTail) {
        evenTail->next = NULL;
    }

    if (oddHead == NULL) {
        return evenHead;
    }

    oddTail->next = evenHead;
    return oddHead;
}

// Function to print a linked list
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

    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);

    printf("Original Linked List:\n");
    printList(head);

    head = groupOddEven(head);

    printf("Modified Linked List (odd nodes grouped together followed by even nodes):\n");
    printList(head);

    return 0;
}
