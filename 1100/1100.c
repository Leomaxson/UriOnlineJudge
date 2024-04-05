/*
Problema: (J) Movimentos do Cavalo (SPC Mini Maratona 2)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Leio a posição e faço uma busca recursiva no tabuleiro para saber em quantos passos é possível chegar
no destino.
*/

#include <stdlib.h>
#include <stdio.h>

#define TAM_TABULEIRO (8)
#define TAM_STRING_MOVIMENTO (3)
#define TAM_FILA (TAM_TABULEIRO * TAM_TABULEIRO)

typedef struct SPosicao {
    int Coluna;
    int Linha;
} Posicao;

typedef struct SFila {
    Posicao Posicoes[TAM_FILA];
    unsigned int Inicio;
    unsigned int Fim;
} Fila;

void Fila_Cria(Fila * fila) {
    fila->Inicio = 0;
    fila->Fim = 0;
}

unsigned int Fila_Vazia(Fila * fila) {
    if(fila->Inicio == fila->Fim) {
        return 1;
    }
    return 0;
}

void Fila_Enfilera(Fila * fila, Posicao pos) {
    fila->Posicoes[fila->Fim] = pos;
    fila->Fim = (fila->Fim + 1) % TAM_FILA;
}

Posicao Fila_Desenfilera(Fila * fila) {
    Posicao pos;

    pos = fila->Posicoes[fila->Inicio];
    fila->Inicio = (fila->Inicio + 1) % TAM_FILA;
    return pos;
}

Posicao converteString(char stringPos[TAM_STRING_MOVIMENTO]) {
    Posicao p;

    p.Coluna = ((int)stringPos[0]) - 97;
    p.Linha = ((int)stringPos[1]) - 49;
    return p;
}

void encontraMovimentos(Posicao p, Posicao movimentos[TAM_TABULEIRO]) {
    movimentos[0].Coluna = p.Coluna + 2;
    movimentos[0].Linha = p.Linha + 1;
    movimentos[1].Coluna = p.Coluna + 2;
    movimentos[1].Linha = p.Linha - 1;
    movimentos[2].Coluna = p.Coluna - 2;
    movimentos[2].Linha = p.Linha + 1;
    movimentos[3].Coluna = p.Coluna - 2;
    movimentos[3].Linha = p.Linha - 1;
    movimentos[4].Coluna = p.Coluna + 1;
    movimentos[4].Linha = p.Linha + 2;
    movimentos[5].Coluna = p.Coluna + 1;
    movimentos[5].Linha = p.Linha - 2;
    movimentos[6].Coluna = p.Coluna - 1;
    movimentos[6].Linha = p.Linha + 2;
    movimentos[7].Coluna = p.Coluna - 1;
    movimentos[7].Linha = p.Linha - 2;
}

unsigned int posicaoValida(Posicao p) {
    if(p.Coluna >= 0 && p.Coluna < 8 && p.Linha >= 0 && p.Coluna < 8) {
        return 1;
    }
    return 0;
}

int main(int argv, char** argc) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    char inicio[TAM_STRING_MOVIMENTO], termino[TAM_STRING_MOVIMENTO];
    Posicao movimentos[TAM_TABULEIRO], posInicio, posTermino, pos, mov;
    Fila fila;
    unsigned int i, j;

    // Enquanto houver instâncias, executa o algoritmo.
    while(scanf("%s %s", inicio, termino) != EOF) {
        posInicio = converteString(inicio);
        posTermino = converteString(termino);
        // Trata separadamente o caso das posições de início e término serem as mesmas.
        if(posInicio.Linha == posTermino.Linha && posInicio.Coluna == posTermino.Coluna) {
            tabuleiro[posTermino.Linha][posTermino.Coluna] = 0;
        } else {
          // Zera o tabuleiro.
            for(i = 0; i < TAM_TABULEIRO; i++) {
                for(j = 0; j < TAM_TABULEIRO; j++) {
                    tabuleiro[i][j] = -1;
                }
            }
            // Zera a fila de posições, enfilera a posição inicial, ajusta a distância dela em zero.
            Fila_Cria(&fila);
            Fila_Enfilera(&fila, posInicio);
            tabuleiro[posInicio.Linha][posInicio.Coluna] = 0;
            // Coloca a posição final com um valor diferente para poder ser identificada.
            tabuleiro[posTermino.Linha][posTermino.Coluna] = -2;
            // Usa o j como flag para indicar quando a distância do destino já tiver sido encontrada.
            j = 1;
            // Enquanto houverem posições enfileiradas.
            while(!Fila_Vazia(&fila) && j) {
              // Desenfilera uma posição.
                pos = Fila_Desenfilera(&fila);
                // Encontra os movimentos a partir da posição.
                encontraMovimentos(pos, movimentos);
                // Para cada movimento...
                for(i = 0; i < TAM_TABULEIRO && j; i++) {
                    mov = movimentos[i];
                    // Verifica se é válido e se não foi percorrido.
                    if(posicaoValida(mov)) {
                        if(tabuleiro[mov.Linha][mov.Coluna] < 0) {
                          // Verifica se é a posição final.
                            if(tabuleiro[mov.Linha][mov.Coluna] == -2) {
                                j = 0;
                            }
                            // Enfilera a posição e marca a distância dela como a distância da posição + 1.
                            Fila_Enfilera(&fila, mov);
                            tabuleiro[mov.Linha][mov.Coluna] = tabuleiro[pos.Linha][pos.Coluna] + 1;
                        }
                    }
                }
            }
        }
        // Imprime a distância da posição final.
        printf("To get from %s to %s takes %d knight moves.\n", inicio, termino, tabuleiro[posTermino.Linha][posTermino.Coluna]);
    }
    return 0;
}