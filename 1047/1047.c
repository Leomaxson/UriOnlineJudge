#include <stdio.h>

#define MINUTOS_DIA (24 * 60)

int leTempoEmMinutos(void) {
    int horas, minutos;
    (void)scanf("%d %d", &horas, &minutos);
    return horas * 60 + minutos;
}

int main(int argv, char **argc) {
    int tempoInicio, tempoFim, duracao;

    tempoInicio = leTempoEmMinutos();
    tempoFim = leTempoEmMinutos();
    if(tempoInicio >= tempoFim) {
        tempoFim += MINUTOS_DIA;
    }
    duracao = tempoFim - tempoInicio;
    (void)printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao / 60, duracao % 60);
    return 0;
}