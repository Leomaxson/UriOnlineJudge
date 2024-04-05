#include <stdio.h>
#include <stdlib.h>

#define MAX_PEDIDOS (20)
#define MAX_PIZZAS (30)

#define max(a,b) (((a) > (b)) ? (a) : (b))

int problemaMochila(int capacidade, int pesos[], int lucros[], int numItens) {
    int i, w, mochila[MAX_PEDIDOS + 1][MAX_PIZZAS + 1];

    // Monta a tabela de recorrências.
    for(i = 0; i <= numItens; i++) {
        for(w = 0; w <= capacidade; w++) {
            if(i == 0 || w == 0) {
                mochila[i][w] = 0;
            } else if(pesos[i - 1] <= w) {
                mochila[i][w] = max(
                    lucros[i - 1] + mochila[i - 1][w - pesos[i - 1]],
                    mochila[i - 1][w]);
            } else {
                mochila[i][w] = mochila[i - 1][w];
            }
        }
    }
    // Libera o espaço e retorna.
    return mochila[numItens][capacidade];
}

int main(int argv, char** argc) {
    int numPedidos, maxPizzas, numPizzas[MAX_PEDIDOS], tempoEntrega[MAX_PEDIDOS], i;

    // Lê o tamanho da primeira instância.
    scanf("%d", &numPedidos);
    while(numPedidos > 0) {
      // Lê a instância.
        scanf("%d", &maxPizzas);
        for(i = 0; i < numPedidos; i++) {
            scanf("%d %d", &tempoEntrega[i], &numPizzas[i]);
        }
        // Calcula o problema da mochila 0-1 para os pedidos.
        i = problemaMochila(maxPizzas, numPizzas, tempoEntrega, numPedidos);
        (void)printf("%d min.\n", i);
        // Lê o tamanho da próxima instância.
        scanf("%d", &numPedidos);
    }
    return 0;
}