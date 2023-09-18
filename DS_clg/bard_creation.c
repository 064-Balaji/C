#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

void pushh(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node->value = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

int mai()
{
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }

    printf("NULL");
    return 0;
}

