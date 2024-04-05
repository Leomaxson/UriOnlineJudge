#include <stdio.h>

int main() {
    unsigned int num_termos, fib, fib_ant, fib_ant_ant;

    // Lê número de termos para calcular.
    scanf("%u", &num_termos);
    switch(num_termos) {
        case 0:
            break;
        case 1:
            printf("0\n");
            break;
        case 2:
            printf("0 1\n");
            break;
        default:
            printf("0 1");
            num_termos -= 2;
            fib_ant_ant = 0;
            fib_ant = 1;
            while(num_termos) {
                fib = fib_ant + fib_ant_ant;
                printf(" %u", fib);
                num_termos--;
                fib_ant_ant = fib_ant;
                fib_ant = fib;
            }
            printf("\n");
            break;
    }
    return 0;
}