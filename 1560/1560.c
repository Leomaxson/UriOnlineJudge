/*
Problema: (J) Energia dos Tri�ngulos (SPC Mini Maratona Extra)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Para descobrir se o ponto est� dentro do tri�ngulo, cria-se um sistema de coordenadas
baric�ntricas do ponto utilizando os tr�s pontos do tri�ngulo. Caso alguma das coordenadas do
ponto dentro do sistema seja negativa, ele est� fora do tri�ngulo. Com isso em m�os, basta somar
o n�mero de pontos brancos que est�o dentro dos tri�ngulos para calcular a energia de cada
tri�ngulo. A soma das energias de todos os tri�ngulos � a resposta.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PONTOS (100)

typedef struct SPonto {
    int X;
    int Y;
} Ponto;

int main(int argv, char** argc) {
    unsigned int numPretos, numBrancos, i, j, k, l, result;
    Ponto pretos[MAX_PONTOS], brancos[MAX_PONTOS];
    unsigned long long energiaTotal, numPontosInternos;
    int divisor, op1, op2, op3, op4, op5, op6;
    double alfa, beta, gama;


    scanf("%u %u", &numPretos, &numBrancos);
    while(!feof(stdin)) {
        // L� todos os pontos.
        for(i = 0; i < numPretos; i++) {
            scanf("%d %d", &pretos[i].X, &pretos[i].Y);
        }
        for(i = 0; i < numBrancos; i++) {
            scanf("%d %d", &brancos[i].X, &brancos[i].Y);
        }
        // Prepara as vari�veis para iniciar o processamento.
        energiaTotal = 0;
        // Itera sobre cada um dos conjuntos de tr�s pontos pretos.
        for(i = 0; i < numPretos - 2; i++) {
            for(j = i + 1; j < numPretos - 1; j++) {
                for(k = j + 1; k < numPretos; k++) {
                    numPontosInternos = 0;
                    // Calcula os resultados intermedi�rios.
                    op1 = pretos[j].Y - pretos[k].Y;
                    op2 = pretos[k].X - pretos[j].X;
                    op3 = pretos[i].X - pretos[k].X;
                    op4 = pretos[i].Y - pretos[k].Y;
                    divisor = (op1 * op3 + op2 * op4);
                    for(l = 0; l < numBrancos; l++) {
                        result = 0;
                        // Calcula os resultados intermedi�rios.
                        op5 = brancos[l].X - pretos[k].X;
                        op6 = brancos[l].Y - pretos[k].Y;
                        // Verifica se o ponto � interno ou n�o.
                        alfa = (double)(op1 * op5 + op2 * op6) / (double)divisor;
                        if(alfa > 0) {
                            beta = (double)((-op4) * op5 + op3 * op6) / (double)divisor;
                            if(beta > 0) {
                                gama = 1.0 - alfa - beta;
                                if(gama > 0) {
                                    result = 1;
                                }
                            }
                        }
                        // Se o ponto for interno, incrementa o n�mero deles.
                        if(result) {
                            numPontosInternos++;
                        }
                    }
                    energiaTotal += numPontosInternos * numPontosInternos;
                }
            }
        }
        printf("%llu\n", energiaTotal);
        if(feof(stdin)) {
            break;
        }
        scanf("%u", &numPretos);
        if(feof(stdin)) {
            break;
        }
        scanf("%u", &numBrancos);
        if(feof(stdin)) {
            break;
        }
    }
    return 0;
}