#include <stdio.h>

void squeeze(char s[], char d[]);
int contains(char d[], char s);

int main() {

  char s[] = "heello\0";
  char d[] = "el\0";
  printf("before = %s\n", s);
  squeeze(s, d);
  printf("after = %s\n", s);
  return 0;
}

void squeeze(char s[], char d[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++) {
    if (!contains(d, s[i])) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

int contains(char d[], char s) {
  int res = 0;
  for (int i = 0; d[i] != '\0'; i++) {
    if (d[i] == s) {
      return 1;
    }
  }
  return 0;
}
