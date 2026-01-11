#include <stdio.h>

int a = 5;

void print_a() { printf("%d\n", a); }

int main() {

  a = 7;
  printf("%d\n", a);

  a = 6;

  print_a();
  return 0;
}
