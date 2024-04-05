/*
Existem duas verificações que indicam a viabilidade de um movimento. A primeira é em relação às
posições com zero. A segunda é em relação à união de blocos.
No caso das posições com zero, elas permitem que se mova em duas (zero no canto), três (zero na
borda), ou quatro direções (zero central).
No caso dos blocos iguais lado-a-lado, cada conjunto permite que se mova em um eixo.
*/

#include <stdlib.h>
#include <stdio.h>

#define TAM_QUADRO (4)
#define STR_DOWN  "DOWN"
#define STR_LEFT  "LEFT"
#define STR_RIGHT "RIGHT"
#define STR_UP    "UP"
#define STR_NONE  "NONE"

int main(int argv, char** argc) {
    unsigned int quadro[TAM_QUADRO][TAM_QUADRO], numInstancias, down, left, right, up, i, j, flag;
    char *str[TAM_QUADRO];

    scanf("%u", &numInstancias);
    while(numInstancias) {
      // Lê a instância.
        scanf("%u %u %u %u", &quadro[0][0], &quadro[0][1], &quadro[0][2], &quadro[0][3]);
        scanf("%u %u %u %u", &quadro[1][0], &quadro[1][1], &quadro[1][2], &quadro[1][3]);
        scanf("%u %u %u %u", &quadro[2][0], &quadro[2][1], &quadro[2][2], &quadro[2][3]);
        scanf("%u %u %u %u", &quadro[3][0], &quadro[3][1], &quadro[3][2], &quadro[3][3]);
        // Zera os flags.
        down = 0;
        left = 0;
        right = 0;
        up = 0;
        // Verifica condição de término do número 2048.
        flag = 1;
        for(i = 0; i < TAM_QUADRO && flag; i++) {
            for(j = 0; j < TAM_QUADRO && flag; j++) {
                if(quadro[i][j] == 2048) {
                    flag = 0;
                }
            }
        }
        if(flag) {
          // Verifica se é possível mover para a direita e para a esquerda com redução.
            for(i = 0; i < TAM_QUADRO && !left; i++) {
                for(j = 1; j < TAM_QUADRO && !left; j++) {
                    if(quadro[i][j] != 0 && quadro[i][j] == quadro[i][j - 1]) {
                        left = 1;
                        right = 1;
                    }
                }
            }
            // Verifica se é possível mover para cima e para baixo com redução.
            for(j = 0; j < TAM_QUADRO && !up; j++) {
                for(i = 1; i < TAM_QUADRO && !up; i++) {
                    if(quadro[i][j] != 0 && quadro[i][j] == quadro[i - 1][j]) {
                        up = 1;
                        down = 1;
                    }
                }
            }
            // Se ainda não for possível, verifica se pode mover para a direita com zeros.
            if(!right) {
                for(i = 0; i < TAM_QUADRO && !right; i++) {
                    flag = 0;
                    for(j = 0; j < TAM_QUADRO && !right; j++) {
                        if(quadro[i][j] == 0) {
                            if(flag) {
                                right = 1;
                            }
                        } else {
                            flag = 1;
                        }
                    }
                }
            }
            // Se ainda não for possível, verifica se pode mover para a esquerda com zeros.
            if(!left) {
                for(i = 0; i < TAM_QUADRO && !left; i++) {
                    flag = 0;
                    for(j = 0; j < TAM_QUADRO && !left; j++) {
                        if(quadro[i][j] == 0) {
                            flag = 1;
                        } else {
                            if(flag) {
                                left = 1;
                            }
                        }
                    }
                }
            }
            // Se ainda não for possível, verifica se pode mover para baixo com zeros.
            if(!down) {
                for(j = 0; j < TAM_QUADRO && !down; j++) {
                    flag = 0;
                    for(i = 0; i < TAM_QUADRO && !down; i++) {
                        if(quadro[i][j] == 0) {
                            if(flag) {
                                down = 1;
                            }
                        } else {
                            flag = 1;
                        }
                    }
                }
            }
            // Se ainda não for possível, verifica se pode mover para cima com zeros.
            if(!up) {
                for(j = 0; j < TAM_QUADRO && !up; j++) {
                    flag = 0;
                    for(i = 0; i < TAM_QUADRO && !up; i++) {
                        if(quadro[i][j] == 0) {
                            flag = 1;
                        } else {
                            if(flag) {
                                up = 1;
                            }
                        }
                    }
                }
            }
        }
        // Imprime de acordo com os resultados.
        str[0] = NULL;
        str[1] = NULL;
        str[2] = NULL;
        str[3] = NULL;
        i = 0;
        if(down) {
            str[i] = STR_DOWN;
            i++;
        }
        if(left) {
            str[i] = STR_LEFT;
            i++;
        }
        if(right) {
            str[i] = STR_RIGHT;
            i++;
        }
        if(up) {
            str[i] = STR_UP;
            i++;
        }
        if(i == 0) { // Nenhum movimento válido.
            str[i] = STR_NONE;
            i++;
        }
        switch(i) {
            case 1:
                printf("%s\n", str[0]);
                break;
            case 2:
                printf("%s %s\n", str[0], str[1]);
                break;
            case 3:
                printf("%s %s %s\n", str[0], str[1], str[2]);
                break;
            case 4:
                printf("%s %s %s %s\n", str[0], str[1], str[2], str[3]);
                break;
        }
        numInstancias--;
    }
    return 0;
}