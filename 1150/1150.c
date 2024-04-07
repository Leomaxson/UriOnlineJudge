#include <stdio.h>

int main(int argv, char** argc) {
    int x, z, i, soma;

    (void)scanf("%d", &x);
    do {
        (void)scanf("%d", &z);
    } while(z <= x);
    soma = 0;
    for(i = x; soma < z; i++) {
        soma += i;
    }
    (void)printf("%d\n", i - x);
    return 0;
}