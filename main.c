// main.c
#include <stdio.h>
#include "mathematique.h"

int main() {
    int a = 10;
    int b = 5;

    // Test des fonctions
    printf("Addition de %d et %d : %d\n", a, b, addition(a, b));
    printf("Soustraction de %d et %d : %d\n", a, b, soustraction(a, b));
    printf("Multiplication de %d et %d : %d\n", a, b, multiplication(a, b));
    printf("Division de %d et %d : %d\n", a, b, division(a, b));

    return 0;
}