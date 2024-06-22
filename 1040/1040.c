#include <stdio.h>

#define MINIMA_APROVACAO 7.0
#define MINIMA_EXAME 5.0

#define MENSAGEM_APROVACAO "Aluno aprovado."
#define MENSAGEM_REPROVACAO "Aluno reprovado."
#define MENSAGEM_EXAME "Aluno em exame."

#define NUM_NOTAS 4
const double PESOS[] = {
    2.0,
    3.0,
    4.0,
    1.0,
};

int main(int argv, char **argc) {
    double notas[NUM_NOTAS], notaExame, media, somaPesos;
    int i;
    char *msg;

    (void)scanf("%lf %lf %lf %lf", &notas[0], &notas[1], &notas[2], &notas[3]);
    media = somaPesos = 0.0;
    for(i = 0; i < NUM_NOTAS; i++) {
        media += notas[i] * PESOS[i];
        somaPesos += PESOS[i];
    }
    media /= somaPesos;
    notaExame = -1.0;
    if(media < MINIMA_EXAME) {
        msg = MENSAGEM_REPROVACAO;
    } else if(media >= MINIMA_APROVACAO) {
        msg = MENSAGEM_APROVACAO;
    } else {
        msg = MENSAGEM_EXAME;
        (void)scanf("%lf", &notaExame);
    }
    (void)printf("Media: %.1lf\n%s\n", media, msg);
    // Aluno em exame.
    if(notaExame >= 0) {
        media = (media + notaExame) / 2.0;
        msg = MENSAGEM_APROVACAO;
        if(media < MINIMA_EXAME) {
            msg = MENSAGEM_REPROVACAO;
        }
        (void)printf("Nota do exame: %.1lf\n%s\nMedia final: %.1lf\n", notaExame, msg, media);
    }
    return 0;
}