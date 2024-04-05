#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10000

int main(int argv, char** argc) {
    int amostras[MAX_TAM], diferenca, diferencaAnterior, diferencaLoop;
    unsigned int numAmostras, i, numPicos;

    // L� o tamanho da primeira inst�ncia.
    scanf("%u", &numAmostras);
    while(numAmostras) {
      // L� as amostras.
        for(i = 0; i < numAmostras; i++) {
            scanf("%d", &amostras[i]);
        }
        // Prepara a execu��o.
        numPicos = 0;
        diferencaLoop = amostras[0] - amostras[numAmostras - 1];
        diferencaAnterior = diferencaLoop;
        // Calcula o n�mero de vales a partir das diferen�as.
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
        // L� o tamanho da pr�xima inst�ncia.
        scanf("%u", &numAmostras);
    }
    return 0;
}