#include <stdio.h>
#include <stdlib.h>

void print(int stack[], int top)
{
 int i;
 printf("The stack element are: \n");
 for(i=0; i<=top; i++){
  printf("%d\n", stack[i]);
 }
}
int pop(int stack[],int top){
 stack[top] = 0;
 return --top;
}


int create(int stack[], int top)
{
 int n;
 printf("Enter the size of stack: \n");
 scanf("%d", &n);
 for(top=0; top<n; top++){
  printf("Enter %d element: ", top);
  scanf("%d",&stack[top]);
 }
 return --top;
}

void main(){
 int stack[50], top;
 int choice;
  top = create(stack,top);

 printf("Enter operation to perform: \n");
 printf("1.push 2.pop 3.print 4.exit\n");
 scanf("%d", &choice);
 while(choice != 4){
 switch(choice){
  case 1:
   printf("Under dev");
   break;
  case 2:
   top = pop(stack, top);
   break;
  case 3:
   print(stack, top);
   break;
 }
 }

 getch();
 clrscr();
}