#include <stdlib.h>
#include <stdio.h>

#define NUM_TAMANHOS (6)
#define MAX_VOLUNTARIOS (30)
#define MAX_STR_TAMANHO (4)

unsigned int converteStrTamanho(char * tamanho) {
    switch(tamanho[0]) {
        case 'X':
            switch(tamanho[1]) {
                case 'X':
                    return 5;
                case 'L':
                    return 4;
                case 'S':
                    return 0;
            }
        case 'L':
            return 3;
        case 'M':
            return 2;
        case 'S':
            return 1;
    }
    return 0;
}

unsigned int tentaCasar(unsigned int numCamisas,
                        unsigned int numVoluntarios,
                        unsigned int indiceVoluntario,
                        unsigned int tamanho1[MAX_VOLUNTARIOS],
                        unsigned int tamanho2[MAX_VOLUNTARIOS],
                        unsigned int contTamanhos[NUM_TAMANHOS]) {
    unsigned int retorno;

    // Se já preencheu todos os voluntários, retorna 1.
    if(indiceVoluntario >= numVoluntarios) {
        return 1;
    }

    if(contTamanhos[tamanho1[indiceVoluntario]] < numCamisas) {
        contTamanhos[tamanho1[indiceVoluntario]]++;
        retorno = tentaCasar(numCamisas, numVoluntarios, indiceVoluntario + 1, tamanho1, tamanho2, contTamanhos);
        contTamanhos[tamanho1[indiceVoluntario]]--;
        if(retorno) {
            return 1;
        }
    }
    if(contTamanhos[tamanho2[indiceVoluntario]] < numCamisas) {
        contTamanhos[tamanho2[indiceVoluntario]]++;
        retorno = tentaCasar(numCamisas, numVoluntarios, indiceVoluntario + 1, tamanho1, tamanho2, contTamanhos);
        contTamanhos[tamanho2[indiceVoluntario]]--;
        if(retorno) {
            return 1;
        }
    }
    return 0;
}

int main(int argv, char** argc) {
    unsigned int numInstancias, numCamisas, numVoluntarios, i, retorno;
    unsigned int tamanho1[MAX_VOLUNTARIOS], tamanho2[MAX_VOLUNTARIOS], contTamanhos[NUM_TAMANHOS];
    char strTamanho1[MAX_STR_TAMANHO], strTamanho2[MAX_STR_TAMANHO];

    scanf("%u", &numInstancias);
    while(numInstancias) {
      // Lê a instância.
        scanf("%u %u", &numCamisas, &numVoluntarios);
        numCamisas /= 6;
        for(i = 0; i < numVoluntarios; i++) {
            scanf("%s %s", strTamanho1, strTamanho2);
            tamanho1[i] = converteStrTamanho(strTamanho1);
            tamanho2[i] = converteStrTamanho(strTamanho2);
        }
        // Zera a contagem dos tamanhos.
        for(i = 0; i < NUM_TAMANHOS; i++) {
            contTamanhos[i] = 0;
        }
        retorno = tentaCasar(numCamisas, numVoluntarios, 0, tamanho1, tamanho2, contTamanhos);
        if(retorno) {
            (void)printf("YES\n");
        } else {
            (void)printf("NO\n");
        }
        numInstancias--;
    }
    return 0;
}