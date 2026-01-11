// todo impl strcat func - copy t to the end of s
#include <stdio.h>

void my_strcat(char *target, char *source) {
  while (*target) {
    target++;
  }

  while ((*target = *source) != '\0') {
    target++;
    source++;
  }
}

int main() {
  char s[50] = "Hello";
  my_strcat(s, " World!!!");

  printf("Result - [%s]\n", s);

  return 0;
}
