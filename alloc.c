#include <stdio.h>
#include <string.h>

#define MAX_ALLOC_SIZE 10000

static char allocbuf[MAX_ALLOC_SIZE];
static char *allocp = allocbuf;

char *alloc(int size) {
  long availableMem = allocbuf + MAX_ALLOC_SIZE - allocp;
  if (availableMem < size) {
    printf("Cannot alloc size - [%d], max size - [%ld]", size, availableMem);
  }
  allocp += size;
  return allocp;
}

void afree(char *p) {
  if (allocp <= p && p < allocbuf + MAX_ALLOC_SIZE) {
    allocp = p;
  }
}

int main() {

  char *strings[10];
  int str_count = 0;

  printf("=== Строковый стек ===\n");

  // 1. Выделяем память под строки
  strings[str_count] = alloc(50);
  strcpy(strings[str_count], "Первая строка");
  str_count++;

  strings[str_count] = alloc(50);
  strcpy(strings[str_count], "Вторая строка");
  str_count++;

  strings[str_count] = alloc(50);
  strcpy(strings[str_count], "Третья строка");
  str_count++;

  // 2. Печатаем все строки
  printf("Содержимое стека:\n");
  for (int i = 0; i < str_count; i++) {
    printf("%d: %s\n", i, strings[i]);
  }

  // 3. Освобождаем в обратном порядке!
  printf("\nОсвобождаем...\n");
  afree(strings[--str_count]); // Освобождаем третью
  printf("Освобождена третья строка\n");

  afree(strings[--str_count]); // Освобождаем вторую
  printf("Освобождена вторая строка\n");

  // 4. Выделяем новую строку на освобождённом месте
  strings[str_count] = alloc(30);
  strcpy(strings[str_count], "Новая строка");
  str_count++;

  printf("\nПосле переиспользования:\n");
  for (int i = 0; i < str_count; i++) {
    printf("%d: %s\n", i, strings[i]);
  }

  // 5. Освобождаем всё остальное
  while (str_count > 0) {
    afree(strings[--str_count]);
  }

  return 0;
}
