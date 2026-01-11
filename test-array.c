#include <stdio.h>

#define MAX_SIZE 1000

int main() {

  char s[MAX_SIZE];
  int i, lim, c;

  for (i = 0; i < lim && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }
}
