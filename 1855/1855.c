#include <stdio.h>

#define MAX_TAM 100

int main(int argv, char** argc) {
    char mapa[MAX_TAM][MAX_TAM], c;
    int numLinhas, numColunas, i, j;

    // Lê os tamanhos do mapa.
    (void)scanf("%d", &numColunas);
    (void)scanf("%d", &numLinhas);
    // Verifica condições de contorno.
    if(numLinhas == 0 || numColunas == 0) {
        (void)printf("!\n");
        return 0;
    }
    // Lê o mapa.
    for(i = 0; i < numLinhas; i++) {
        (void)scanf("%s", mapa[i]);
    }
    // Percorre o mapa até encontrar o tesouro, ou sair do mapa, ou entrar em loop.
    i = 0;
    j = 0;
    while(mapa[i][j] != '*') {
        c = mapa[i][j];
        mapa[i][j] = '#'; // Marca o vértice como já passado.
        switch(c) {
            case '>':  // Caminhar para a direita.
                j++;
                while(mapa[i][j] == '.' && j < numColunas) {
                    j++;
                }
                break;
            case '<':  // Caminhar para a esquerda.
                j--;
                while(mapa[i][j] == '.' && j >= 0) {
                    j--;
                }
                break;
            case 'v':  // Caminhar para baixo.
                i++;
                while(mapa[i][j] == '.' && i < numLinhas) {
                    i++;
                }
                break;
            case '^':  // Caminhar para cima.
                i--;
                while(mapa[i][j] == '.' && i >= 0) {
                    i--;
                }
                break;
            case '#':  // Loop encontrado.
                (void)printf("!\n");
                return 0;
            default:  // Caractere inválido.
                (void)printf("!\n");
                return 0;
        }
        if(i < 0 || j < 0 || i >= numLinhas || j >= numColunas) {  // Saiu do mapa.
            (void)printf("!\n");
            return 0;
        }
    }
    (void)printf("*\n");
    return 0;
}