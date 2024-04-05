#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct SNoLista {
  int Dest;
  int Peso;
  struct SNoLista *Prox;
} NoLista;

typedef struct SGrafo {
  int NumVertices;
  NoLista **Lista;
} Grafo;

NoLista* NoLista_Cria(int destino, int peso) {
  NoLista *novoNo = (NoLista*)malloc(sizeof(NoLista));
  novoNo->Dest = destino;
  novoNo->Peso = peso;
  novoNo->Prox = NULL;
  return novoNo;
}

Grafo* Grafo_Cria(int numVertices) {
  int i;
  Grafo *grafo;

  grafo = (Grafo*)malloc(sizeof(Grafo));
  grafo->NumVertices = numVertices;
  grafo->Lista = (NoLista**)malloc(numVertices * sizeof(NoLista*));
  // Inicializa a lista de adjacências.
  for(i = 0; i < numVertices; i++) {
    grafo->Lista[i] = NULL;
  }
  return grafo;
}

void Grafo_Destroi(Grafo *grafo) {
  int i;
  NoLista *aux;

  for(i = 0; i < grafo->NumVertices; i++) {
    while(grafo->Lista[i] != NULL) {
      aux = grafo->Lista[i];
      grafo->Lista[i] = grafo->Lista[i]->Prox;
      free(aux);
    }
  }
  free(grafo->Lista);
  free(grafo);
}

void Grafo_AdicionaAresta(Grafo *grafo, int origem, int destino, int peso) {
  NoLista *novoNo;

  novoNo = NoLista_Cria(destino, peso);
  novoNo->Prox = grafo->Lista[origem];
  grafo->Lista[origem] = novoNo;
}

void Grafo_UneArestas(Grafo *grafoOriginal, Grafo *grafo) {
  NoLista *no1, *no2;
  int i;

  for(i = 0; i < grafoOriginal->NumVertices; i++) {
    no1 = grafoOriginal->Lista[i];
    while(no1 != NULL) {
      no2 = grafoOriginal->Lista[no1->Dest];
      while(no2 != NULL) {
        if(no2->Dest != i) {  // Verifica se não é um caminho de ida e volta pro mesmo vértice (Ex: v1->v2->v1).
          Grafo_AdicionaAresta(grafo, i, no2->Dest, no1->Peso + no2->Peso);
        }
        no2 = no2->Prox;
      }
      no1 = no1->Prox;
    }
  }
}

int Dijkstra(Grafo *grafo) {
  int *distancias, *restantes, numRestantes, i, vertice, dist;
  char *restantesCompleto;
  NoLista *no;

  // Inicializa os vetores e variáveis.
  distancias = (int*)malloc(grafo->NumVertices * sizeof(int));
  restantes = (int*)malloc(grafo->NumVertices * sizeof(int));
  restantesCompleto = (char*)malloc(grafo->NumVertices * sizeof(char));
  numRestantes = grafo->NumVertices;
  for(i = 0; i < grafo->NumVertices; i++) {
    distancias[i] = INT_MAX;
    restantes[i] = i;
    restantesCompleto[i] = '1';
  }
  // Distância da origem.
  distancias[0] = 0;
  while(numRestantes > 0) {
    // Acha o indice do vértice de menor distância.
    vertice = 0;
    for(i = 1; i < numRestantes; i++) {
      if(distancias[restantes[i]] < distancias[restantes[vertice]]) {
        vertice = i;
      }
    }
    // Acha o vértice de menor distância.
    i = vertice;
    vertice = restantes[i];
    // Condição de contorno, se a distância atual do vértice for igual à INT_MAX, ele não está 
    // conectado ao subgrafo inicial.
    if(distancias[vertice] == INT_MAX) {
      break;
    }
    // Remove o vértice dos restantes.
    numRestantes--;
    restantes[i] = restantes[numRestantes];
    restantesCompleto[vertice] = '0';
    // Itera sobre os vizinhos do vértice atualizando as distâncias.
    no = grafo->Lista[vertice];
    while(no != NULL) {
      if(restantesCompleto[no->Dest] == '1') {
        dist = distancias[vertice] + no->Peso;
        if(dist < distancias[no->Dest]) {
          distancias[no->Dest] = dist;
        }
      }
      no = no->Prox;
    }
  }
  // Limpa recursos e retorna o comprimento do caminho.
  vertice = grafo->NumVertices - 1;
  dist = distancias[vertice];
  free(distancias);
  free(restantes);
  free(restantesCompleto);
  if(dist == INT_MAX) {
    return -1;
  }
  return dist;
}

int main() {
  Grafo *grafo, *grafoOriginal;
  int numVertices, numArestas, v1, v2, peso;

  // Lê e cria o grafo original.
  scanf("%d %d", &numVertices, &numArestas);
  grafoOriginal = Grafo_Cria(numVertices);
  while(numArestas) {
    scanf("%d %d %d", &v1, &v2, &peso);
    v1--;
    v2--;
    Grafo_AdicionaAresta(grafoOriginal, v1, v2, peso);
    Grafo_AdicionaAresta(grafoOriginal, v2, v1, peso);
    numArestas--;
  }
  // Cria o novo grafo, unindo pares de arestas consecutivas do grafo original.
  // Depois disso, pode destruir o grafo original.
  grafo = Grafo_Cria(numVertices);
  Grafo_UneArestas(grafoOriginal, grafo);
  Grafo_Destroi(grafoOriginal);
  // Executa o algoritmo de Dijkstra no grafo modificado.
  peso = Dijkstra(grafo);
  Grafo_Destroi(grafo);
  printf("%d\n", peso);
  return 0;
}