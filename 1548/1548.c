#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM (1000)

int Compara(const void * a, const void * b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int fila1[MAX_TAM], fila2[MAX_TAM], numInstancias, tamanhoFila, numElementosNaoTrocados, i;

  // Lê o número de instâncias.
  scanf("%u", &numInstancias);
  while(numInstancias) {
    // Lê a instância.
    scanf("%u", &tamanhoFila);
    for(i = 0; i < tamanhoFila; i++) {
      scanf("%u", &fila1[i]);
      fila2[i] = fila1[i];
    }
    // Ordena uma das filas.
    qsort(fila1, tamanhoFila, sizeof(int), Compara);
    // Percorre a fila de referência, verificando quantos elementos não trocaram de lugar.
    numElementosNaoTrocados = 0;
    for(i = 0; i < tamanhoFila; i++) {
      if(fila1[i] == fila2[i]) {
        numElementosNaoTrocados++;
      }
    }
    printf("%u\n", numElementosNaoTrocados);
    numInstancias--;
  }
  return 0;
}