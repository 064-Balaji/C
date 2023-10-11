#include <stdio.h>
#include <ctype.h>
#include <string.h>

void replaceNonAlphabets(char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            *str = '$';
        }
        str++;
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character added by fgets
    input[strlen(input) - 1] = '\0';

    printf("Original string: %s\n", input);

    replaceNonAlphabets(input);

    printf("Modified string: %s\n", input);

    return 0;
}
