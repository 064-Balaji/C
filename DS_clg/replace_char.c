#include <stdio.h>

int main() {
  char str[100];
  int i;

  printf("Enter a string: ");
  scanf("%s", str);

  for (i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i])) {
      str[i] = '$';
    }
  }

  printf("The modified string is: %s\n", str);

  return 0;
}

