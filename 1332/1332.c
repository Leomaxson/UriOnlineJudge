#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_MAX 5 + 1

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main(int argv, char** argc) {
    char string[TAMANHO_MAX];
    unsigned int instancias;
    unsigned char one;

    scanf("%u", &instancias);
    while(instancias > 0) {
        scanf("%s", string);
        if(string[3] == '\0') {  // 'one' ou 'two'
            one = 0;
            // Conta quantos caracteres da palavra 'one' estão corretos. Se dois ou mais, a 
            // palavra é 'one', caso contrário, a palavra é 'two'.
            if(string[0] == 'o') {
                one++;
            }
            if(string[1] == 'n') {
                one++;
            }
            if(string[2] == 'e') {
                one++;
            }
            if(one >= 2) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        } else {  // 'three'
            printf("3\n");
        }
        instancias--;
    }
    return 0;
}