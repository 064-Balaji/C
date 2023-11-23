#include <stdio.h>
#include <string.h>
#include <ctype.h>

void symbol(char sym);

char c[50];
int arr[10];
int cur = 0;

int main(){

    printf("Enter the postfix expression: ");
    scanf("%s",c);

    for (int i = 0; i < strlen(c); i++)
    {
        if(isdigit(c[i])){
            arr[cur] = c[i] - '0';
            cur++;
        }
        else{
            symbol(c[i]);
        }
    }

    printf("The Evaluated value is: %d\n ", arr[0]);
    return -1;
}

void symbol(char sym){
    switch (sym)
    {
    case '+':
        arr[cur-2] = arr[cur-2] + arr[cur-1];
        cur--;
        break;

    case '-':
        arr[cur-2] = arr[cur-2] - arr[cur-1];
        cur--;
        break;

    case '/':
        arr[cur-2] = arr[cur-2] / arr[cur-1];
        cur--;
        break;

    case '*':
        arr[cur-2] = arr[cur-2] * arr[cur-1];
        cur--;
        break;
    
    default:
        printf("This %c symbol is not suuported here. \nLet's try some other symbols", sym);
        break;
    }
}