#include <stdio.h>

int main () {
    int c, simvols, state;
    while ((c = getchar()) != EOF){
        ++simvols;
    }
    printf("Символов - %d\t",simvols);
    for (state = 1; state < simvols; state++)
        printf("|");
    printf("\n");
    return 0;
}
