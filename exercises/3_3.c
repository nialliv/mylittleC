#include <stdio.h>
#include <string.h>

void expand(const char s1[], char s2[]);
size_t getResultSize(const char s[]);

int main() {
  char *ss[] = {"0-9", "a-z", "A-z", "-a-z", "a-z-"};

  for (int indx = 0; indx < 5; indx++) {

    char newLine[getResultSize(ss[indx]) + 1];

    expand(ss[indx], newLine);
  }

  printf("\n");
  return 0;
}

size_t getResultSize(const char line[]) {
  size_t result = 0;
  unsigned long lastIndx = strlen(line) - 1;

  for (size_t i = 1; i < lastIndx; i++) {
    if ('-' == line[i]) {
      result += line[i + 1] + 1 - line[i - 1];
    }
  }

  if ('-' == line[0]) {
    result++;
  }

  if ('-' == line[lastIndx]) {
    result++;
  }

  return result;
}

void expand(const char input[], char result[]) {
  printf("Input - [%s]\n", input);

  size_t pointer = 0;
  unsigned long lastIndx = strlen(input) - 1;

  if ('-' == input[0]) {
    result[pointer++] = '-';
  }

  for (size_t i = 1; i < lastIndx; i++) {
    if ('-' == input[i]) {
      for (int j = input[i - 1]; j != input[i + 1] + 1; j++) {
        result[pointer++] = j;
      }
    }
  }

  if ('-' == input[lastIndx]) {
    result[pointer++] = '-';
  }

  result[pointer] = '\0';
  printf("Expanded - [%s]\n", result);
}
