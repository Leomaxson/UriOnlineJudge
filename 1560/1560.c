/*
Problema: (J) Energia dos Triângulos (SPC Mini Maratona Extra)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Para descobrir se o ponto está dentro do triângulo, cria-se um sistema de coordenadas
baricêntricas do ponto utilizando os três pontos do triângulo. Caso alguma das coordenadas do
ponto dentro do sistema seja negativa, ele está fora do triângulo. Com isso em mãos, basta somar
o número de pontos brancos que estão dentro dos triângulos para calcular a energia de cada
triângulo. A soma das energias de todos os triângulos é a resposta.
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
        // Lê todos os pontos.
        for(i = 0; i < numPretos; i++) {
            scanf("%d %d", &pretos[i].X, &pretos[i].Y);
        }
        for(i = 0; i < numBrancos; i++) {
            scanf("%d %d", &brancos[i].X, &brancos[i].Y);
        }
        // Prepara as variáveis para iniciar o processamento.
        energiaTotal = 0;
        // Itera sobre cada um dos conjuntos de três pontos pretos.
        for(i = 0; i < numPretos - 2; i++) {
            for(j = i + 1; j < numPretos - 1; j++) {
                for(k = j + 1; k < numPretos; k++) {
                    numPontosInternos = 0;
                    // Calcula os resultados intermediários.
                    op1 = pretos[j].Y - pretos[k].Y;
                    op2 = pretos[k].X - pretos[j].X;
                    op3 = pretos[i].X - pretos[k].X;
                    op4 = pretos[i].Y - pretos[k].Y;
                    divisor = (op1 * op3 + op2 * op4);
                    for(l = 0; l < numBrancos; l++) {
                        result = 0;
                        // Calcula os resultados intermediários.
                        op5 = brancos[l].X - pretos[k].X;
                        op6 = brancos[l].Y - pretos[k].Y;
                        // Verifica se o ponto é interno ou não.
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
                        // Se o ponto for interno, incrementa o número deles.
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