#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

#define NUM_MEIOS_TONS (12)
#define MUSICA_TAMANHO_MAX (100000)
#define TRECHO_TAMANHO_MAX (10000)

// ÍNDICE DAS NOTAS:
//  0: G#, Ab
//  1: A
//  2: A#, Bb
//  3: B, Cb
//  4: B#, C
//  5: C#, Db
//  6: D
//  7: D#, Eb
//  8: E, Fb
//  9: F, E#
// 10: F#, Gb
// 11: G

int calculaIndice(char nota, char modificador) {
    int indice;

    // Define o índice base da nota.
    switch(nota) {
        case 'A':
            indice = 1;
            break;
        case 'B':
            indice = 3;
            break;
        case 'C':
            indice = 4;
            break;
        case 'D':
            indice = 6;
            break;
        case 'E':
            indice = 8;
            break;
        case 'F':
            indice = 9;
            break;
        case 'G':
            indice = 11;
            break;
        default:
            return 0xffffffff;  // Erro de nota.
    }

    // Ajusta o modificador.
    switch(modificador) {
        case '#':  // Sustenido.
            indice++;
            break;
        case 'b':  // Bemol
            indice--;
            break;
        default:
            break;
    }

    return indice % NUM_MEIOS_TONS;
}

/**
 * Lê uma nota da entrada padrão.
 * @param nota Apontador para onde a nota será escrita.
 * @param modificador Apontador para onde o modificador da nota será escrito.
 */
void leNota(char *nota, char * modificador) {
    char leitura[5];

    scanf("%s", leitura);
    *nota = leitura[0];
    *modificador = leitura[1];
}

/**
 * Calcula o vetor de deslocamentos de um trecho que será lido da entrada padrão.
 * @param deslocamentos Endereço do vetor onde os deslocamentos serão salvos.
 * @param tamanho Tamanho do trecho que será lido da entrada padrão.
 */
void leLinhaCalculaDeslocamentos(int *deslocamentos, int tamanho) {
    char nota, modificador;
    int i;

    leNota(&nota, &modificador);
    deslocamentos[0] = calculaIndice(nota, modificador);
    for(i = 1; i < tamanho; i++) {
        leNota(&nota, &modificador);
        deslocamentos[i] = calculaIndice(nota, modificador);
        deslocamentos[i - 1] = deslocamentos[i] - deslocamentos[i - 1];
        if(deslocamentos[i - 1] < 0) {
            deslocamentos[i - 1] += NUM_MEIOS_TONS;
        }
    }
}

/**
* Verifica se o trecho ocorre dentro da música utilizando o algoritmo de Boyer-Moore-Horspool
* aplicado aos vetores de deslocamentos da música e do trecho.
* @param musica Apontador para o início dos deslocamentos da música.
* @param tamanho_musica Tamanho do texto.
* @param trecho Apontador para o início do padrão.
* @param tamanho_trecho Tamanho do padrão.
* @return Retorna o apontador para a ocorrência ou NULL se não achar.
*/
int verificaPadrao(const int *musica, int tamanhoMusica, const int *trecho, int tamanhoTrecho) {
    int deslocamentos[NUM_MEIOS_TONS], i, ultimo;

    // Verifica as entradas antes de prosseguir com o algoritmo.
    if((tamanhoTrecho == 0) || (musica == NULL) || (trecho == NULL)) {
        return 0;
    }
    // Inicializa o vetor de deslocamentos do algoritmo de Boyer-Moore-Horspool para todos os 
    // caracteres com o maior deslocamento que é o tamanho do trecho.
    for(i = 0; i < NUM_MEIOS_TONS; i++) {
        deslocamentos[i] = tamanhoTrecho;
    }
    // Para os deslocamentos presentes no trecho, calcula o deslocamento de cada um.
    ultimo = tamanhoTrecho - 1;
    for(i = 0; i < ultimo; i++) {
        deslocamentos[trecho[i]] = ultimo - i;
    }
    // Tenta colidir todos os deslocamentos da música e do trecho, começando de trás para frente. Se 
    // não houver colisão, é porque encontrou uma ocorrência. Se houver colisão, desloca a música de 
    // acordo com o deslocamento dela que causou a colisão.
    while(tamanhoMusica >= tamanhoTrecho) {
        for(i = ultimo; musica[i] == trecho[i]; i--) {
            if(i == 0) {
                return 1;
            }
        }
        tamanhoMusica -= deslocamentos[musica[ultimo]];
        musica += deslocamentos[musica[ultimo]];
    }
    return 0;
}

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main(int argv, char** argc) {
    int tamanhoMusica, tamanhoTrecho, musica[MUSICA_TAMANHO_MAX], trecho[TRECHO_TAMANHO_MAX], resultado;

    // Lê os tamanhos da primeira instância.
    scanf("%d %d", &tamanhoMusica, &tamanhoTrecho);
    while(tamanhoMusica != 0 && tamanhoTrecho != 0) {
      // Calcula os deslocamentos da música e do trecho.
        leLinhaCalculaDeslocamentos(musica, tamanhoMusica);
        tamanhoMusica--;
        leLinhaCalculaDeslocamentos(trecho, tamanhoTrecho);
        tamanhoTrecho--;
        // Verifica se o padrão acontece na música.
        resultado = verificaPadrao(musica, tamanhoMusica, trecho, tamanhoTrecho);
        if(resultado) {
            printf("S\n");
        } else {
            printf("N\n");
        }
        // Lê os tamanhos da próxima instância.
        scanf("%d %d", &tamanhoMusica, &tamanhoTrecho);
    }
    return 0;
}