#include <stdio.h>

int my_strpbrk(char s[], char s2[]);

int main() {
  printf("result - %d\n", my_strpbrk("Hello", "zo"));
  return 0;
}

int my_strpbrk(char s[], char s2[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}
