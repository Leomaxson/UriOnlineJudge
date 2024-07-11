#include <stdio.h>

int main(int argv, char **argc) {
    int numRodadas, valorJogador1, valorJogador2, pontosJogador1, pontosJogador2;

    (void)scanf("%d", &numRodadas);
    while(numRodadas > 0) {
        pontosJogador1 = 0;
        pontosJogador2 = 0;
        while(numRodadas > 0) {
            (void)scanf("%d %d", &valorJogador1, &valorJogador2);
            if(valorJogador1 > valorJogador2) {
                pontosJogador1++;
            }
            if(valorJogador2 > valorJogador1) {
                pontosJogador2++;
            }
            numRodadas--;
        }
        (void)printf("%d %d\n", pontosJogador1, pontosJogador2);
        (void)scanf("%d", &numRodadas);
    }
    return 0;
}
