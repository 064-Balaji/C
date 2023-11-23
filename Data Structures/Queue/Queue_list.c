//This program can have a basic implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front, *rear, *temp;

int length,data;
void create();
void display();


int main(){
    printf("\n \nQueue using Linked List \n");
    create();
    display();
}


void create(){
    printf("Enter the length of the queue: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        printf("Enter %d data: ",i+1);
        scanf("%d", &data);

        if(front == NULL){
            struct node *temp = malloc(sizeof(struct node));
            temp->data = data;
            temp->next =NULL;
            front = rear =temp;
        }
        else{
            rear->next = malloc(sizeof(struct node));
            rear = rear->next;
            rear->data = data;
            rear->next = NULL;
        }
    }
    printf("\n");
}

void display(){
    temp = front;
    for (int i = 0; i < length; i++)
    {
        printf("%d-> ", temp->data);
        temp= temp->next;
    }
    
}

void insert(){
    printf("Enter the data to insert:");
    scanf("%d", &data);
    rear->next = malloc((sizeof(struct node)));
    rear= rear->next;
    rear->data = data;
    rear->next = NULL;
}

void delete(){
    temp = front;
    front= front->next;
    free(temp);
}