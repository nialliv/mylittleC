#include <stdio.h>

int main () {
    int c;
    while ((c = getchar()) != EOF){
        while ((c = getchar()) != EOF){
            if (c == '\n')
                printf("\n");
        }
    }
    return 0;
}
