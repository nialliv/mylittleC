#include <stdio.h>
int atoi(const char s[]);

int main() {
  printf("result = %d\n", atoi("Hello 45 avhs;ouio 3831"));

  return 0;
}

int atoi(const char s[]) {
  int result = 0;

  for (int i = 0; s[i] != '\0'; i++) {

    if (s[i] >= '0' && s[i] <= '9') {
      result = 10 * result + (s[i] - '0');
    }
  }
  return result;
}
