#include <stdio.h>
#include <stdlib.h>

int main() {
    char flag = 'Y';
    while (flag == 'Y' || flag=='y'){
        printf("Welcom to Decimal to Hexadecimal converter\n");
        printf("Enter the number: \n");
        int num;
        scanf("%d", &num);
        printf("The decimal Number is:      %d \n",num);
        printf("The Hexa Decimal Number is: %X \n",num);
        printf("Do you want to continue: Y/N");
        scanf("%c", &flag);
    }
    return 0;
}