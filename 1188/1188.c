#include <stdio.h>

#define TAMANHO_MATRIZ 12
#define NUM_ELEMENTOS 30.0

int elementoUtil(int i, int j) {
    if(i <= 6) {
        return 0;
    } else if(j >= TAMANHO_MATRIZ - i && j < i) {
        return 1;
    }
    return 0;
}

int main(int argv, char **argc) {
    double resultado, valor;
    int i, j;
    char operacao;

    (void)scanf("%c", &operacao);
    resultado = 0.0;
    for(i = 0; i < TAMANHO_MATRIZ; i++) {
        for(j = 0; j < TAMANHO_MATRIZ; j++) {
            (void)scanf("%lf", &valor);
            if(elementoUtil(i, j)) {
                resultado += valor;
            }
        }
    }
    if(operacao == 'M') {
        resultado /= NUM_ELEMENTOS;
    }
    (void)printf("%.1lf\n", resultado);
    return 0;
}