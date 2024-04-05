#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES (60)
#define MAX_ARESTAS (200)

// Define o tipo referente à uma aresta.
typedef struct SAresta {
    int Peso;
    int Vertice1;
    int Vertice2;
} Aresta;

int qsort_comparaArestas(const void* aresta1, const void* aresta2) {
    Aresta *a1, *a2;

    a1 = (Aresta*)aresta1;
    a2 = (Aresta*)aresta2;
    return a1->Peso - a2->Peso;
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
    int numVertices, numArestas, i, tamFloresta, pesoAGM, vertices[MAX_VERTICES], v1, v2, peso;
    Aresta arestas[MAX_ARESTAS];

    // Lê a quantidade de vértices e arestas da instância.
    scanf("%d %d", &numVertices, &numArestas);
    // Cria a lista de vértices.
    for(i = 0; i < numVertices; i++) {
        vertices[i] = i;
    }
    // Lê todas as arestas e adiciona na lista.
    for(i = 0; i < numArestas; i++) {
        scanf("%d %d %d", &v1, &v2, &peso);
        v1--;
        v2--;
        arestas[i].Vertice1 = v1;
        arestas[i].Vertice2 = v2;
        arestas[i].Peso = peso;
    }
    // Ordena a lista de arestas por peso preparando para executar o algoritmo de Kruskal.
    qsort(arestas, numArestas, sizeof(Aresta), qsort_comparaArestas);
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
    printf("%d\n", pesoAGM);
    return 0;
}