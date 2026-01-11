#include <stdio.h>
/*
 Копирование файла
 Version = 1.0
*/
int main() {
  int c;
  c = getchar();
  while (c != EOF) { // Аббревиатура. Конец файла
    putchar(c);
    c = getchar();
  }
}
