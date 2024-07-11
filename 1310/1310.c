#include <stdio.h>

#define MAX_DIAS 50

#define max(a,b) (((a) > (b)) ? (a) : (b))

int somaMaximaSubvetor(int *vetor, int tamVetor) {
    int i, maxAtual, maxGlobal;

    maxGlobal = 0;
    maxAtual = 0;
    for(i = 0; i < tamVetor; i++) {
        maxAtual = max(vetor[i], vetor[i] + maxAtual);
        maxGlobal = max(maxGlobal, maxAtual);
    }
    return maxGlobal;
}

int main(int argv, char **argc) {
    int lucroPorDia[MAX_DIAS], custoPorDia, receitaDoDia, numDias, i;

    while(!feof(stdin)) {
        // Lê a entrada.
        (void)scanf("%d", &numDias);
        if(feof(stdin)) {
            break;
        }
        (void)scanf("%d", &custoPorDia);
        for(i = 0; i < numDias; i++) {
            (void)scanf("%d", &receitaDoDia);
            lucroPorDia[i] = receitaDoDia - custoPorDia;
        }
        // Calcula e imprime a máxima receita.
        (void)printf("%d\n", somaMaximaSubvetor(lucroPorDia, numDias));
    }
    return 0;
}
