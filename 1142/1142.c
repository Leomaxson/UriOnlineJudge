#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int num_linhas, a, b, c;

    // Lê o número de linhas para imprimir.
    (void)scanf("%u", &num_linhas);
    a = 1;
    b = 2;
    c = 3;
    while(num_linhas) {
        (void)printf("%u %u %u PUM\n", a, b, c);
        a += 4;
        b += 4;
        c += 4;
        num_linhas--;
    }
    return 0;
}