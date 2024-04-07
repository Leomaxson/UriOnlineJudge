#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int numInstancias, b;
    int a, soma;

    (void)scanf("%u", &numInstancias);
    while(numInstancias) {
        (void)scanf("%d %u", &a, &b);
        soma = 0;
        if(a % 2 == 0) {
            a++;
        }
        while(b) {
            soma += a;
            a += 2;
            b--;
        }
        (void)printf("%d\n", soma);
        numInstancias--;
    }
    return 0;
}