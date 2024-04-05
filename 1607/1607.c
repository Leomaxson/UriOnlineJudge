#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 1000+1

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
    char stringA[TAMANHO], stringB[TAMANHO];
    unsigned int i, operacoes, instancias;
    char aux;

    scanf("%u", &instancias);
    while(instancias > 0) {
        scanf("%s %s", stringA, stringB);
        operacoes = 0;
        i = 0;
        while(stringA[i] != '\0') {
            aux = stringB[i] - stringA[i];
            if(aux < 0) {
                aux += 26;
            }
            operacoes += aux;
            i++;
        }
        printf("%u\n", operacoes);
        instancias--;
    }
    return 0;
}