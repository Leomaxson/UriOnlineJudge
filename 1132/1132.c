#include <stdio.h>

#define MULTIPLO 13

int main(int argv, char** argc) {
    int x, y, contagem;

    // Lê os valores de X e Y.
    scanf("%d", &x);
    scanf("%d", &y);
    // Define o menor como X.
    if(y < x) {
        contagem = x;
        x = y;
        y = contagem;
    }
    contagem = 0;
    while(x <= y) {
        if(x % MULTIPLO != 0) {
            contagem += x;
        }
        x++;
    }
    (void)printf("%d\n", contagem);
    return 0;
}