#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TAMANHO_MAXIMO 50 + 2

/**
 * Busca a primeira ocorr�ncia do padr�o dentro do texto utilizando o algoritmo
 * Boyer-Moore-Horspool.
 * @param texto Apontador para o in�cio do texto.
 * @param tamanho_texto Tamanho do texto.
 * @param padrao Apontador para o in�cio do padr�o.
 * @param tamanho_padrao Tamanho do padr�o.
 * @return Retorna o apontador para a ocorr�ncia ou NULL se n�o achar.
 */
const unsigned char *boyer_moore_horspool(const unsigned char *texto, size_t tamanho_texto,
                                          const unsigned char *padrao, size_t tamanho_padrao) {
    unsigned char deslocamentos[UCHAR_MAX], i, ultimo;

    // Verifica as entradas antes de prosseguir com o algoritmo.
    if((tamanho_padrao == 0) || (texto == NULL) || (padrao == NULL)) {
        return NULL;
    }
    // Inicializa o vetor de deslocamentos para todos os caracteres com o maior deslocamento que � o 
    // tamanho do padr�o.
    for(i = 0; i < UCHAR_MAX; i++) {
        deslocamentos[i] = tamanho_padrao;
    }
    // Para os caracteres presentes no padr�o, calcula o deslocamento de cada um.
    ultimo = tamanho_padrao - 1;
    for(i = 0; i < ultimo; i++) {
        deslocamentos[padrao[i]] = ultimo - i;
    }
    // Tenta colidir todos os caracteres do texto e do padr�o, come�ando de tr�s para frente. Se 
    // n�o houver colis�o, � porque encontrou uma ocorr�ncia. Se houver colis�o, desloca o texto de 
    // acordo com o caractere dele que causou a colis�o.
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

    // Aloca espa�o para ambas as strings.
    texto = malloc((TAMANHO_MAXIMO) * sizeof(unsigned char));
    padrao = malloc((TAMANHO_MAXIMO) * sizeof(unsigned char));

    // Faz a leitura das inst�ncias e processa uma a uma. Se receber uma inst�ncia nula, sai e termina.
    while(fgets(texto, TAMANHO_MAXIMO, stdin) != NULL) {
        fgets(padrao, TAMANHO_MAXIMO, stdin);
        tamanho_texto = strlen(texto);
        tamanho_padrao = strlen(padrao);
        // Determina como a menor string a string do padr�o (se o texto for menor, inverte).
        if(tamanho_padrao > tamanho_texto) {
            aux = texto;
            texto = padrao;
            padrao = aux;
            tamanho_aux = tamanho_texto;
            tamanho_texto = tamanho_padrao;
            tamanho_padrao = tamanho_aux;
        }
        // Para cada substring do padr�o, come�ando da maior para as menores (a maior sendo 
        // ele mesmo), verifica utilizando o algoritmo de Boyer-Moore-Horspool se ela est� 
        // presente dentro do texto. Como as substrings do padr�o s�o avaliadas em ordem 
        // decrescente de tamanho, a primeira ocorr�ncia ser� a maior ocorr�ncia.
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