#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM (1000 + 1)
#define NUM_CHARS (256)

int main() {
    char palavra[MAX_TAM];
    unsigned int cont[NUM_CHARS], i, numImpares;

    while(!feof(stdin)) {
      // Lê a próxima instância.
        scanf("%s", &palavra);
        if(feof(stdin)) {
            break;
        }
        // Zera os contadores.
        for(i = 0; i < NUM_CHARS; i++) {
            cont[i] = 0;
        }
        // Computa as quantidades de cada letra.
        i = 0;
        while(palavra[i] != '\0') {
            cont[(unsigned int)palavra[i]]++;
            i++;
        }
        // Verifica o número de ímpares.
        numImpares = 0;
        for(i = 0; i < NUM_CHARS; i++) {
            if((cont[i] % 2) != 0) {
                numImpares++;
            }
        }
        // 
        if(numImpares) {
            numImpares--;
        }
        printf("%u\n", numImpares);
    }
    return 0;
}