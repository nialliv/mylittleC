#include <stdio.h>
/* Копирование входного потока
   Version 1.5
*/
int main() {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
  return 0;
}
