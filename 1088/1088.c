#include <stdio.h>
#include <stdlib.h>

// Realiza o merge de duas parti��es.
unsigned int merge(unsigned int vetor[], unsigned int comeco, unsigned int meio, unsigned int fim) {
    unsigned int pos1, pos2, posAux, tamanho, inversoes;
    unsigned int *vetorAux;

    pos1 = comeco;
    pos2 = meio;
    posAux = 0;
    tamanho = fim - comeco;
    inversoes = 0;
    vetorAux = (int*)malloc(tamanho * sizeof(int));
    while(pos1 < meio && pos2 < fim) {
        if(vetor[pos1] <= vetor[pos2]) {
            vetorAux[posAux] = vetor[pos1];
            pos1++;
        } else {
            vetorAux[posAux] = vetor[pos2];
            pos2++;
            // Conta as invers�es.
            inversoes += meio - pos1;
        }
        posAux++;
    }
    // Termina a primeira parti��o se n�o estiver vazia.
    while(pos1 < meio) {
        vetorAux[posAux] = vetor[pos1];
        posAux++;
        pos1++;
    }
    // Termina a segunda parti��o se n�o estiver vazia.
    while(pos2 < fim) {
        vetorAux[posAux] = vetor[pos2];
        posAux++;
        pos2++;
    }
    // Copia de volta para o vetor original.
    for(posAux = 0; posAux < tamanho; posAux++) {
        vetor[comeco + posAux] = vetorAux[posAux];
    }
    free(vetorAux);
    return inversoes;
}

// Realiza o Merge Sort.
unsigned int mergeSort(unsigned int vetor[], unsigned int comeco, unsigned int fim) {
    unsigned int meio, numElementos, inversoes;

    numElementos = fim - comeco;
    meio = (fim + comeco) / 2;
    inversoes = 0;
    if(numElementos > 2) {
        inversoes = mergeSort(vetor, comeco, meio);
        inversoes += mergeSort(vetor, meio, fim);
    }
    inversoes += merge(vetor, comeco, meio, fim);
    return inversoes;
}

int main(int argv, char** argc) {
    unsigned int tamanho, inversoes, i, sequencia[100000];
    // unsigned int *sequencia;

    // L� o tamanho da primeira inst�ncia.
    scanf("%u", &tamanho);
    while(tamanho) {
      // L� a sequ�ncia.
      // sequencia = (unsigned int*)malloc(tamanho * sizeof(unsigned int));
        for(i = 0; i < tamanho; i++) {
            scanf("%u", &sequencia[i]);
        }
        // Calcula o n�mero de invers�es.
        inversoes = mergeSort(sequencia, 0, tamanho);
        // free(sequencia);
        // Imprime o resultado.
        if(inversoes % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
        // L� o tamanho da pr�xima inst�ncia.
        scanf("%u", &tamanho);
    }
    return 0;
}