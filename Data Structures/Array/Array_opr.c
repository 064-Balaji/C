#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>


int arr[100];
int length = 0, choice, data;

void creation();
void display();
void ins();

int main(){

    printf("\t \tWelcome to Array operations \t \t \n");

    creation();

    bool alive = true;

    while (alive)
    {
        printf("What do you want to do: \n");
        printf("1.Insertion 2.Deletion 3.Exit: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ins();
            break;
        
        case 3:
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
            arr[i] = arr[i+1];
        }
        
        printf("Enter element to insert: ");
        scanf("%d", &data);
        arr[0] = data;
        break;
    
    case 2:
        display();
        int sca, pos;
        printf("Enter after which element you want to insert: ");
        scanf("%d", &sca);
        for (int i=0; i<length; i++)
        {
            if(sca == arr[i]){
                for(int j=length; j<=0; j--){
                    arr[j] = arr[j+1];
                }
                pos=i;
            }
        }
        printf("Enter the value to insert: ");
        scanf("%d\n",&data);
        arr[pos] = data;
        
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