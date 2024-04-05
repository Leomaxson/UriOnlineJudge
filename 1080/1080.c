/*
Problema: Maior e Posição (URI-1080)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

A estratégia usada é simplesmente ler cada número da entrada e verificar se ele é o maior até
agora. Se for, guarda o valor dele e sua posição.
*/

#include <stdio.h>
#define NUM_ENTRADAS 100

int main(int argv, char** argc) {
    unsigned int maior, posicaoMaior, i, valorLido;

    maior = 0;
    posicaoMaior = 0;

    for(i = 0; i < NUM_ENTRADAS; i++) {
        (void)scanf("%u", &valorLido);
        if(valorLido > maior) {
            maior = valorLido;
            posicaoMaior = i;
        }
    }

    posicaoMaior++;
    (void)printf("%u\n", maior);
    (void)printf("%u\n", posicaoMaior);
    return 0;
}