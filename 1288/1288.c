#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int problemaMochila(int capacidade, int pesos[], int lucros[], int numItens) {
    int i, w, retorno;
    int** mochila;

    // Cria a mochila.
    mochila = (int**)malloc((numItens + 1) * sizeof(int));
    for(i = 0; i < numItens + 1; i++) {
        mochila[i] = (int*)malloc((capacidade + 1) * sizeof(int));
    }
    // Monta a tabela de recorrências.
    for(i = 0; i <= numItens; i++) {
        for(w = 0; w <= capacidade; w++) {
            if(i == 0 || w == 0) {
                mochila[i][w] = 0;
            } else if(pesos[i - 1] <= w) {
                mochila[i][w] = max(
                    lucros[i - 1] + mochila[i - 1][w - pesos[i - 1]],
                    mochila[i - 1][w]);
            } else {
                mochila[i][w] = mochila[i - 1][w];
            }
        }
    }
    // Libera o espaço e retorna.
    retorno = mochila[numItens][capacidade];
    for(i = 0; i < numItens + 1; i++) {
        free(mochila[i]);
    }
    free(mochila);
    return retorno;
}

int main(int argv, char** argc) {
    int numProjeteis, capacidadeCanhao, resistenciaCastelo, numInstancias, i, resultado;
    int *pesosProjeteis, *danosProjeteis;

    // Lê o número de instâncias.
    scanf("%d", &numInstancias);
    while(numInstancias) {
      // Lê a instância.
        scanf("%d", &numProjeteis);
        pesosProjeteis = (int *)malloc(numProjeteis * sizeof(int));
        danosProjeteis = (int *)malloc(numProjeteis * sizeof(int));
        for(i = 0; i < numProjeteis; i++) {
            scanf("%d %d", &danosProjeteis[i], &pesosProjeteis[i]);
        }
        scanf("%d", &capacidadeCanhao);
        scanf("%d", &resistenciaCastelo);
        // Calcula o problema da mochila inteira e verifica o resultado.
        resultado = problemaMochila(capacidadeCanhao, pesosProjeteis, danosProjeteis, numProjeteis);
        if(resultado < resistenciaCastelo) {
            (void)printf("Falha na missao\n");
        } else {
            (void)printf("Missao completada com sucesso\n");
        }
        // Desaloca a memória.
        free(danosProjeteis);
        free(pesosProjeteis);
        numInstancias--;
    }
    return 0;
}