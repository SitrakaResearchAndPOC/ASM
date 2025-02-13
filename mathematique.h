// mathematique.c
#include <stdio.h>
#include "mathematique.h"

// Fonction pour additionner deux entiers
int addition(int a, int b) {
    return a + b;
}

// Fonction pour soustraire deux entiers
int soustraction(int a, int b) {
    return a - b;
}

// Fonction pour multiplier deux entiers
int multiplication(int a, int b) {
    return a * b;
}

// Fonction pour diviser deux entiers
// Remarque : on suppose que b n'est pas nul.
int division(int a, int b) {
    if (b == 0) {
        printf("Erreur : Division par zéro!\n");
        return 0; // ou une autre valeur spéciale en cas d'erreur
    }
    return a / b;
}