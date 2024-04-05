#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TAMANHO_MAXIMO_ENUNCIADO 50 + 1
#define DIFICULDADE_FACIL 250
#define DIFICULDADE_MEDIO 500
#define DIFICULDADE_DIFICIL 1000

char calculaTamanhoPalavra(char enunciado[], char posicao, char posicaoFim) {
    char i, palavra;

    palavra = 1;
    for(i = posicao; i < posicaoFim; i++) {
        if(isdigit(enunciado[i])) {
            palavra = 0;
        }
        if(ispunct(enunciado[i])) {
            if(palavra) {
                if(i == posicaoFim - 1) {  // � um ponto final?
                    if(posicaoFim - posicao == 1) {  // � um ponto final, mas sem nenhuma letra?
                        return -1;
                    }
                    return posicaoFim - posicao - 1;
                } else {
                    palavra = 0;
                }
            }
        }
    }
    if(palavra) {
        return posicaoFim - posicao;
    }
    return posicao - posicaoFim;
}

char achaFimSimbolo(char enunciado[], char posicao) {
    char pos;

    pos = posicao;
    while(enunciado[pos] != '\0' && !isspace(enunciado[pos])) {
        pos++;
    }
    return pos;
}

/**
 * Acha o pr�ximo s�mbolo na linha.
 * @param enunciado Linha com o enunciado.
 * @param posicao Posi��o para come�ar a procurar.
 * @return Retorna a posi��o do pr�ximo s�mbolo (ou -1 se n�o achar um s�mbolo).
 */
char achaSimbolo(char enunciado[], char posicao) {
    char pos;

    pos = posicao;
    while(enunciado[pos] != '\0' && !isalnum(enunciado[pos]) && !ispunct(enunciado[pos])) {
        pos++;
    }

    // Verifica se chegou no final da string ou achou um s�mbolo.
    if(enunciado[pos] == '\0') {
        return -1;
    }
    return pos;
}

/**
 * Define a dificuldade do problema de acordo com o tamanho m�dio das palavras dele.
 * @param tamanhoMedio Tamanho m�dio das palavras do problema.
 * @return Retorna a dificuldade do problema.
 */
int calculaDificuldade(char comprimentoTotal, char numPalavras) {
    char tamanhoMedio;

    if(numPalavras == 0) {
        return DIFICULDADE_FACIL;
    }
    tamanhoMedio = comprimentoTotal / numPalavras;
    if(tamanhoMedio <= 3) {
        return DIFICULDADE_FACIL;
    } else if(tamanhoMedio <= 5) {
        return DIFICULDADE_MEDIO;
    }
    return DIFICULDADE_DIFICIL;
}

/**
 * Ponto de entrada para o programa.
 * @return Retorna sempre zero.
 */
int main(int argv, char** argc) {
  // FILE *entrada;
    char enunciado[TAMANHO_MAXIMO_ENUNCIADO], aux, comprimentoTotal, numPalavras, posicao, posicaoFimSimbolo;

    /*entrada = fopen("input.txt", "r");
    if(entrada == NULL) {
      (void)printf("Erro ao abrir o arquivo.");
      return 0;
    }*/

    //while(!feof(entrada)) {
    while(!feof(stdin)) {
      // L� uma linha da entrada padr�o.
      //if(fgets(enunciado, TAMANHO_MAXIMO_ENUNCIADO, entrada) == NULL) {
        if(fgets(enunciado, TAMANHO_MAXIMO_ENUNCIADO, stdin) == NULL) {
            return 0;
        }
        posicao = comprimentoTotal = numPalavras = 0;
        // Enquanto achar s�mbolos, processa o s�mbolo para ver o tamanho. Se for uma palavra, soma o 
        // tamanho ao comprimento total das palavras.
        while((posicao = achaSimbolo(enunciado, posicao)) >= 0) {
            posicaoFimSimbolo = achaFimSimbolo(enunciado, posicao);
            aux = calculaTamanhoPalavra(enunciado, posicao, posicaoFimSimbolo);
            if(aux < 0) {
                posicao = posicaoFimSimbolo;
            } else {
                posicao = posicaoFimSimbolo;
                comprimentoTotal += aux;
                numPalavras++;
            }
        }
        // Calcula o tamanho m�dio das palavras da linha (enunciado) e imprime a dificuldade.
        (void)printf("%u\n", calculaDificuldade(comprimentoTotal, numPalavras));
    }
    return 0;
}
