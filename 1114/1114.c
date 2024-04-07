#include <stdio.h>

#define SENHA (2002)

int main(int argv, char** argc) {
    int entrada;

    while(1) {
        (void)scanf("%d", &entrada);
        if(entrada == SENHA) {
            (void)printf("Acesso Permitido\n");
            break;
        }
        (void)printf("Senha Invalida\n");
    }
    return 0;
}