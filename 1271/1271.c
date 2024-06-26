#include <stdio.h>

#define MAX_GENES 50001  // Adicionei uma posi��o pois todos os �ndices come�am com 1.

int main(int argv, char** argc) {
    unsigned int numGenes, numConsultas, casoTeste, numInversoes, i, j, aux, genes[MAX_GENES];

    // L� o tamanho da primeira inst�ncia para come�ar o algoritmo.
    (void)scanf("%u", &numGenes);
    casoTeste = 1;
    while(numGenes) {
      // Inicializa o vetor de genes.
        for(i = 1; i <= numGenes; i++) {
            genes[i] = i;
        }
        // L� a quantidade de invers�es e aplica cada uma delas ao vetor.
        (void)scanf("%u", &numInversoes);
        while(numInversoes) {
            (void)scanf("%u %u", &i, &j);
            // Aplica a invers�o.
            while(i < j) {
                aux = genes[i];
                genes[i] = genes[j];
                genes[j] = aux;
                i++;
                j--;
            }
            numInversoes--;
        }
        // Imprime o n�mero do caso de teste.
        (void)printf("Genome %u\n", casoTeste);
        // L� a quantidade de consultas e escreve a resposta para cada uma delas.
        (void)scanf("%u", &numConsultas);
        while(numConsultas) {
            (void)scanf("%u", &aux);
            for(i = 1; i <= numGenes; i++) {
                if(genes[i] == aux) {
                    (void)printf("%u\n", i);
                    break;
                }
            }
            numConsultas--;
        }
        // L� o tamanho da pr�xima inst�ncia.
        (void)scanf("%u", &numGenes);
        casoTeste++;
    }
    return 0;
}