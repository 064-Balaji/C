#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head, *current, *temp;

void display();

int no, data, length;

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

int main(){
    create();
}