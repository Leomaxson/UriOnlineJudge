#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int num_termos, fib, fib_ant, fib_ant_ant;

    // Lê número de termos para calcular.
    (void)scanf("%u", &num_termos);
    switch(num_termos) {
        case 0:
            break;
        case 1:
            (void)printf("0\n");
            break;
        case 2:
            (void)printf("0 1\n");
            break;
        default:
            (void)printf("0 1");
            num_termos -= 2;
            fib_ant_ant = 0;
            fib_ant = 1;
            while(num_termos) {
                fib = fib_ant + fib_ant_ant;
                (void)printf(" %u", fib);
                num_termos--;
                fib_ant_ant = fib_ant;
                fib_ant = fib;
            }
            (void)printf("\n");
            break;
    }
    return 0;
}