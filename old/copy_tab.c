#include <stdio.h>

int main() {
    int c;
    while((c = getchar()) != EOF){
        if (c == '\t'){
            printf("\\t");
            while ((c = getchar()) == '\t')
                printf("\\t");
        }
        if (c == '\b'){
            printf("\\b");
            while ((c = getchar()) == '\b')
                printf("\\b");
        }
        if (c != EOF){
            putchar(c);
        }
    }
    return 0;
}

