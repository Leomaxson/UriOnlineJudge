#include <stdlib.h>
#include <stdio.h>

#define TAM_ENTRADA (5)

int main(int argv, char** argc) {
    int input, impares, pos, neg, i;

    impares = pos = neg = 0;
    for(i = 0; i < TAM_ENTRADA; i++) {
        (void)scanf("%d", &input);
        if(input % 2) {
            impares++;
        }
        if(input > 0) {
            pos++;
        } else if(input < 0) {
            neg++;
        }
    }
    (void)printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", TAM_ENTRADA - impares, impares, pos, neg);
    return 0;
}