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

    (void)scanf("%u", &instancias);
    while(instancias > 0) {
        (void)scanf("%s", string);
        if(string[3] == '\0') {  // 'one' ou 'two'
            one = 0;
            // Conta quantos caracteres da palavra 'one' est�o corretos. Se dois ou mais, a 
            // palavra � 'one', caso contr�rio, a palavra � 'two'.
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
                (void)printf("1\n");
            } else {
                (void)printf("2\n");
            }
        } else {  // 'three'
            (void)printf("3\n");
        }
        instancias--;
    }
    return 0;
}