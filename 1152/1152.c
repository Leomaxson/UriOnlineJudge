#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 200000
#define MAX_ARESTAS 200000

// Define o tipo referente à uma aresta.
typedef struct SAresta {
  int Peso;
  int Vertice1;
  int Vertice2;
} Aresta;

void quickSort(Aresta arestas[], int esquerda, int direita) {
  int i, j;
  Aresta x, y;

  i = esquerda;
  j = direita;
  x = arestas[(esquerda + direita) / 2];
  while(i <= j) {
    while(arestas[i].Peso < x.Peso && i < direita) {
      i++;
    }
    while(arestas[j].Peso > x.Peso && j > esquerda) {
      j--;
    }
    if(i <= j) {
      y = arestas[i];
      arestas[i] = arestas[j];
      arestas[j] = y;
      i++;
      j--;
    }
  }
  if(j > esquerda) {
    quickSort(arestas, esquerda, j);
  }
  if(i < direita) {
    quickSort(arestas, i, direita);
  }
}

void mesclaVertices(int vertices[], int numVertices, int referencia, int vertice) {
  int i;

  for(i = 0; i < numVertices; i++) {
    if(vertices[i] == vertice) {
      vertices[i] = referencia;
    }
  }
}

int main() {
  int numVertices, numArestas, i, tamFloresta, pesoTotal, pesoAGM, *vertices;
  Aresta * arestas;

  vertices = malloc(MAX_VERTICES * sizeof(int));
  arestas = malloc(MAX_ARESTAS * sizeof(Aresta));
  do {
    // Lê a quantidade de vértices e arestas da instância.
    scanf("%d %d", &numVertices, &numArestas);
    if(numVertices || numArestas) {
      pesoTotal = 0;
      // Cria a lista de vértices.
      for(i = 0; i < numVertices; i++) {
        vertices[i] = i;
      }
      // Lê todos os vértices e adiciona na lista.
      for(i = 0; i < numArestas; i++) {
        scanf("%d %d %d", &arestas[i].Vertice1, &arestas[i].Vertice2, &arestas[i].Peso);
        pesoTotal += arestas[i].Peso;
      }
      // Ordena a lista de arestas por peso preparando para executar o algoritmo de Kruskal.
      quickSort(arestas, 0, numArestas - 1);
      tamFloresta = numVertices;
      pesoAGM = 0;
      i = 0;
      // Processa aresta por aresta, em ordem, verificando se ela une duas sub-árvores distintas.
      while(tamFloresta > 1 && i < numArestas) {
        // Verifica se a aresta mais leve liga duas árvores diferentes.
        if(vertices[arestas[i].Vertice1] != vertices[arestas[i].Vertice2]) {
          pesoAGM += arestas[i].Peso;
          // Percorre a lista de vértices mesclando duas árvores que eram distintas.
          if(vertices[arestas[i].Vertice1] <= vertices[arestas[i].Vertice2]) {
            mesclaVertices(vertices, numVertices, vertices[arestas[i].Vertice1], vertices[arestas[i].Vertice2]);
          } else {
            mesclaVertices(vertices, numVertices, vertices[arestas[i].Vertice2], vertices[arestas[i].Vertice1]);
          }
          tamFloresta--;
        }
        i++;
      }
      printf("%d\n", pesoTotal - pesoAGM);
    }
  } while(numVertices || numArestas);
  free(vertices);
  free(arestas);
  return 0;
}