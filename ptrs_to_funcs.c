#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc(char *first, char *second) {
  if (strlen(first) < strlen(second))
    return -1;
  return 1;
}

int desc(char *first, char *second) { return !asc(first, second); }

void print_by_comp(char *first, char *second, int (*comp)(char *, char *)) {
  if ((*comp)(first, second) < 0) {
    printf("result - %s\n", first);
  } else {
    printf("result - %s\n", second);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Not valid argv\nargc = %d\n", argc);
    return EXIT_FAILURE;
  }

  print_by_comp(argv[1], argv[2], asc);

  return EXIT_SUCCESS;
}
