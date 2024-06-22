#include <stdio.h>
#include <string.h>
#include <time.h>

void scanTm(struct tm *data) {
    (void)scanf("%*s %d", &data->tm_mday);
    (void)scanf("%d : %d : %d", &data->tm_hour, &data->tm_min, &data->tm_sec);
}

int main(int argv, char **argc) {
    struct tm inicio, fim;

    // Zera variaveis.
    memset(&inicio, 0, sizeof(struct tm));
    memset(&fim, 0, sizeof(struct tm));
    // Lê entrada.
    scanTm(&inicio);
    scanTm(&fim);

    return 0;
}