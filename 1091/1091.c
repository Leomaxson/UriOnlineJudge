#include <stdio.h>

void imprimePos(int subtracaoX, int subtracaoY) {
    char str[4];

    if(subtracaoX == 0 || subtracaoY == 0) {
        (void)printf("divisa\n");
        return;
    }
    str[2] = '\n';
    str[3] = '\0';
    if(subtracaoY > 0) {
        str[0] = 'N';
    } else {
        str[0] = 'S';
    }
    if(subtracaoX > 0) {
        str[1] = 'E';
    } else {
        str[1] = 'O';
    }
    (void)printf(str);
}

void processaInstancia(unsigned int consultas) {
    int divisaX, divisaY, posX, posY;

    (void)scanf("%d %d", &divisaX, &divisaY);
    while(consultas) {
        (void)scanf("%d %d", &posX, &posY);
        imprimePos(posX - divisaX, posY - divisaY);
        consultas--;
    }
}

int main(int argv, char** argc) {
    unsigned int consultas;

    (void)scanf("%u", &consultas);
    while(consultas) {
        processaInstancia(consultas);
        (void)scanf("%u", &consultas);
    }
    return 0;
}