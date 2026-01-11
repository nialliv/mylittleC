#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 15

float get_fahr (int fa) {
    return (5.0/9.0)*(fa-32);
} 

int main () {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        get_fahr(fahr);
        printf("%3d %6.1f\n", fahr, get_fahr(fahr));
    }
    return 0;
}

