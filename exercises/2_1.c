#include <limits.h>
#include <stdio.h>

/* над чекнуть диапазоны
 * char short int long
 * signed unsigned
 *
 * Еще нам усложнили задачу - над еще и посчитать для вещественных чисел... Что
 * бы это не значило*/

int main() {
  printf("signed char min - [%d], max - [%d]\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char min - [%d], max - [%d]\n", 0, UCHAR_MAX);

  printf("signed short min - [%d], max - [%d]\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short min - [%d], max - [%d]\n", 0, USHRT_MAX);

  printf("signed int min - [%d], max - [%d]\n", INT_MIN, INT_MAX);
  printf("unsigned int min - [%d], max - [%u]\n", 0, UINT_MAX);

  printf("signed long min - [%lu], max - [%lu]\n", LONG_MIN, LONG_MAX);
  printf("unsigned long min - [%d], max - [%lu]\n", 0, ULONG_MAX);
  return 0;
}
