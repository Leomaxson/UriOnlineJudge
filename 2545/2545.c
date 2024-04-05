#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES (1000)

typedef enum EEstadoVertice {
    Branco,
    Cinza,
    Preto,
} EstadoVertice;

typedef struct SGrafo {
    char Adj[MAX_VERTICES][MAX_VERTICES];
    unsigned int NumVertices;
    EstadoVertice EstadoVertices[MAX_VERTICES];
    unsigned int NivelVertice[MAX_VERTICES];
} Grafo;

void Grafo_Cria(Grafo * g, unsigned int numVertices) {
    unsigned int i, j;

    g->NumVertices = numVertices;
    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++) {
            g->Adj[i][j] = '\0';
        }
    }
}

void Grafo_InsereAresta(Grafo * g, unsigned int vertice1, unsigned int vertice2) {
    if(vertice1 < g->NumVertices && vertice2 < g->NumVertices) {
        g->Adj[vertice1][vertice2] = '\1';
    }
}

unsigned int Grafo_VerificaCicloDFS(Grafo * g, unsigned int vertice, unsigned int nivel) {
    unsigned int i;

    // Ajuste inicial.
    g->EstadoVertices[vertice] = Cinza;
    if(g->NivelVertice[vertice] < nivel) {
        g->NivelVertice[vertice] = nivel;
    }
    // Percorre os adjacentes.
    for(i = 0; i < g->NumVertices; i++) {
        if(g->Adj[vertice][i] == '\1') {
            if(g->EstadoVertices[i] == Cinza) {
                g->EstadoVertices[vertice] = Branco;
                return 1;
            } else if(g->EstadoVertices[i] == Branco) {
                if(Grafo_VerificaCicloDFS(g, i, nivel + 1)) {
                    g->EstadoVertices[vertice] = Branco;
                    return 1;
                }
            }
        }
    }
    g->EstadoVertices[vertice] = Branco;
    return 0;
}

unsigned int Grafo_PossuiCiclo(Grafo * g) {
    unsigned int i;

    // Zera o estado dos vértices.
    for(i = 0; i < g->NumVertices; i++) {
        g->EstadoVertices[i] = Branco;
        g->NivelVertice[i] = 0;
    }
    // Chama a Grafo_VerificaCicloDFS a partir de cada vértice.
    for(i = 0; i < g->NumVertices; i++) {
        if(g->EstadoVertices[i] == Branco) {
            if(Grafo_VerificaCicloDFS(g, i, 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argv, char** argc) {
    unsigned int numVertices, numArestas, i, j, nivel;
    Grafo g;

    while(!feof(stdin)) {
      // Lê o tamanho da instância.
        (void)scanf("%u", &numVertices);
        if(feof(stdin)) {
            break;
        }
        // Cria o grafo vazio.
        Grafo_Cria(&g, numVertices);
        // Lê as arestas da instância.
        for(i = 0; i < numVertices; i++) {
            (void)scanf("%u", &numArestas);
            while(numArestas) {
                (void)scanf("%u", &j);
                j--;
                Grafo_InsereAresta(&g, i, j);
                numArestas--;
            }
        }
        // Verifica se o grafo tem ciclo (impossível compilar).
        if(Grafo_PossuiCiclo(&g)) {
            (void)printf("-1\n");
        } else {
          // Verifica a maior profundidade da árvore.
            nivel = 0;
            for(i = 0; i < g.NumVertices; i++) {
                if(g.NivelVertice[i] > nivel) {
                    nivel = g.NivelVertice[i];
                }
            }
            (void)printf("%u\n", nivel);
        }
    }
    return 0;
}