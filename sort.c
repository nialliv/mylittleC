#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAX_ALLOC_SIZE 10000

char *lineptr[MAXLINES];
static char allocbuf[MAX_ALLOC_SIZE];
static char *allocp = allocbuf;

int readlines(char *lineptrp[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main() {

  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }

  printf("error: input too big to sort\n");
  return 1;
}

int my_getline(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    *(s + i) = c;
  }

  if (c == '\n') {
    *(s + i) = c;
    ++i;
  }

  *(s + i) = '\0';

  return i;
}

char *alloc(int size) {
  long availableMem = allocbuf + MAX_ALLOC_SIZE - allocp;
  if (availableMem < size) {
    printf("Cannot alloc size - [%d], max size - [%ld]", size, availableMem);
  }
  allocp += size;
  return allocp;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = my_getline(line, MAXLEN) >= 0)) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    }
    line[len - 1] = '\0';
    strcpy(p, line);
    lineptr[nlines++] = p;
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  for (int i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

void qsort(char *v[], int left, int right) {
  int i, last;

  void swap(char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);

  last = right;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
