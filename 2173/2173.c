#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES (100)

typedef unsigned int uint;

uint achaVerticeMenorDistancia(int distanciasVertices[],
                               char verticesIncluidos[],
                               int numVertices) {
    int distanciaMinima, verticeMinimo, i;

    distanciaMinima = INT_MAX;
    for(i = 0; i < numVertices; i++) {
        if(verticesIncluidos[i] == 'N' && distanciasVertices[i] < distanciaMinima) {
            distanciaMinima = distanciasVertices[i];
            verticeMinimo = i;
        }
    }
    return verticeMinimo;
}

int calculaPesoAGM(int **grafo, int numVertices) {
    int *distanciasVertices, i, u, v, distanciaTotal;
    char *verticesIncluidos;

    // Inicializa as distâncias como infinitas menos o vértice zero. Coloca a distância dele como 
    // zero para começar a partir dele.
    distanciasVertices = (int *)malloc(numVertices * sizeof(int));
    verticesIncluidos = (char *)malloc(numVertices * sizeof(char));
    distanciaTotal = 0;
    for(i = 0; i < numVertices; i++) {
        distanciasVertices[i] = INT_MAX;
        verticesIncluidos[i] = 'N';
    }
    distanciasVertices[0] = 0;
    // Itera no número de vértices pois a AGM terá todos.
    for(i = 0; i < numVertices; i++) {
      // Acha o vértice de menor distância, marca ele como incluído e soma a distância dele ao total 
      // da AGM.
        u = achaVerticeMenorDistancia(distanciasVertices, verticesIncluidos, numVertices);
        verticesIncluidos[u] = 'S';
        distanciaTotal += distanciasVertices[u];
        // Atualiza as distâncias dos vértices que ainda não foram incluídos para este.
        for(v = 0; v < numVertices; v++) {
            if(grafo[u][v] && verticesIncluidos[v] == 'N' && grafo[u][v] < distanciasVertices[v]) {
                distanciasVertices[v] = grafo[u][v];
            }
        }
    }
    free(distanciasVertices);
    free(verticesIncluidos);
    return distanciaTotal;
}

int main(int argv, char** argc) {
    int **grafo, numVertices, numArestas, v1, v2, peso, pesoAGMaxima, i, j;

    // Lê a instância e trata o caso de saída.
    while(scanf("%d %d", &numVertices, &numArestas) != EOF) {
        if(numVertices == 0 && numArestas == 0) {
            break;
        }
        // Cria o grafo.
        grafo = (int **)malloc(numVertices * sizeof(int *));
        for(i = 0; i < numVertices; i++) {
            grafo[i] = (int *)malloc(numVertices * sizeof(int));
        }
        // Inicializa as arestas como zero.
        for(v1 = 0; v1 < numVertices; v1++) {
            for(v2 = 0; v2 < numVertices; v2++) {
                grafo[v1][v2] = 0;
            }
        }
        // Lê todas as arestas do grafo.
        while(numArestas) {
            (void)scanf("%d %d %d", &v1, &v2, &peso);
            // Ajusta a numeração do vértice para [0..numVertices - 1] ao invés de [1..numVertices].
            v1--;
            v2--;
            grafo[v1][v2] = peso;
            grafo[v2][v1] = peso;
            numArestas--;
        }
        // Executa o algoritmo de Prim sobre o grafo para encontrar o peso da AGM.
        peso = calculaPesoAGM(grafo, numVertices);
        // Multiplica todos os vértices por -1 e executa novamente Prim para achar o peso da Árvore 
        // Geradora Máxima.
        for(i = 0; i < numVertices; i++) {
            for(j = 0; j < numVertices; j++) {
                grafo[i][j] *= -1;
            }
        }
        pesoAGMaxima = calculaPesoAGM(grafo, numVertices);
        // Desaloca o grafo.
        for(i = 0; i < numVertices; i++) {
            free(grafo[i]);
        }
        free(grafo);
        // Imprime o resultado.
        (void)printf("%d\n", -pesoAGMaxima - peso);
    }
    return 0;
}