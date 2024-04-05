#include <stdlib.h>
#include <stdio.h>

#define DURACAO_PARTIDA (90)

int main(int argv, char** argc) {
    unsigned int numPinos, resposta, i;

    while(1) {
      // Lê a instância e verifica a condição de saída.
        scanf("%u %u", &numPinos, &resposta);
        if(numPinos == 0 && resposta == 0) {
            break;
        }
        // Imprime os primeiros K-1 elementos em ordem crescente.
        for(i = 1; i < resposta; i++) {
            printf("%u ", i);
        }
        // Imprime os elementos restantes em ordem decrescente.
        while(numPinos > resposta) {
            printf("%u ", numPinos);
            numPinos--;
        }
        printf("%u\n", numPinos);
    }
    return 0;
}
