#include <stdio.h>

#define MAX_FAIXA_1 2000.0
#define MAX_FAIXA_2 3000.0
#define MAX_FAIXA_3 4500.0

#define TAXA_FAIXA_2 0.08
#define TAXA_FAIXA_3 0.18
#define TAXA_FAIXA_4 0.28

#define PRECO_FAIXA_2 ((MAX_FAIXA_2 - MAX_FAIXA_1) * TAXA_FAIXA_2)
#define PRECO_FAIXA_3 ((MAX_FAIXA_3 - MAX_FAIXA_2) * TAXA_FAIXA_3)

int main(int argv, char **argc) {
    double salario, imposto;

    (void)scanf("%lf", &salario);
    // Verifica se é isento.
    if(salario <= MAX_FAIXA_1) {
        (void)printf("Isento\n");
        return 0;
    }
    // Calcula imposto.
    if(salario > MAX_FAIXA_3) {
        salario -= MAX_FAIXA_3;
        imposto = PRECO_FAIXA_2 + PRECO_FAIXA_3 + salario * TAXA_FAIXA_4;
    } else if(salario > MAX_FAIXA_2) {
        salario -= MAX_FAIXA_2;
        imposto = PRECO_FAIXA_2 + salario * TAXA_FAIXA_3;
    } else {
        salario -= MAX_FAIXA_1;
        imposto = salario * TAXA_FAIXA_2;
    }
    (void)printf("R$ %.2lf\n", imposto);
    return 0;
}