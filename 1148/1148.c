/*
Problema: (A) Países em Guerra (SPC Mini Maratona 2)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Basta ajustar o grafo no momento da leitura para, quando encontrar uma aresta para um vértice
sendo que já tem a de volta, coloca o peso de ambas como zero.
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int distanciaMinima(int dist[], int incluidos[], int numVertices) {
    int minimo, indiceVertice, i;

    minimo = INT_MAX;
    for(i = 0; i < numVertices; i++) {
        if(incluidos[i] == 0 && dist[i] <= minimo) {
            minimo = dist[i];
            indiceVertice = i;
        }
    }
    return indiceVertice;
}

int dijkstra(int **grafo, int origem, int destino, int numVertices) {
    int *distancias, *incluidos, contagem, i, retorno;

    distancias = (int *)malloc(numVertices * sizeof(int));
    incluidos = (int *)malloc(numVertices * sizeof(int));
    // Inicializa os vetores de distâncias e incluídos.
    for(i = 0; i < numVertices; i++) {
        distancias[i] = INT_MAX;
        incluidos[i] = 0;
    }
    // Ajusta a distância da origem para zero.
    distancias[origem] = 0;
    // Acha o menor caminho para todos os vértices.
    for(contagem = 1; contagem < numVertices; contagem++) {
        int u = distanciaMinima(distancias, incluidos, numVertices);
        incluidos[u] = 1;
        for(i = 0; i < numVertices; i++) {
            if(!incluidos[i] && grafo[u][i] >= 0 && distancias[u] != INT_MAX
               && distancias[u] + grafo[u][i] < distancias[i]) {
                distancias[i] = distancias[u] + grafo[u][i];
            }
        }
    }
    retorno = distancias[destino];
    free(distancias);
    free(incluidos);
    return retorno;
}

int main(int argv, char** argc) {
    int ** grafo, numVertices, numArestas, i, j, peso, pesquisas;

    // Lê o tamanho da instância e verifica a condição de saída.
    while(scanf("%d %d", &numVertices, &numArestas) != EOF) {
        if(numVertices == 0 && numArestas == 0) {
            break;
        }
        // Cria o grafo.
        grafo = (int **)malloc(numVertices * sizeof(int *));
        for(i = 0; i < numVertices; i++) {
            grafo[i] = (int *)malloc(numVertices * sizeof(int));
        }
        // Preenche inicialmente todas as arestas como vazias.
        for(i = 0; i < numVertices; i++) {
            for(j = 0; j < numVertices; j++) {
                grafo[i][j] = -1;
            }
        }
        // Faz a leitura de todas as arestas.
        while(numArestas) {
            scanf("%d %d %d", &i, &j, &peso);
            i--;
            j--;
            if(grafo[j][i] != -1) {
                grafo[j][i] = 0;
                grafo[i][j] = 0;
            } else {
                grafo[i][j] = peso;
            }
            numArestas--;
        }
        // Realiza todas as pesquisas da instância.
        scanf("%d", &pesquisas);
        while(pesquisas) {
            scanf("%d %d", &i, &j);
            i--;
            j--;
            peso = dijkstra(grafo, i, j, numVertices);
            if(peso == INT_MAX) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", peso);
            }
            pesquisas--;
        }
        // Desaloca o grafo.
        for(i = 0; i < numVertices; i++) {
            free(grafo[i]);
        }
        free(grafo);
        printf("\n");
    }
    return 0;
}