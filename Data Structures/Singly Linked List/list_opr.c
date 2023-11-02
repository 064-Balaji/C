#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head, *current, *temp;

void display();

int no, data, length, choice;

void create(){
    printf("Enter the no of elements want to insert: ");
    scanf("%d", &no);
    length = no;

    for(int i=0; i<no; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d",&data);

        if(head == NULL){
            head = malloc(sizeof(struct node));
            head->data = data;
            head->next = NULL;
            current = head;
        }

        else{
            current->next = malloc(sizeof(struct node));
            current = current->next;
            current->data = data;
            current->next = NULL;
        }
    }

    printf("Current list status: \n");
    display();
}

void display(){
    temp = head;
    while (temp->data != 0)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(){
    printf("1.Insert at First   2.Insert at Middle   3.Insert at End");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the value to insert: ");
        scanf("%d", &data);

        struct node *current = (struct node *) malloc(sizeof(struct node));
        current->data = data;
        current->next = head;
        head = current;

        printf("List after Insertion: \n");
        display();
        break;
    
    case 2:
        display();
        printf("Enter the position to be inserted");
        scanf("%d", &no);

        temp = head;
        for(int i=0; i<no; i++)
        {
            temp=temp->next;
        }
        
        printf("Enter the value to be inserted: ");
        scanf("%d", &data);
        current->data = data;
        current->next = temp->next;
        temp->next = current;

        printf("List after insertion: \n");
        display();
        break;

    case 3:
        printf("Enter the value to be Inserted: ");
        scanf("%d", &data);

        temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = (struct node*) malloc(sizeof(struct node));
        temp = temp->next;
        temp->data = data;
        temp->next = NULL;

    default:
        printf("Enter the correct option");
        break;
    }
}

void delete(){
    printf("1.Deletion at First   2.Deletion at Middle   3.Deletion at End\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Deleting the element: %d", head->data);
        temp = head;
        head = head->next;
        free(temp);
        break;

    case 2:
        display();
        printf("Enter the position want to delete: ");
        scanf("%d", &no);

        temp = head;
        for(int i=0; i<no; i++)
        {
            current = temp;
            temp=temp->next;
        }
        current->next = temp->next;
        free(temp);
        break;

    case 3:
        printf("Before Deletion: \n");
        display();
        temp = head;
        while(temp->next != NULL){
            current = temp;
            temp=temp->next;
        }

        current->next=NULL;
        free(temp);
        break;
    
    default:
        printf("Choose correct option");
        break;
    }
}

int main(){
    printf("\t \t Linked List Creation... \n");
    create();
    printf("What do you want to do: \n");
    printf("1.Insertion   2.Deletion   3.Display");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insert();
        break;
    
    case 2:
        delete();
        break;

    case 3:
        display();
        break;

    default:
        printf("Choose the correct option");
        break;
    }
}