#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int num_jogadas, joao[10000], maria[10000], instancias, i, valor;

    instancias = 0;
    while(1) {
        (void)scanf("%u", &num_jogadas);
        if(num_jogadas == 0) {
            break;
        }
        joao[instancias] = 0;
        maria[instancias] = 0;
        do {
            (void)scanf("%u", &valor);
            if(valor) {
                joao[instancias]++;
            } else {
                maria[instancias]++;
            }
            num_jogadas--;
        } while(num_jogadas > 0);
        instancias++;
    }

    for(i = 0; i < instancias; i++) {
        (void)printf("Mary won %u times and John won %u times\n", maria[i], joao[i]);
    }
    return 0;
}