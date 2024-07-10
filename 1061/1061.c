#include <stdio.h>
#include <string.h>
#include <time.h>

void scanTm(struct tm *data) {
    (void)scanf("%*s %d", &data->tm_mday);
    (void)scanf("%d : %d : %d", &data->tm_hour, &data->tm_min, &data->tm_sec);
}

struct tm subtractTm(struct tm tmInicio, struct tm tmFim) {
    time_t inicio = mktime(&tmInicio);
    time_t fim = mktime(&tmFim);
    double diferencaSegundos = difftime(fim, inicio);
    time_t tempo = (time_t)diferencaSegundos;
    struct tm *tmTempo = gmtime(&tempo);
    return *tmTempo;
}

int main(int argv, char **argc) {
    struct tm inicio, fim, tempo;

    // Zera variaveis.
    memset(&inicio, 0, sizeof(struct tm));
    memset(&fim, 0, sizeof(struct tm));
    // Lê entrada.
    scanTm(&inicio);
    scanTm(&fim);
    // Calcula diferenca.
    tempo = subtractTm(inicio, fim);
    // Imprime saida.
    (void)printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", tempo.tm_mday, tempo.tm_hour, tempo.tm_min, tempo.tm_sec);
    return 0;
}