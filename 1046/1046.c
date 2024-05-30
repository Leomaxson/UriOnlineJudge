#include <stdio.h>

int main(int argv, char **argc) {
    int horaInicio, horaFim;

    (void)scanf("%d %d", &horaInicio, &horaFim);
    if(horaInicio >= horaFim) {
        horaFim += 24;
    }
    (void)printf("O JOGO DUROU %d HORA(S)\n", horaFim - horaInicio);
    return 0;
}