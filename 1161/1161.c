/*
Problema: Soma de Fatoriais (URI-1161)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Leio os dois n�meros e fa�o o c�lculo em uma vari�veis long long unsigned int para que caiba.
*/

#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int num;
    long long unsigned int fat1, fat2;

    while(1) {
        (void)scanf("%u", &num);
        if(feof(stdin)) {
            break;
        }
        fat1 = 1;
        while(num > 1) {
            fat1 *= num;
            num--;
        }
        (void)scanf("%u", &num);
        fat2 = 1;
        while(num > 1) {
            fat2 *= num;
            num--;
        }
        (void)printf("%llu\n", fat1 + fat2);
    }
    return 0;
}