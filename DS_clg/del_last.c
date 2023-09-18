#include <stdio.h>

void delete_last_element(int array[], int size) {
  int i;

  for (i = size - 1; i >= 0; i--) {
    array[i] = array[i - 1];
  }

  array[size] = 0;
}

int main() {
  int array[] = {1, 2, 3, 4, 5}, i;
  int size = sizeof(array) / sizeof(array[0]);

  delete_last_element(array, size);

  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}

