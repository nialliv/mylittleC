#include <stdio.h>
#include <string.h>

const char *message = "Hello, World!";
#define HIST_CAP 256
size_t hist[HIST_CAP] = {0};

int main()
{
    size_t idx[] = {3, 6, 7, 7, 8, 2, 0, 4, 8, 9, 7, 5, 1};
    const char *table = " !,HWdelor";

    for (size_t i = 0; i < sizeof(idx) / sizeof(idx[0]); ++i)
    {
        putchar(table[idx[i]]);
    }

    return 0;
}