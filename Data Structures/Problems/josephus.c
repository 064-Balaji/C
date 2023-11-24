/*
24.Write a Program to implement Josephus Problem using list implementation of queue.
*/

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

int createqueue(struct queue **front,struct queue **rear)
{
    printf("\n\n*******Creating a Circular Queue*******");
    int num,n;
    printf("\n\nEnter no. of elements in the queue: ");
    scanf("%d",&n);
    printf("\nEnter the data: ");
    scanf("%d",&num);
    *front=malloc(sizeof(struct queue));
    (*front)->data=num;
    (*front)->next=NULL;
    *rear=*front;
    for(int i=1;i<n-1;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&num);
        (*rear)->next=malloc(sizeof(struct queue));
        *rear=(*rear)->next;
        (*rear)->data=num;
    }
    printf("Enter the data: ");
    scanf("%d",&num);
    (*rear)->next=malloc(sizeof(struct queue));
    *rear=(*rear)->next;
    (*rear)->data=num;
    (*rear)->next=*front;
    return num;
}

void Josephus(struct queue **front,struct queue **rear,int k,int *num)
{
    struct queue *temp;
    while(*front!=*rear)
    {
        for(int i=1;i<k;i++)
        {
            temp=*front;
            *front=(*front)->next;
            (*rear)->next=temp;
            *rear=(*rear)->next;
            (*rear)->next=*front;
        }
        temp=*front;
        *front=(*front)->next;
        (*rear)->next=*front;
        free(temp);
        (*num)--;
    }
    printf("\n\nThe last person standing is at position %d.\n",(*front)->data);
}

void displayqueue(struct queue *front,int num)
{
    printf("\n\n*******Displaying the Queue*******");
    for(int i=0;i<num;i++)
    {
        printf("\n%d",front->data);
        front=front->next;
    }
}

int main()
{
    struct queue *front=NULL;
    struct queue *rear=NULL;
    int num;
    
    num=createqueue(&front,&rear);
    displayqueue(front,num);
    
    Josephus(&front,&rear,3,&num);
    return 0;
}