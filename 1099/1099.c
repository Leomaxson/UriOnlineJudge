#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int instancias;
    int a, b, soma;

    (void)scanf("%u", &instancias);
    while(instancias) {
        (void)scanf("%d %d", &a, &b);
        if(a > b) {
            soma = b;
            b = a;
            a = soma;
        }
        if(a % 2 == 0) {
            a++;
        } else {
            a += 2;
        }
        soma = 0;
        while(a < b) {
            soma += a;
            a += 2;
        }
        (void)printf("%d\n", soma);
        instancias--;
    }
    return 0;
}