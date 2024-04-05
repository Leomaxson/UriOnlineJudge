/*
Problema: Soma de Fatoriais (URI-1161)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Leio os dois números e faço o cálculo em uma variáveis long long unsigned int para que caiba.
*/

#include <stdio.h>

int main() {
    unsigned int num;
    long long unsigned int fat1, fat2;

    while(1) {
        scanf("%u", &num);
        if(feof(stdin)) {
            break;
        }
        fat1 = 1;
        while(num > 1) {
            fat1 *= num;
            num--;
        }
        scanf("%u", &num);
        fat2 = 1;
        while(num > 1) {
            fat2 *= num;
            num--;
        }
        printf("%llu\n", fat1 + fat2);
    }
    return 0;
}