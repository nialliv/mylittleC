#include <stdio.h>

struct point {
  int x;
  int y;
};

int main() {
  struct point p = {1, 2};

  printf("point - %d, %d\n", p.x, p.y);
  return 0;
}
