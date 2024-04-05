#include <stdio.h>
#include <math.h>

#define MATRIZ_MAX_LINHAS 7

#define MAX_VERTICES MATRIZ_MAX_LINHAS * MATRIZ_MAX_LINHAS
#define GRAU_MAXIMO 4

int main() {
  // Cores corVertice[MAX_VERTICES];
  unsigned int matrizAdjacencias[MAX_VERTICES][GRAU_MAXIMO], numAdjacencias[MAX_VERTICES],
    instancias, verticeInicial, numVertices, numArestas, i, j, k;

  // L� a quantidade de inst�ncias que dever�o ser executadas.
  scanf("%u", &instancias);
  while(instancias) {
    // L� o v�rtice inicial.
    scanf("%u", &verticeInicial);

    // L� a quantidade de v�rtices e arestas.
    scanf("%u %u", &numVertices, &numArestas);

    // Inicializa a matriz de adjac�ncias e o vetor de cores.
    for(i = 0; i < numVertices; i++) {
      for(j = 0; j < GRAU_MAXIMO; j++) {
        matrizAdjacencias[i][j] = -1;
      }
      numAdjacencias[i] = 0;
      // corVertice[i] = Branco;
    }

    // L� todas as arestas.
    while(numArestas) {
      scanf("%u %u", &i, &j);
      // Define a primeira adjac�ncia.
      k = 0;
      while(k < numAdjacencias[i] && matrizAdjacencias[i][k] != j) {
        k++;
      }
      if(k >= numAdjacencias[i]) {
        numAdjacencias[i]++;
      }
      matrizAdjacencias[i][k] = j;
      // Define a segunda adjac�ncia.
      k = 0;
      while(k < numAdjacencias[j] && matrizAdjacencias[j][k] != i) {
        k++;
      }
      if(k >= numAdjacencias[j]) {
        numAdjacencias[j]++;
      }
      matrizAdjacencias[j][k] = i;
      numArestas--;
    }

    // Calcula o n�mero de movimentos necess�rios.
    k = 0;
    for(i = 0; i < numVertices; i++) {
      k += numAdjacencias[i];
    }

    // Imprime o n�mero de movimentos necess�rios.
    printf("%u\n", k);
    instancias--;
  }
  return 0;
}