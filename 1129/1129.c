#include <stdio.h>

#define THRESHOLD (127)
#define NUM_ALTERNATIVAS (5)

void processaInstancia(unsigned int tamInstancia) {
    int cinza[NUM_ALTERNATIVAS], i, numRespostas;
    char resp;

    while(tamInstancia) {
        (void)scanf("%d %d %d %d %d", &cinza[0], &cinza[1], &cinza[2], &cinza[3], &cinza[4]);
        numRespostas = 0;
        for(i = 0; i < NUM_ALTERNATIVAS; i++) {
            if(cinza[i] <= THRESHOLD) {
                numRespostas++;
                resp = 'A' + i;
            }
        }
        if(numRespostas != 1) {
            resp = '*';
        }
        printf("%c\n", resp);
        tamInstancia--;
    }
}

int main(int argv, char** argc) {
    unsigned int tamInstancia;

    do {
        (void)scanf("%u", &tamInstancia);
        processaInstancia(tamInstancia);
    } while(tamInstancia > 0);
    return 0;
}