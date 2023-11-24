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

int enqueue(struct queue **front,struct queue **rear,int num,int data)
{
    struct queue *new;
    new=malloc(sizeof(struct queue));
    new->data=data;
    (*rear)->next=new;
    new->next=*front;
    *rear=new;
    return ++num;
}

int dequeue(struct queue **front,struct queue **rear,int num)
{
    struct queue *temp;
    temp=*front;
    *front=(*front)->next;
    free(temp);
    (*rear)->next=*front;
    printf("\n\nSuccessfully dequeued....");
    return --num;
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
    
    num=enqueue(&front,&rear,num,5);
    displayqueue(front,num);
    
    num=dequeue(&front,&rear,num);
    displayqueue(front,num);
}