#include <stdio.h>

#define CONTINUAR (1)

int main(int argv, char** argc) {
    unsigned int golsInter, golsGremio, vitoriasInter, vitoriasGremio, empates;
    int novaInstancia;

    vitoriasInter = vitoriasGremio = empates = 0;
    do {
        (void)scanf("%u %u", &golsInter, &golsGremio);
        if(golsInter > golsGremio) {
            vitoriasInter++;
        } else if(golsInter < golsGremio) {
            vitoriasGremio++;
        } else {
            empates++;
        }
        (void)printf("Novo grenal (1-sim 2-nao)\n");
        (void)scanf("%d", &novaInstancia);
    } while(novaInstancia == CONTINUAR);
    (void)printf("%u grenais\nInter:%u\nGremio:%u\nEmpates:%u\n", 
                 vitoriasInter + vitoriasGremio + empates, 
                 vitoriasInter, 
                 vitoriasGremio, 
                 empates);
    if(vitoriasInter > vitoriasGremio) {
        (void)printf("Inter venceu mais\n");
    } else if(vitoriasInter < vitoriasGremio) {
        (void)printf("Gremio venceu mais\n");
    } else {
        (void)printf("Nao houve vencedor\n");
    }
    return 0;
}