#include <stdio.h>

int main()
{
    int ch, num;
    while ((ch = getchar()) != EOF)
    {
        num = 0;
        if (ch == '\t')
        {
            printf("\\t");
            num = 1;
        }
        if (ch == '\b')
        {
            printf("\\b");
            num = 1;
        }
        if (ch == '\\')
        {
            printf("\\\\");
            num = 1;
        }
        if (num != 1)
            putchar(ch);
    }

    return 0;
}