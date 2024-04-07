#include <stdio.h>

int main(int argv, char** argc) {
    int idade, soma, count;

    soma = count = 0;
    (void)scanf("%d", &idade);
    while(idade >= 0) {
        count++;
        soma += idade;
        (void)scanf("%d", &idade);
    }
    (void)printf("%.2lf\n", (double)soma / (double)count);
    return 0;
}