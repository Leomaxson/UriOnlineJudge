#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM (100000)

typedef struct STupla {
    int X;
    int Y;
} Tupla;

int main() {
    int x, y, n, i, limite, instancia;
    Tupla * colmeia;

    // Aloca o vetor para guardar os valores e inicializa os valores.
    colmeia = (Tupla *)malloc(MAX_NUM * sizeof(Tupla));
    limite = 0;
    x = 0;
    y = 0;
    n = 0;
    // Adiciona o primeiro favo para manter o padrão.
    colmeia[limite].X = x;
    colmeia[limite].Y = y;
    // Itera sobre cada um dos seis trechos para preencher o vetor.
    while(1) {
        ++limite;
        ++y;
        ++n;
        colmeia[limite].X = x;
        colmeia[limite].Y = y;

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n - 1; ++i) {
            --x;
            ++y;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n; ++i) {
            --x;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n; ++i) {
            --y;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n; ++i) {
            ++x;
            --y;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n; ++i) {
            ++x;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
        for(i = 0; i < n; ++i) {
            ++y;
            ++limite;
            colmeia[limite].X = x;
            colmeia[limite].Y = y;
            if(limite >= MAX_NUM) break;
        }

        if(limite >= MAX_NUM) break;
    }
    // Faz a leitura das instâncias e escreve a resposta acessando o vetor na posição.
    while(scanf("%d", &instancia) != EOF) {
        instancia--;
        printf("%d %d\n", colmeia[instancia].X, colmeia[instancia].Y);
    }
    free(colmeia);
    return 0;
}
