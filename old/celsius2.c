#include <stdio.h>

main () {
    printf("Программа вывода таблицы Цельсия версии 2.0\n");
    printf("Фаренгейт\t\tЦельсий\n");
    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 15) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
