#include <stdio.h>
void squeeze(char s[], char c);

int main() {

  char lines[] = "Hello\0";

  printf("before = %s\n", lines);
  squeeze(lines, 'l');
  printf("after = %s\n", lines);

  return 0;
}

void squeeze(char s[], char c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}
