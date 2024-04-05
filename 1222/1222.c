#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA (70 + 1)

int main() {
  char palavra[MAX_PALAVRA];
  unsigned int numPalavras, maxLinhasPagina, maxCharsLinha, numCharsLinhaAtual, numLinhasPaginaAtual, numPaginas, tamPalavra;

  while(!feof(stdin)) {
    scanf("%u %u %u", &numPalavras, &maxLinhasPagina, &maxCharsLinha);
    if(feof(stdin)) {
      continue;
    }
    numCharsLinhaAtual = 0;
    numPaginas = 1;
    numLinhasPaginaAtual = 1;
    while(numPalavras) {
      // Lê a próxima palavra e calcula o tamanho.
      scanf("%s", palavra);
      tamPalavra = strlen(palavra);
      numCharsLinhaAtual += tamPalavra;
      // Verifica se tem que trocar de linha.
      if(numCharsLinhaAtual > maxCharsLinha) {
        numCharsLinhaAtual = tamPalavra;
        numLinhasPaginaAtual++;
      }
      // Verifica se tem que trocar de página.
      if(numLinhasPaginaAtual > maxLinhasPagina) {
        numLinhasPaginaAtual = 1;
        numPaginas++;
      }
      numPalavras--;
      if(numPalavras) {
        // Adiciona o espaço entre palavras.
        numCharsLinhaAtual++;
        // Verifica se tem que trocar de linha.
        if(numCharsLinhaAtual > maxCharsLinha) {
          numCharsLinhaAtual = 0;
          numLinhasPaginaAtual++;
        }
        // Verifica se tem que trocar de página.
        if(numLinhasPaginaAtual > maxLinhasPagina) {
          numLinhasPaginaAtual = 1;
          numPaginas++;
        }
      }
    }
    // Imprime o número de páginas necessárias.
    printf("%u\n", numPaginas);
  }
  return 0;
}