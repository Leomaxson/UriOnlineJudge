#include <stdio.h>
#include <stdlib.h>

typedef enum EEstadoVertice {
    Branco,
    Cinza,
    Preto,
} EstadoVertice;

typedef struct SGrafo {
    char ** Adj;
    unsigned int NumVertices;
    EstadoVertice * EstadosVertices;
} Grafo;

void Grafo_Cria(Grafo * g, unsigned int numVertices) {
    unsigned int i, j;

    g->NumVertices = numVertices;
    g->EstadosVertices = (EstadoVertice *)malloc(numVertices * sizeof(EstadoVertice));
    g->Adj = (char **)malloc(numVertices * sizeof(char *));
    for(i = 0; i < numVertices; i++) {
        g->Adj[i] = (char *)malloc(numVertices * sizeof(char));
        for(j = 0; j < numVertices; j++) {
            g->Adj[i][j] = '\0';
        }
    }
}

void Grafo_Destroi(Grafo * g) {
    unsigned int i;

    for(i = 0; i < g->NumVertices; i++) {
        free(g->Adj[i]);
    }
    free(g->Adj);
    free(g->EstadosVertices);
    g->NumVertices = 0;
}

void Grafo_InsereAresta(Grafo * g, unsigned int vertice1, unsigned int vertice2) {
    if(vertice1 < g->NumVertices && vertice2 < g->NumVertices) {
        g->Adj[vertice1][vertice2] = '\1';
    }
}

void Grafo_DFS(Grafo * g, unsigned int vertice) {
    unsigned int i;

    g->EstadosVertices[vertice] = Cinza;
    for(i = 0; i < g->NumVertices; i++) {
        if(g->Adj[vertice][i] == '\1') {
            if(g->EstadosVertices[i] == Branco) {
                Grafo_DFS(g, i);
            }
        }
    }
    g->EstadosVertices[vertice] = Preto;
}

unsigned int Grafo_Conectado(Grafo * g) {
    unsigned int i;

    // Zera o estado dos vértices.
    for(i = 0; i < g->NumVertices; i++) {
        g->EstadosVertices[i] = Branco;
    }
    // Chama a DFS a partir do vértice zero.
    Grafo_DFS(g, 0);
    // Verifica se algum vértice não foi alcançado.
    for(i = 0; i < g->NumVertices; i++) {
        if(g->EstadosVertices[i] == Branco) {
            return 0;
        }
    }
    return 1;
}

void Grafo_Transpor(Grafo * g) {
    unsigned int i, j;

    for(i = 0; i < g->NumVertices; i++) {
        for(j = i; j < g->NumVertices; j++) {
            if(g->Adj[i][j] == '\1') {
                if(g->Adj[j][i] == '\0') {
                    g->Adj[i][j] = '\0';
                    g->Adj[j][i] = '\1';
                }
            } else {
                if(g->Adj[j][i] == '\1') {
                    g->Adj[i][j] = '\1';
                    g->Adj[j][i] = '\0';
                }
            }
        }
    }
}

int main(int argv, char** argc) {
    unsigned int numVertices, numArestas, i, v1, v2, param;
    Grafo g;

    // Lê os tamanhos da primeira instância.
    scanf("%u %u", &numVertices, &numArestas);
    while(numVertices) {
      // Cria o grafo vazio.
        Grafo_Cria(&g, numVertices);
        // Lê as arestas da instância.
        for(i = 0; i < numArestas; i++) {
            scanf("%u %u %u", &v1, &v2, &param);
            v1--;
            v2--;
            Grafo_InsereAresta(&g, v1, v2);
            if(param == 2) {
                Grafo_InsereAresta(&g, v2, v1);
            }
        }
        // Verifica se o grafo é um componente fortemente conectado.
        param = Grafo_Conectado(&g);
        if(param) {
            Grafo_Transpor(&g);
            param += Grafo_Conectado(&g);
        }
        // Verifica se passou nos dois critérios.
        if(param >= 2) {
            (void)printf("1\n");
        } else {
            (void)printf("0\n");
        }
        // Destroi i grafo e lê os tamanhos da próxima instância.
        Grafo_Destroi(&g);
        scanf("%u %u", &numVertices, &numArestas);
    }
    return 0;
}