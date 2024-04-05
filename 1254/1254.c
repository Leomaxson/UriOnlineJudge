#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_TAG (10 + 1)
#define TAM_SUBST (4 + 1)
#define TAM_TEXTO (100 + 2)
#define TAM_SAIDA (400 + 1)

int main(int argv, char** argc) {
    char tag[TAM_TAG], subst[TAM_SUBST], textoOriginal[TAM_TEXTO], texto[TAM_TEXTO], saida[TAM_SAIDA];
    char *ptrTextoOriginal, *ptrTexto, *ptrSaida, *ptrTag;
    size_t tamanhoTag, tamanhoSubst, tamanhoTexto, i, cont;

    while(!feof(stdin)) {
      // L� a entrada de uma inst�ncia.
        scanf("%s %s", tag, subst);
        getchar();
        fgets(textoOriginal, TAM_TEXTO, stdin);
        if(feof(stdin)) {
            break;
        }
        // Prepara dados para a execu��o.
        strcpy(texto, textoOriginal);
        i = 0;
        while(tag[i] != '\0') {
            tag[i] = tolower(tag[i]);
            i++;
        }
        i = 0;
        while(texto[i] != '\0') {
            texto[i] = tolower(texto[i]);
            i++;
        }
        tamanhoTag = strlen(tag);
        tamanhoSubst = strlen(subst);
        tamanhoTexto = strlen(texto);
        ptrTexto = texto;
        ptrSaida = saida;
        ptrTextoOriginal = textoOriginal;
        // Inicia o processamento da inst�ncia.
        ptrTag = strstr(ptrTexto, tag);
        while(ptrTag != NULL) {
          // Copia o trecho do texto original ainda n�o copiado at� o ponto da tag e move os ponteiros de leitura e escrita.
            cont = ptrTag - ptrTexto;
            strncpy(ptrSaida, ptrTextoOriginal, cont);
            ptrSaida += cont;
            ptrTextoOriginal += cont;
            // Verifica se est� dentro ou fora de uma tag.
            i = 0;
            while(ptrTag[i] != '>' && ptrTag[i] != '<' && ptrTag[i] != '\0') {
                i++;
            }
            if(ptrTag[i] == '>') {  // Dentro de uma tag.
              // Copia a substitui��o da tag pra sa�da e move os ponteiros de leitura e escrita.
                strncpy(ptrSaida, subst, tamanhoSubst);
                ptrSaida += tamanhoSubst;
            } else {  // Fora de uma tag.
              // Copia o trecho da tag encontrado para a sa�da e move os ponteiros de leitura e escrita.
                strncpy(ptrSaida, ptrTextoOriginal, tamanhoTag);
                ptrSaida += tamanhoTag;
            }
            ptrTextoOriginal += tamanhoTag;
            // Avan�a o ponteiro de busca at� depois do padr�o encontrado.
            ptrTexto = ptrTag;
            ptrTexto += tamanhoTag;
            ptrTag = strstr(ptrTexto, tag);
        }
        strcpy(ptrSaida, ptrTextoOriginal);
        printf("%s", saida);
    }
    return 0;
}