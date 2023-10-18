#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
   stack[++top] = item;
}

char pop() {
   if (top == -1)
      return -1;
   else
      return stack[top--];
}

int precedence(char symbol) {
   switch (symbol) {
      case '+':
      case '-':
         return 2;
      case '*':
      case '/':
         return 3;
      case '^':
         return 4;
      case '(':
      case ')':
      case '#':
         return 1;
   }
   return -1;
}

void infixToPostfix(char infix_exp[], char postfix_exp[]) {
   int i, j = 0;
   char item;
   char x;

   push('(');
   strcat(infix_exp, ")");

   for (i = 0; infix_exp[i] != '\0'; i++) {
      item = infix_exp[i];

      if (item == '(') {
         push(item);
      }
      else if (isalnum(item)) {
         postfix_exp[j++] = item;
      }
      else if (item == ')') {
         while ((x = pop()) != '(')
            postfix_exp[j++] = x;
      }
      else {
         while (precedence(stack[top]) >= precedence(item))
            postfix_exp[j++] = pop();
         push(item);
      }
   }

   postfix_exp[j] = '\0';
}

int main() {
   char infix[SIZE], postfix[SIZE];

   printf("Enter Infix expression: ");
   fgets(infix, SIZE, stdin);

   infix[strcspn(infix, "\n")] = 0;

   infixToPostfix(infix, postfix);

   printf("Postfix Expression: ");
   puts(postfix);

   return 0;
}

void wait(){
   
}
