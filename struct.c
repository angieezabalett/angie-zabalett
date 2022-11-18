//de angie
#include <stdio.h>

struct num {
    int hola;
    struct num *prev;
} num1, num2, num3;

int main () {
    num1.hola = 1;
    num2.hola = 2;
    num3.hola = 3;

    num3.prev = &num2;
    num2.prev = &num1;
    num1.prev = NULL;

    printf ("%d", num3.prev->hola);
}