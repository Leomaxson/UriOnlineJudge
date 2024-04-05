#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_BUFFER (5)

int main(int argv, char** argc) {
    unsigned int numInstancias, min, max, i, tamNum, j;
    char buffer[TAMANHO_BUFFER + 1], aux;

    // Lê o número de instâncias.
    (void)scanf("%u", &numInstancias);
    while(numInstancias) {
      // Lê os limites da instância.
        (void)scanf("%u %u", &min, &max);
        // Imprime a ida.
        for(i = min; i <= max; i++) {
            (void)printf("%u", i);
        }
        // Imprime a volta.
        for(i = max; i >= min; i--) {
          // Acha o tamanho do número.
            sprintf(buffer, "%u", i);
            tamNum = 1;
            while(buffer[tamNum] != '\0') {
                tamNum++;
            }
            tamNum--;
            // Inverte o número no buffer.
            j = 0;
            while(j < tamNum) {
                aux = buffer[j];
                buffer[j] = buffer[tamNum];
                buffer[tamNum] = aux;
                j++;
                tamNum--;
            }
            // Imprime o número invertido.
            (void)printf("%s", buffer);
        }
        (void)printf("\n");
        numInstancias--;
    }
    return 0;
}