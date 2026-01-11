#include "array_utils.h"
#include <stddef.h>

void print_int_array(const int arr[], int size) {
  if (size <= 0) {
    printf("[]\n");
    return;
  }

  printf("[");

  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }

  printf("]\n");
}

int sizeof_str(const char s[]) {
  int length = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    length++;
  }
  return length;
}
