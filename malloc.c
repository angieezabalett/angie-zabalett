#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Escribi un numero:");
    int *pnumero = malloc(sizeof(int));
    scanf("%d", pnumero);
    printf("%d", *pnumero);
    return 0;
}