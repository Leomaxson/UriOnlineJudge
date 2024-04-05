#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAX_LENGTH (10000 + 1)
#define OP_SHIFT_VOGAIS (0)
#define OP_SHIFT_CONSOANTES (1)
#define OP_IMPRIME (2)

unsigned int vogal(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return 0;
}

void shiftRight(unsigned int tamanho, char * stringOriginal, char * stringShiftada, unsigned int shift) {
    unsigned int i;

    for(i = 0; i < tamanho; i++) {
        stringShiftada[(i + shift) % tamanho] = stringOriginal[i];
    }
}

unsigned int separaVogaisConsoantes(char * stringOriginal, char * vogais, unsigned int * numVogais,
                                    unsigned int * indicesVogais, char * consoantes) {
    unsigned int i, j, k;

    i = 0;
    j = 0;
    k = 0;
    while(stringOriginal[i] != '\0') {
        if(vogal(stringOriginal[i])) {
            vogais[j] = stringOriginal[i];
            indicesVogais[j] = i;
            j++;
        } else {
            consoantes[k] = stringOriginal[i];
            k++;
        }
        i++;
    }
    indicesVogais[j] = UINT_MAX;  // Ajuste para definir o limite do vetor para a comparação na hora de montar a string.
    *numVogais = j;
    return i;
}

void montaString(char * vogais, char * consoantes, char * saida,
                 unsigned int * indicesVogais, unsigned int tamString) {
    unsigned int i, j, k;

    j = 0;
    k = 0;
    for(i = 0; i < tamString; i++) {
        if(i == indicesVogais[j]) {
            saida[i] = vogais[j];
            j++;
        } else {
            saida[i] = consoantes[k];
            k++;
        }
    }
    saida[tamString] = '\0';
}

int main(int argv, char** argc) {
    char string1[MAX_LENGTH], string2[MAX_LENGTH], string3[MAX_LENGTH];
    char * vogais, *consoantes, *buffer, *aux;
    unsigned int indicesVogais[MAX_LENGTH];
    unsigned int numInstancias, instancia;
    unsigned int tamString, numVogais, numConsoantes;
    unsigned int numOperacoes, op, shift, shiftVogais, shiftConsoantes;

    scanf("%u", &numInstancias);
    instancia = 1;
    while(instancia <= numInstancias) {
        vogais = string1;
        consoantes = string2;
        buffer = string3;
        scanf("%s", buffer);
        tamString = separaVogaisConsoantes(buffer, vogais, &numVogais, indicesVogais, consoantes);
        numConsoantes = tamString - numVogais;
        scanf("%u", &numOperacoes);
        printf("Caso #%u:\n", instancia);
        shiftVogais = 0;
        shiftConsoantes = 0;
        while(numOperacoes) {
            scanf("%u", &op);
            switch(op) {
                case OP_SHIFT_VOGAIS:
                    scanf("%u", &shift);
                    shiftVogais += shift;
                    break;
                case OP_SHIFT_CONSOANTES:
                    scanf("%u", &shift);
                    shiftConsoantes += shift;
                    break;
                case OP_IMPRIME:
                    if(shiftVogais > 0) {
                        shiftRight(numVogais, vogais, buffer, shiftVogais);
                        aux = vogais;
                        vogais = buffer;
                        buffer = aux;
                        shiftVogais = 0;
                    }
                    if(shiftConsoantes > 0) {
                        shiftRight(numConsoantes, consoantes, buffer, shiftConsoantes);
                        aux = consoantes;
                        consoantes = buffer;
                        buffer = aux;
                        shiftConsoantes = 0;
                    }
                    montaString(vogais, consoantes, buffer, indicesVogais, tamString);
                    printf("%s\n", buffer);
                    break;
                default:
                    break;
            }
            numOperacoes--;
        }
        instancia++;
    }
    return 0;
}