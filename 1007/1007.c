#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    int a, b, c, d, dif;

    (void)scanf("%d %d %d %d", &a, &b, &c, &d);
    dif = a * b - c * d;
    (void)printf("DIFERENCA = %d\n", dif);
    return 0;
}