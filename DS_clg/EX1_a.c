#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(! isalpha(str[i])){
            str[i] = '$';
        }
    }
    printf("The modeified string is: %s\n", str);
    return 0;
}
