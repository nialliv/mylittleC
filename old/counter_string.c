#include <stdio.h>
main () {
    int c, n1;
    while((c = getchar()) != EOF) {
        if (c == '\n'){
            ++n1;
        }
    }
    printf("%d\n",n1);
}
