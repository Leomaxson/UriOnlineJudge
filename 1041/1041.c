/*
Problema: Coordenadas de um Ponto (URI-1041)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Ler o ponto na entrada e tratar com ifs-elses cada um dos casos de quadrantes, eixos, ou origem.
*/

#include <stdio.h>

int main(int argv, char** argc) {
    double x, y;

    scanf("%lf", &x);
    scanf("%lf", &y);

    if(x > 0.0) {
        if(y > 0.0) {
            (void)printf("Q1\n");
        } else if(y < 0.0) {
            (void)printf("Q4\n");
        } else {
            (void)printf("Eixo X\n");
        }
    } else if(x < 0.0) {
        if(y > 0.0) {
            (void)printf("Q2\n");
        } else if(y < 0.0) {
            (void)printf("Q3\n");
        } else {
            (void)printf("Eixo X\n");
        }
    } else {
        if(y == 0.0) {
            (void)printf("Origem\n");
        } else {
            (void)printf("Eixo Y\n");
        }
    }
    return 0;
}