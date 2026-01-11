#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  char tmp;

  for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

int main() {
  char string[1000];
  itoa(12345, string);
  printf("Result - [%s]\n", string);
  return 0;
}
