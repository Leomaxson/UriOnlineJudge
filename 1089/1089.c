#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10000

int main(int argv, char** argc) {
    int amostras[MAX_TAM], diferenca, diferencaAnterior, diferencaLoop;
    unsigned int numAmostras, i, numPicos;

    // Lê o tamanho da primeira instância.
    scanf("%u", &numAmostras);
    while(numAmostras) {
      // Lê as amostras.
        for(i = 0; i < numAmostras; i++) {
            scanf("%d", &amostras[i]);
        }
        // Prepara a execução.
        numPicos = 0;
        diferencaLoop = amostras[0] - amostras[numAmostras - 1];
        diferencaAnterior = diferencaLoop;
        // Calcula o número de vales a partir das diferenças.
        for(i = 1; i < numAmostras; i++) {
            diferenca = amostras[i] - amostras[i - 1];
            if(diferenca * diferencaAnterior < 0) {  // Sinal diferente. Mudou o sentido.
                numPicos++;
            }
            diferencaAnterior = diferenca;
        }
        // Verifica se tem vale no loop.
        if(diferencaLoop * diferenca < 0) {
            numPicos++;
        }
        // Imprime a resposta.
        (void)printf("%u\n", numPicos);
        // Lê o tamanho da próxima instância.
        scanf("%u", &numAmostras);
    }
    return 0;
}