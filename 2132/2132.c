#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAM_STRING (60)

int main(int argv, char** argc) {
    char string[TAM_STRING + 1];
    long long int resp, test, tam, i;

    test = 0;
    while(!feof(stdin)) {
        string[0] = '\0';
        (void)scanf("%s", string);
        if(string[0] == '\0') {
            break;
        }
        tam = 0;
        while(string[tam] != '\0') {
            tam++;
        }
        resp = 0;
        for(i = 0; i < tam; i++) {
            if(string[i] == 'b') {
                resp += (long long int)pow(2, tam - i - 1);
            }
        }
        (void)printf("Palavra %d\n%d\n\n", ++test, resp);
    }
    return 0;
}