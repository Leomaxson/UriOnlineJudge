#include <stdlib.h>
#include <stdio.h>

#define MAX_INGREDIENTES (100)

int main() {
    int numInstancias, dinheiro, i, numIngredientesReceita, ingrediente, quantidade, maxBolos, numBolos;
    int numIngredientes, precosIngredientes[MAX_INGREDIENTES], numReceitas, precoReceita;

    // L� o n�mero de inst�ncias.
    scanf("%d", &numInstancias);
    while(numInstancias) {
      // L� os tamanhos da inst�ncia.
        scanf("%d %d %d", &dinheiro, &numIngredientes, &numReceitas);
        // L� os pre�os dos ingredientes.
        for(i = 0; i < numIngredientes; i++) {
            scanf("%d", &precosIngredientes[i]);
        }
        // L� as receitas de bolos, j� calculando o custo de um bolo para cada uma e avaliando se ele � o m�ximo.
        maxBolos = 0;
        for(i = 0; i < numReceitas; i++) {
          // Calcula o pre�o da receita.
            precoReceita = 0;
            scanf("%d", &numIngredientesReceita);
            while(numIngredientesReceita) {
                scanf("%d %d", &ingrediente, &quantidade);
                precoReceita += precosIngredientes[ingrediente] * quantidade;
                numIngredientesReceita--;
            }
            // Avalia o n�mero de bolos.
            numBolos = dinheiro / precoReceita;
            if(maxBolos < numBolos) {
                maxBolos = numBolos;
            }
        }
        // Imprime o m�ximo de bolos de um �nico tipo.
        printf("%d\n", maxBolos);
        numInstancias--;
    }
    return 0;
}