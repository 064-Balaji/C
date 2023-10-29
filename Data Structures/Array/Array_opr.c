#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>


int arr[100];
int length = 0, choice, data;

void creation();
void display();
void ins();
void del();
void search();

int main(){

    printf("\t \tWelcome to Array operations \t \t \n");

    creation();

    bool alive = true;

    while (alive)
    {
        printf("What do you want to do: \n");
        printf("1.Insertion 2.Deletion 3.Display 4.Search 5.Exit: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ins();
            break;
        
        case 2:
            del();
            break;

        case 3:
            display();
            break;

        case 4:
            search();
            break;

        case 5:
            return 0;
            break;
        
        default:
            printf("Choose correct option:");
            break;
        }
    }
    printf("Good Bye!");
}


void creation(){
    int no;
    printf("Enter no of elements for array: ");
    scanf("%d", &no);

    for(int i=0; i<no; i++){
        printf("Enter %d element: ", i);
        scanf("%d", &data);
        arr[i]=data;
    }

    printf("Creation Finished. \n");

    printf("Array Status: \n");
    display();

    printf("Let's continue with other process. \n");
}


void display(){
    length = 0;
    for(int i=0; arr[i]!='\0'; i++){
        printf("%d-> ",arr[i]);
        length++;
    }
    printf("\nTotal no of elements: %d \n",length);
}

void ins(){
    printf("Choose where to insert: \n");
    printf("1.Insert at first\n2.Insert at middle\n3.Insert at end\n");
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
        printf("Enter the value to insert: ");
        scanf("%d",&data);
        arr[sca-1] = data;
        break;
        
    case 3:
        printf("Enter element to insert: ");
        scanf("%d", &data);
        arr[length] = data;
        break;

    case 4:
        display();
        break;
    
    default:
        break;
    }
}

void del(){
    printf("Deletion \n");

    printf("1.Deletion at first \n2.Deletion at middle \n3.Deletion at end \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Removing first element of an array...\n");
        for (int i = 0; i<length; i++)
        {
            arr[i] = arr[i+1];
        }
        length--;
        
        printf("Modified Array is: ");
        display();
        break;
    
    case 2:
        printf("Current Status: ");
        display();
        printf("Enter the element want to remove: ");
        scanf("%d", &data);

        for (int i=0; i<length; i++)
        {
            if(arr[i] == data){
                for (int j=i; j<length; j++)
                {
                    arr[j]=arr[j+1];
                }
                
            }
        }
        arr[length]=0;
        length--;

        printf("Modified Array is: ");
        display();
        break;
        
    case 3:
        printf("Removing the last element of an arrray...\n");
        arr[length-1] = 0;
        length--;

        printf("Modified Array is: ");
        display();
        break;

    default:
        break;
    }
}

void search(){
    printf("How do you want to perform searching \n");
    printf("1.Value of element 2.Position of an element\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the value to search: ");
        scanf("%d", &data);
        for(int i=0; i<length; i++){
            if(arr[i]==data){
                printf("The position of an entered Value is: %d \n", i+1);
            }
        }
        break;
    
    case 2:
        printf("Enter the position to find: ");
        scanf("%d", &data);

        printf("The value of an given position is: %d", arr[data-1]);

    default:
        break;
    }
}