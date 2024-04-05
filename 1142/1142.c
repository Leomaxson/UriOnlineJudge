#include <stdio.h>

int main() {
    unsigned int num_linhas, a, b, c;

    // Lê o número de linhas para imprimir.
    scanf("%u", &num_linhas);
    a = 1;
    b = 2;
    c = 3;
    while(num_linhas) {
        printf("%u %u %u PUM\n", a, b, c);
        a += 4;
        b += 4;
        c += 4;
        num_linhas--;
    }
    return 0;
}