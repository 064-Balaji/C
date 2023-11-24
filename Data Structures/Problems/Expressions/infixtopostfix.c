#include <stdio.h>
#include <string.h>

char inf[50], pos[50];
int top = 0, stack[25];
void postfix();
char pop();
void push(int data);

int main(){
    printf("Enter the infix expression: ");
    scanf("%s",inf);

    postfix();

    return -1;
}

void postfix(){
    int i, j=0;
    for(i=0; inf[i] != '\0'; i++){
        switch (inf[i])
        {
        case '+':
            while(stack[top] >= 1)
                pos[j++]= pop();
            push(1);
            break;
        
        case '-':
            while (stack[top] >= 1)
            {
                pos[j++] = pop();
            }
            push(2);
            break;

        case '*':
            while (stack[top] >= 3)
            {
                pos[j++] = pop();
            }
            push(3);
            break;

        case '/':
            while (stack[top] >= 3)
            {
                pos[j++] = pop();
            }
            push(4);
            break;

        case '^':
            while (stack[top] >= 4)
            {
                pos[j++] = pop();
            }
            push(5);
            break;

        case '(':
            push(0);
            break;
            
        case ')':
            while (stack[top] != 0)
            {
                pos[j++] = pop();
            }
            top--;
            break;
            
        default:
            pos[j++] = inf[i];
            break;
        }
    }
    while (top>0)
    {
        pos[j++] = pop();
    }

    printf("The posfix expression is: %s", pos);
}

void push(int data){
    top++;
    stack[top] = data;
}

char pop(){
    int e1;
    char e;
    e1 = stack[top];
    top--;

    switch (e1)
    {
    case 1:
        e= '+';
        break;

    case 2:
        e= '-';
        break;

    case 3:
        e= '*';
        break;

    case 4:
        e= '/';
        break;

    case 5:
        e= '^';
        break;
    }
    return (e);
}