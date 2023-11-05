#include <stdio.h>
#include <conio.h>


void create();
void insert();
void delete();
void display();


int arr[100], front, rear;
int length, data, choice;

int main()
{
    printf("\t \t Queue Operations\n");
    create();


    do{
        printf("What do you want to do: \n");
        printf("1.Insertion   2.Deletion   3.Display   4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
                break;

            default:
                printf("Choose the correct option");
                break;
        }
    }while(choice != 4);
    return 0;
}

void create()
{
    printf("array creation...\n");
    printf("Enter no of elements: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        printf("Enter %d element: ", i);
        scanf("%d", &data);

        if(front == -1)
        {
            arr[i] = data;
            front=rear=0;
        }
        else
        {
            arr[i] = data;
            rear=i;
        }
    }
    
}

void insert()
{
    printf("Insert\n");
    printf("1.First   2.Middle   3.End\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (int i=length; i>=0; i--)
        {
            arr[i+1] = arr[i];
        }
        
        printf("Enter element to insert: ");
        scanf("%d", &data);
        arr[0] = data;
        length++;
        break;
    
    case 2:
        display();
        int sca;
        printf("Enter position for where to insert: ");
        scanf("%d", &sca);
        for (int i=length; i>=sca-1; i--)
        {
            arr[i] = arr[i-1];
        }
        printf("Enter element to insert: ");
        scanf("%d",&data);
        arr[sca-1] = data;
        length++;
        break;
        
    case 3:
        printf("Enter element to insert: ");
        scanf("%d", &data);
        arr[length] = data;
        length++;
        break;
    
    default:
        break;
    }
}

void delete()
{
    printf("1.Deletion at first   2.Deletion at middle   3.Deletion at end \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Removing first element of an array...\n");
        for (int i=0; i<length-1; i++)
        {
            arr[i] = arr[i+1];
        }
        length--;
        rear = length-1;
        
        printf("Modified Array is: ");
        display();
        break;
    
    case 2:
        printf("Current Status: ");
        display();
        printf("Enter the element want to remove: ");
        scanf("%d", &data);

        for (int i=0; i<length-1; i++)
        {
            if(arr[i] == data){
                for (int j=i; j<length-1; j++)
                {
                    arr[j]=arr[j+1];
                }
                
            }
        }
        arr[length]=0;
        length--;
        rear = length-1;

        printf("Modified Array is: ");
        display();
        break;
        
    case 3:
        printf("Removing the last element of an arrray...\n");
        arr[length-1] = 0;
        length--;
        rear = length-1;

        printf("Modified Array is: ");
        display();
        break;

    default:
        break;
    }
}

void display()
{
    for (int i = 0; i < length; i++)
    {
        printf("%d-> ", arr[i]);
    }

    printf("\n");
    
    printf("Front element is: %d \n", arr[front]);
    printf("Rear element is: %d \n", arr[rear]);
}