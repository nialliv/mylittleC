#include <stdio.h>
int main () {
    int c,i,j,length;
    int alfovit[26];
    length = 0;
    for (i = 0; i < 26; ++i)
        alfovit[i] = 0;
    while ((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z') {
            ++alfovit[c - 'a'];
        }}
    for (i = 0; i < 26; ++i){
        printf("\n%d\t", alfovit[i]);
            for(j=0; j < alfovit[i]; j++){
                putchar('_');
                printf("\n");
            }
    }
    return 0;
}
