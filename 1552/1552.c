#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct SAresta {
    int Origem;
    int Destino;
    double Peso;
} Aresta;

typedef struct SGrafo {
    int NumVertices;
    int NumArestas;
    Aresta * Arestas;
} Grafo;

void Grafo_Cria(Grafo *grafo, int numVertices, int numArestas) {
    grafo->NumVertices = numVertices;
    grafo->NumArestas = numArestas;
    grafo->Arestas = (Aresta *)malloc(numArestas * sizeof(Aresta));
}

void Grafo_Destroi(Grafo *grafo) {
    free(grafo->Arestas);
    grafo->NumArestas = 0;
    grafo->NumVertices = 0;
}

typedef struct SSubset {
    int Pai;
    int Rank;
} Subset;

int Subset_Find(Subset subsets[], int i) {
    if(subsets[i].Pai != i) {
        subsets[i].Pai = Subset_Find(subsets, subsets[i].Pai);
    }
    return subsets[i].Pai;
}

void Subset_Union(Subset subsets[], int x, int y) {
    int xroot = Subset_Find(subsets, x);
    int yroot = Subset_Find(subsets, y);

    if(subsets[xroot].Rank < subsets[yroot].Rank) {
        subsets[xroot].Pai = yroot;
    } else if(subsets[xroot].Rank > subsets[yroot].Rank) {
        subsets[yroot].Pai = xroot;
    } else {
        subsets[yroot].Pai = xroot;
        subsets[xroot].Rank++;
    }
}

int Compara(const void* a, const void* b) {
    return ((Aresta*)a)->Peso > ((Aresta*)b)->Peso;
}

double CalculaTamanhoAGM(Grafo *grafo) {
    int numVertices, e, i, v, x, y;
    Aresta *resultado, proximaAresta;
    Subset *subsets;
    double custoTotal;

    numVertices = grafo->NumVertices;
    e = 0;
    i = 0;
    resultado = (Aresta *)malloc(numVertices * sizeof(Aresta));
    qsort(grafo->Arestas, grafo->NumArestas, sizeof(Aresta), Compara);
    subsets = (Subset *)malloc(numVertices * sizeof(Subset));
    for(v = 0; v < numVertices; ++v) {
        subsets[v].Pai = v;
        subsets[v].Rank = 0;
    }
    while(e < numVertices - 1) {
        proximaAresta = grafo->Arestas[i++];
        x = Subset_Find(subsets, proximaAresta.Origem);
        y = Subset_Find(subsets, proximaAresta.Destino);
        if(x != y) {
            resultado[e++] = proximaAresta;
            Subset_Union(subsets, x, y);
        }
    }
    custoTotal = 0.0;
    for(i = 0; i < e; ++i) {
        custoTotal += resultado[i].Peso;
    }
    return custoTotal;
}

int main() {
    int numInstancias, numPessoas, i, j, *posX, *posY, xAux, yAux, indiceAresta;
    Grafo grafo;

    // Lê a quantidade de instâncias que deverão ser executadas.
    scanf("%d", &numInstancias);
    while(numInstancias) {
      // Lê as pessoas da instância e monta o grafo de distâncias.
        scanf("%d", &numPessoas);
        posX = (int *)malloc(numPessoas * sizeof(int));
        posY = (int *)malloc(numPessoas * sizeof(int));
        Grafo_Cria(&grafo, numPessoas, (numPessoas * (numPessoas - 1)) / 2);
        for(i = 0; i < numPessoas; i++) {
            scanf("%d %d", &posX[i], &posY[i]);
        }
        // Cálculo da matriz de distâncias.
        indiceAresta = 0;
        for(i = 0; i < numPessoas - 1; i++) {
            for(j = i + 1; j < numPessoas; j++) {
                xAux = posX[i] - posX[j];
                yAux = posY[i] - posY[j];
                xAux *= xAux;
                yAux *= yAux;
                grafo.Arestas[indiceAresta].Peso = sqrt((double)(xAux + yAux)) / 100.0;
                grafo.Arestas[indiceAresta].Origem = i;
                grafo.Arestas[indiceAresta].Destino = j;
                indiceAresta++;
            }
        }
        // Com a matriz de distâncias definida, calcula o tamanho da árvore geradora mínima para 
        // o grafo completo gerado.
        printf("%.2lf\n", CalculaTamanhoAGM(&grafo));
        free(posX);
        free(posY);
        Grafo_Destroi(&grafo);
        numInstancias--;
    }
    return 0;
}