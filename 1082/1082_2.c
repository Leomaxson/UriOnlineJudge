#include <stdio.h>
#include <math.h>

#define MAX_VERTICES 26
// #define MAX_PONTOS 500
// #define INFINITO 100000

void AgrupaComponentes(unsigned char vertices[MAX_VERTICES][MAX_VERTICES], unsigned char componentes[MAX_VERTICES], unsigned int componente1, unsigned int componente2) {
    unsigned int i;

    // Teste de sanidade com os parâmetros.
    if(componente1 == componente2 || componente1 >= MAX_VERTICES || componente2 >= MAX_VERTICES) {
        return;
    }
    // Marca todos os vértices do componente 2 no componente 1.
    for(i = 0; i < MAX_VERTICES; i++) {
        if(vertices[componente2][i]) {
            vertices[componente1][i] = 1;
        }
    }
    // Marca o componente 2 como "não utilizado".
    componentes[componente2] = 0;
}

void ImprimeComponente(unsigned char vertices[MAX_VERTICES][MAX_VERTICES], unsigned int componente) {
    char i;

    for(i = 0; i < MAX_VERTICES; i++) {
        if(vertices[componente][i]) {
            printf("%c,", i + 'a');
        }
    }
    printf("\n");
}

int main() {
    unsigned char vertices[MAX_VERTICES][MAX_VERTICES], componentes[MAX_VERTICES];
    unsigned int numCasosTeste, casoTeste, numVertices, numArestas, i, j, componente1, componente2, numComponentes;
    char vertice1, vertice2;

    // Lê a quantidade de instâncias que deverão ser executadas.
    scanf("%u", &numCasosTeste);
    casoTeste = 1;
    while(numCasosTeste) {
      // Inicializa as matrizes com zero.
        for(i = 0; i < MAX_VERTICES; i++) {
            componentes[i] = 0;
            for(j = 0; j < MAX_VERTICES; j++) {
                vertices[i][j] = 0;
            }
        }
        // Lê os tamanhos da instância.
        scanf("%u %u", &numVertices, &numArestas);
        // Inicializa a matriz de vértices e o vetor de componentes.
        for(i = 0; i < numVertices; i++) {
            componentes[i] = 1;
            vertices[i][i] = 1;
        }
        numComponentes = numVertices;
        // Lê cada uma das arestas da instância.
        for(i = 0; i < numArestas; i++) {
            scanf("%c %c", &vertice1, &vertice2);
            vertice1 -= 'a';
            vertice2 -= 'a';
            // Acha o componente do vértice 1.
            for(j = 0; j < numVertices; j++) {
                if(vertices[j][vertice1]) {
                    if(componentes[j]) {
                        componente1 = j;
                    }
                }
            }
            // Acha o componente do vértice 2.
            for(j = 0; j < numVertices; j++) {
                if(vertices[j][vertice2]) {
                    if(componentes[j]) {
                        componente2 = j;
                    }
                }
            }
            // Se são componentes diferentes, une eles.
            if(componente1 != componente2) {
                AgrupaComponentes(vertices, componentes, componente1, componente2);
                numComponentes--;
            }
        }
        // Imprime o resultado do caso teste encontrando cada componente, em ordem.
        printf("Case #%u:\n", casoTeste);
        for(j = 0; j < numVertices; j++) {
            for(i = 0; i < numVertices; i++) {
                if(vertices[i][j]) {
                    if(componentes[i]) {
                        ImprimeComponente(vertices, i);
                        componentes[i] = 0;
                    }
                }
            }
        }
        printf("%u connected components\n\n", numComponentes);
        numCasosTeste--;
        casoTeste++;
    }
    return 0;
}