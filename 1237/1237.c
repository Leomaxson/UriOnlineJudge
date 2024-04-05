#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TAMANHO_MAXIMO 50 + 2

/**
 * Busca a primeira ocorrência do padrão dentro do texto utilizando o algoritmo
 * Boyer-Moore-Horspool.
 * @param texto Apontador para o início do texto.
 * @param tamanho_texto Tamanho do texto.
 * @param padrao Apontador para o início do padrão.
 * @param tamanho_padrao Tamanho do padrão.
 * @return Retorna o apontador para a ocorrência ou NULL se não achar.
 */
const unsigned char *boyer_moore_horspool(const unsigned char *texto, size_t tamanho_texto,
                                          const unsigned char *padrao, size_t tamanho_padrao) {
    unsigned char deslocamentos[UCHAR_MAX], i, ultimo;

    // Verifica as entradas antes de prosseguir com o algoritmo.
    if((tamanho_padrao == 0) || (texto == NULL) || (padrao == NULL)) {
        return NULL;
    }
    // Inicializa o vetor de deslocamentos para todos os caracteres com o maior deslocamento que é o 
    // tamanho do padrão.
    for(i = 0; i < UCHAR_MAX; i++) {
        deslocamentos[i] = tamanho_padrao;
    }
    // Para os caracteres presentes no padrão, calcula o deslocamento de cada um.
    ultimo = tamanho_padrao - 1;
    for(i = 0; i < ultimo; i++) {
        deslocamentos[padrao[i]] = ultimo - i;
    }
    // Tenta colidir todos os caracteres do texto e do padrão, começando de trás para frente. Se 
    // não houver colisão, é porque encontrou uma ocorrência. Se houver colisão, desloca o texto de 
    // acordo com o caractere dele que causou a colisão.
    while(tamanho_texto >= tamanho_padrao) {
        for(i = ultimo; texto[i] == padrao[i]; i--) {
            if(i == 0) {
                return texto;
            }
        }
        tamanho_texto -= deslocamentos[texto[ultimo]];
        texto += deslocamentos[texto[ultimo]];
    }
    return NULL;
}

/**
 * Ponto de entrada para o programa.
 * @return Retorna sempre zero.
 */
int main(int argv, char** argc) {
    unsigned char *texto, *padrao, *aux;
    size_t tamanho_texto, tamanho_padrao, tamanho_aux, i, j;
    unsigned char maior_substring, instancia;

    // Aloca espaço para ambas as strings.
    texto = malloc((TAMANHO_MAXIMO) * sizeof(unsigned char));
    padrao = malloc((TAMANHO_MAXIMO) * sizeof(unsigned char));

    // Faz a leitura das instâncias e processa uma a uma. Se receber uma instância nula, sai e termina.
    while(fgets(texto, TAMANHO_MAXIMO, stdin) != NULL) {
        fgets(padrao, TAMANHO_MAXIMO, stdin);
        tamanho_texto = strlen(texto);
        tamanho_padrao = strlen(padrao);
        // Determina como a menor string a string do padrão (se o texto for menor, inverte).
        if(tamanho_padrao > tamanho_texto) {
            aux = texto;
            texto = padrao;
            padrao = aux;
            tamanho_aux = tamanho_texto;
            tamanho_texto = tamanho_padrao;
            tamanho_padrao = tamanho_aux;
        }
        // Para cada substring do padrão, começando da maior para as menores (a maior sendo 
        // ele mesmo), verifica utilizando o algoritmo de Boyer-Moore-Horspool se ela está 
        // presente dentro do texto. Como as substrings do padrão são avaliadas em ordem 
        // decrescente de tamanho, a primeira ocorrência será a maior ocorrência.
        maior_substring = 0;
        for(i = tamanho_padrao; i > 0; i--) {
            for(j = 0; j <= tamanho_padrao - i; j++) {
                if(boyer_moore_horspool(texto, tamanho_texto, padrao + j, i) != NULL) {
                    maior_substring = i;
                    break;
                }
            }
            if(maior_substring != 0) {
                break;
            }
        }
        (void)printf("%u\n", maior_substring);
    }
    return 0;
}