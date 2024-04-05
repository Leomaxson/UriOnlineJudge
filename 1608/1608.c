#include <stdlib.h>
#include <stdio.h>

#define MAX_INGREDIENTES (100)

int main(int argv, char** argc) {
    int numInstancias, dinheiro, i, numIngredientesReceita, ingrediente, quantidade, maxBolos, numBolos;
    int numIngredientes, precosIngredientes[MAX_INGREDIENTES], numReceitas, precoReceita;

    // Lê o número de instâncias.
    (void)scanf("%d", &numInstancias);
    while(numInstancias) {
      // Lê os tamanhos da instância.
        (void)scanf("%d %d %d", &dinheiro, &numIngredientes, &numReceitas);
        // Lê os preços dos ingredientes.
        for(i = 0; i < numIngredientes; i++) {
            (void)scanf("%d", &precosIngredientes[i]);
        }
        // Lê as receitas de bolos, já calculando o custo de um bolo para cada uma e avaliando se ele é o máximo.
        maxBolos = 0;
        for(i = 0; i < numReceitas; i++) {
          // Calcula o preço da receita.
            precoReceita = 0;
            (void)scanf("%d", &numIngredientesReceita);
            while(numIngredientesReceita) {
                (void)scanf("%d %d", &ingrediente, &quantidade);
                precoReceita += precosIngredientes[ingrediente] * quantidade;
                numIngredientesReceita--;
            }
            // Avalia o número de bolos.
            numBolos = dinheiro / precoReceita;
            if(maxBolos < numBolos) {
                maxBolos = numBolos;
            }
        }
        // Imprime o máximo de bolos de um único tipo.
        (void)printf("%d\n", maxBolos);
        numInstancias--;
    }
    return 0;
}