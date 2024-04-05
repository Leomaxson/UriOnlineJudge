#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES (26)
#define min(a,b) (((a) < (b)) ? (a) : (b))

int NormalizaComponente(int componentes[MAX_VERTICES], int i) {
    if(componentes[i] != i) {
        componentes[i] = NormalizaComponente(componentes, componentes[i]);
    }
    return componentes[i];
}

int main(int argv, char** argc) {
    int numInstancias, instancia, numVertices, numArestas, componentes[MAX_VERTICES], lidos[MAX_VERTICES], numLidos, i, numComponentes, vertice;
    char v1, v2;

    // Lê o número de instâncias.
    scanf("%d\n", &numInstancias);
    instancia = 1;
    while(numInstancias) {
      // Lê os tamanhos da instância.
        scanf("%d %d", &numVertices, &numArestas);
        // Inicializa o vetor de componentes.
        for(i = 0; i < numVertices; i++) {
            componentes[i] = i;
            lidos[i] = 0;
        }
        // Lê todas as arestas, marcando os componentes conectados.
        while(numArestas) {
            scanf("\n%c %c", &v1, &v2);
            v1 -= 'a';
            v2 -= 'a';
            i = min(componentes[v1], componentes[v2]);
            componentes[v1] = i;
            componentes[v2] = i;
            numArestas--;
        }
        // Normaliza os componentes.
        for(i = 0; i < numVertices; i++) {
            componentes[i] = NormalizaComponente(componentes, i);
        }
        printf("Case #%d:\n", instancia);
        // Imprime os componentes.
        numLidos = 0;
        numComponentes = 0;
        while(numLidos < numVertices) {
          // Acha o primeiro vértice do primeiro componente faltando.
            for(i = 0; i < numVertices; i++) {
                if(lidos[i] == 0) {
                    vertice = componentes[i];
                    break;
                }
            }
            // Imprime os vértices do componente.
            for(i = 0; i < numVertices; i++) {
                if(componentes[i] == vertice) {
                    printf("%c,", i + 'a');
                    numLidos++;
                    lidos[i] = 1;
                }
            }
            printf("\n");
            numComponentes++;
        }
        printf("%u connected components\n\n", numComponentes);
        instancia++;
        numInstancias--;
    }
    return 0;
}