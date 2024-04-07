#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int fatorial, entrada;

    (void)scanf("%u", &entrada);
    fatorial = entrada;
    while(entrada > 1) {
        entrada--;
        fatorial *= entrada;
    }
    (void)printf("%u\n", fatorial);
    return 0;
}