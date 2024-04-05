#include <stdio.h>

#define MAX_GENES 50001  // Adicionei uma posição pois todos os índices começam com 1.

int main(int argv, char** argc) {
    unsigned int numGenes, numConsultas, casoTeste, numInversoes, i, j, aux, genes[MAX_GENES];

    // Lê o tamanho da primeira instância para começar o algoritmo.
    scanf("%u", &numGenes);
    casoTeste = 1;
    while(numGenes) {
      // Inicializa o vetor de genes.
        for(i = 1; i <= numGenes; i++) {
            genes[i] = i;
        }
        // Lê a quantidade de inversões e aplica cada uma delas ao vetor.
        scanf("%u", &numInversoes);
        while(numInversoes) {
            scanf("%u %u", &i, &j);
            // Aplica a inversão.
            while(i < j) {
                aux = genes[i];
                genes[i] = genes[j];
                genes[j] = aux;
                i++;
                j--;
            }
            numInversoes--;
        }
        // Imprime o número do caso de teste.
        printf("Genome %u\n", casoTeste);
        // Lê a quantidade de consultas e escreve a resposta para cada uma delas.
        scanf("%u", &numConsultas);
        while(numConsultas) {
            scanf("%u", &aux);
            for(i = 1; i <= numGenes; i++) {
                if(genes[i] == aux) {
                    printf("%u\n", i);
                    break;
                }
            }
            numConsultas--;
        }
        // Lê o tamanho da próxima instância.
        scanf("%u", &numGenes);
        casoTeste++;
    }
    return 0;
}