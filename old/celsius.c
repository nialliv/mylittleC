#include <stdio.h>

main(){
    printf("Пошло поехало)\nНиже идет таблица Цельсия и Фаренгейта\n");
    
    int fahr, celsius;

    int lower = 0;   //Нижняя граница таблицы
    int upper = 300; //Верхняя граница
    int step = 5;   //Шаг

    fahr = lower;

    printf("Фаренгейт\tЦельсий\n");
    while (fahr <= upper){
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t\t%d\n", fahr, celsius);
        fahr += step;
    }
}
