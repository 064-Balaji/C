#include <stdio.h>

void isempty(int Queue[], int size){
    if(Queue[0] == 0){
        printf("Empty");
    }
    else{
        for(int i=0; i<size; i++){
            printf("%d", Queue[i]);
        }
    }
}

void insele(int Queue[], int n, int front, int rear){
    int no, data;
    printf("Enter no of element \n");
    scanf("%d", &no);
    for(int i=0; i<no; i++){
        printf("Enter %d element \n", i+1);
        scanf("%d", &data);
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        Queue[rear] = data;
    }
}

void display(int Queue[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ",Queue[i]);
    }
}

int main(){
    int size;
    printf("Enter the size of Queue: \n");
    scanf("%d", &size);
    int Queue[size];
    int choice = 3;
    int front =-1, rear = -1;


    printf("Choose the action to perform: \n");
    printf("1. Insert Element \n");

    while (choice == 0)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            isempty(Queue, size);
            break;
        
        case 2:
            insele(Queue, size, front, rear);
            break;

        case 3:
            display(Queue, size);
            break;

        default:
            break;
        }
    }
    
    return 0;
    
}
