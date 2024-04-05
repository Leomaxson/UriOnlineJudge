/*
Problema: (B) Bacteria I (SPC Mini Maratona 3)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Basta ler ambas as strings e buscar pela primeira ocorrência do padrão no texto.
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX_TAM (100)

unsigned char verificaPadrao(const unsigned char *texto, unsigned char tamanhoTexto,
                             const unsigned char *padrao, unsigned char tamanhoPadrao) {
    unsigned char deslocamentos[UCHAR_MAX], i, ultimo;

    // Verifica as entradas antes de prosseguir com o algoritmo.
    if((tamanhoPadrao == 0) || (texto == NULL) || (padrao == NULL)) {
        return 0;
    }
    // Inicializa o vetor de deslocamentos do algoritmo de Boyer-Moore-Horspool para todos os 
    // caracteres com o maior deslocamento que é o tamanho do trecho.
    for(i = 0; i < UCHAR_MAX; i++) {
        deslocamentos[i] = tamanhoPadrao;
    }
    // Para os deslocamentos presentes no trecho, calcula o deslocamento de cada um.
    ultimo = tamanhoPadrao - 1;
    for(i = 0; i < ultimo; i++) {
        deslocamentos[padrao[i]] = ultimo - i;
    }
    // Tenta colidir todos os deslocamentos da música e do trecho, começando de trás para frente. Se 
    // não houver colisão, é porque encontrou uma ocorrência. Se houver colisão, desloca a música de 
    // acordo com o deslocamento dela que causou a colisão.
    while(tamanhoTexto >= tamanhoPadrao) {
        for(i = ultimo; texto[i] == padrao[i]; i--) {
            if(i == 0) {
                return 1;
            }
        }
        tamanhoTexto -= deslocamentos[texto[ultimo]];
        texto += deslocamentos[texto[ultimo]];
    }
    return 0;
}

int main(int argv, char** argc) {
    char DNA[MAX_TAM + 1], padrao[MAX_TAM + 1];
    unsigned char tamanhoDNA, tamanhoPadrao, result;

    while(!feof(stdin)) {
        // Tenta ler a próxima instancia.
        (void)scanf("%s", DNA);
        if(feof(stdin)) {
            break;
        }
        (void)scanf("%s", padrao);
        // Calcula o tamanho das sequências.
        tamanhoDNA = 0;
        while(DNA[tamanhoDNA] != '\0') {
            tamanhoDNA++;
        }
        tamanhoPadrao = 0;
        while(padrao[tamanhoPadrao] != '\0') {
            tamanhoPadrao++;
        }
        // Verifica se o padrão aparece e escreve a resposta.
        result = verificaPadrao(DNA, tamanhoDNA, padrao, tamanhoPadrao);
        if(result) {
            (void)printf("Resistente\n");
        } else {
            (void)printf("Nao resistente\n");
        }
    }
    return 0;
}