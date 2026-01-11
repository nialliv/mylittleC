#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);

int main() {

  char before[] = "Hello\nI'm Fraddy! =)\n\tAnd u?";
  char after[2 * strlen(before) + 1];

  printf("Before escape - [%s]\n", before);

  escape(before, after);

  printf("After escape - [%s]\n", after);

  return 0;
}

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':

      t[j++] = '\\';
      t[j++] = 't';
      break;

    default:
      t[j++] = s[i];
      break;
    }
  }
  t[j] = '\0';
}
