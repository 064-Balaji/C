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
        break;
    
    case 2:
        display();
        printf("Enter the position to be inserted");
        scanf("%d", &no);

        


    default:
        break;
    }
}

int main(){
    create();
}