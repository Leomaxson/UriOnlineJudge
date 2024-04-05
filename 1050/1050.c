#include <stdio.h>
#include <string.h>

// Lista de DDDs
#define DDD_BRASILIA       (61)
#define DDD_SALVADOR       (71)
#define DDD_SAO_PAULO      (11)
#define DDD_RIO_DE_JANEIRO (21)
#define DDD_JUIZ_DE_FORA   (32)
#define DDD_CAMPINAS       (19)
#define DDD_VITORIA        (27)
#define DDD_BELO_HORIZONTE (31)

void printNomeCidade(int ddd) {
    switch(ddd) {
        case DDD_BRASILIA:
            (void)printf("Brasilia\n");
            break;
        case DDD_SALVADOR:
            (void)printf("Salvador\n");
            break;
        case DDD_SAO_PAULO:
            (void)printf("Sao Paulo\n");
            break;
        case DDD_RIO_DE_JANEIRO:
            (void)printf("Rio de Janeiro\n");
            break;
        case DDD_JUIZ_DE_FORA:
            (void)printf("Juiz de Fora\n");
            break;
        case DDD_CAMPINAS:
            (void)printf("Campinas\n");
            break;
        case DDD_VITORIA:
            (void)printf("Vitoria\n");
            break;
        case DDD_BELO_HORIZONTE:
            (void)printf("Belo Horizonte\n");
            break;
        default:
            (void)printf("DDD nao cadastrado\n");
            break;
    }
}

int main(int argv, char** argc) {
    int ddd;

    (void)scanf("%d", &ddd);
    printNomeCidade(ddd);
    return 0;
}