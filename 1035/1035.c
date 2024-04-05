#include <stdio.h>

int main(int argv, char** argc) {
    int a, b, c, d;

    (void)scanf("%d %d %d %d", &a, &b, &c, &d);
    if(
        (b > c) &&
        (d > a) &&
        (c + d > a + b) &&
        (c > 0) &&
        (d > 0) &&
        (a % 2 == 0)) {
        (void)printf("Valores aceitos\n");
    } else {
        (void)printf("Valores nao aceitos\n");
    }
    return 0;
}