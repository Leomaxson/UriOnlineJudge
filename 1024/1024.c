#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_MAX_LINHA 1024

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
  size_t numLinhas, tamanho, pos, i;
  char linha[TAMANHO_MAX_LINHA];

  while(fscanf(stdin, "%llu\n", &numLinhas) >= 1) {
    while(numLinhas > 0) {
      // Pega a próxima linha da entrada.
      fgets(linha, TAMANHO_MAX_LINHA, stdin);
      tamanho = strlen(linha);
      if(linha[tamanho - 1] == '\n') {
        tamanho--;
        linha[tamanho] = '\0';
      }
      // Desloca cada letra três posições para a direita.
      for(i = 0; i < tamanho; i++) {
        if(isalpha(linha[i])) {
          linha[i] += 3;
        }
      }
      // Inverte a linha.
      pos = tamanho - 1;
      for(i = 0; i < tamanho / 2; i++) {
        linha[i] ^= linha[pos - i];
        linha[pos - i] ^= linha[i];
        linha[i] ^= linha[pos - i];
      }
      // Desloca cada caractere, da metade em diante, uma posição para a esquerda começando.
      for(i = tamanho / 2; i < tamanho; i++) {
        linha[i]--;
      }
      // Imprime a linha e decrementa a contagem.
      printf("%s\n", linha);
      numLinhas--;
    }
  }
  return 0;
}