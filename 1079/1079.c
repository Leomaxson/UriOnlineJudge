#include <stdio.h>

#define PESO_A (2.0)
#define PESO_B (3.0)
#define PESO_C (5.0)
#define SOMA_PESOS (PESO_A + PESO_B + PESO_C)

int main(int argv, char** argc) {
    unsigned int numInstancias;
    double a, b, c, mediaPonderada;

    (void)scanf("%u", &numInstancias);
    while(numInstancias) {
        (void)scanf("%lf %lf %lf", &a, &b, &c);
        mediaPonderada = (a * PESO_A + b * PESO_B + c * PESO_C) / SOMA_PESOS;
        (void)printf("%.1lf\n", mediaPonderada);
        numInstancias--;
    }
    return 0;
}