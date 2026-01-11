#include <stdio.h>

static int size = 100;

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void print_length(char *line) {
  int res;
  for (res = 0; *line != '\0'; line++) {
    res++;
  }
  printf("length - [%d]\n", res);
}

void print_arr(int *arr) {
  for (int *p = arr; p < arr + size; p++) {
    printf("%d ", *p);
  }
}

int main() {
  char *s = "Hello";

  printf("%c\n", *(s + 1));

  return 0;
}
