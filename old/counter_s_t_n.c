#include <stdio.h>

main () {
    int s,n,t,c;
    s = 0;
    n = 0;
    t = 0;
    while ((c=getchar()) != EOF){
        if (c == ' '){
            s++;}
        if (c == '\n'){
            n++;}
        if (c == '\t'){
            t++;}
    }
    printf("Пробелов = %d Переносов строки = %d Табуляций = %d\n",s,n,t);
}
