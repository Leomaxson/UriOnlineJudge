#include <stdlib.h>
#include <stdio.h>

#define DURACAO_PARTIDA (90)

int main(int argv, char** argc) {
    unsigned int numPinos, resposta, i;

    while(1) {
      // L� a inst�ncia e verifica a condi��o de sa�da.
        (void)scanf("%u %u", &numPinos, &resposta);
        if(numPinos == 0 && resposta == 0) {
            break;
        }
        // Imprime os primeiros K-1 elementos em ordem crescente.
        for(i = 1; i < resposta; i++) {
            (void)printf("%u ", i);
        }
        // Imprime os elementos restantes em ordem decrescente.
        while(numPinos > resposta) {
            (void)printf("%u ", numPinos);
            numPinos--;
        }
        (void)printf("%u\n", numPinos);
    }
    return 0;
}
