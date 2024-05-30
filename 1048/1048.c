#include <stdio.h>

#define REAJUSTE_0 (0.15)
#define REAJUSTE_1 (0.12)
#define REAJUSTE_2 (0.10)
#define REAJUSTE_3 (0.07)
#define REAJUSTE_4 (0.04)

#define FAIXA_1 (400.0)
#define FAIXA_2 (800.0)
#define FAIXA_3 (1200.0)
#define FAIXA_4 (2000.0)

double getReajuste(double salario) {
    if(salario > FAIXA_4) {
        return REAJUSTE_4;
    } else if(salario > FAIXA_3) {
        return REAJUSTE_3;
    } else if(salario > FAIXA_2) {
        return REAJUSTE_2;
    } else if(salario > FAIXA_1) {
        return REAJUSTE_1;
    }
    return REAJUSTE_0;
}

int main(int argv, char **argc) {
    double salario, reajuste;

    (void)scanf("%lf", &salario);
    reajuste = getReajuste(salario);
    (void)printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%\n",
                 salario + salario * reajuste,
                 salario * reajuste,
                 reajuste * 100.0);
    return 0;
}