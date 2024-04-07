#include <stdio.h>

#define MIN (0.0)
#define MAX (10.0)

int main(int argv, char** argc) {
    unsigned int notasLidas;
    double nota, media;

    notasLidas = 0;
    media = 0.0;
    while(notasLidas < 2) {
        (void)scanf("%lf", &nota);
        if(nota < MIN || nota > MAX) {
            (void)printf("nota invalida\n");
        } else {
            notasLidas++;
            media += nota / 2.0;
        }
    }
    (void)printf("media = %.2lf\n", media);
    return 0;
}