#include <stdio.h>

int main() {
    int positivos = 0;
    double soma = 0.0;
    double valor;

    for(int i = 0; i < 6; i++) {
        scanf("%lf", &valor);
        if(valor > 0) {
            positivos++;
            soma += valor;
        }
    }
    double media = soma / positivos;
    printf("%d valores positivos\n%.1f\n", positivos, media);
    return 0;
}