#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_BUFFER (5)

int main() {
  unsigned int numInstancias, min, max, i, tamNum, j;
  char buffer[TAMANHO_BUFFER + 1], aux;

  // Lê o número de instâncias.
  scanf("%u", &numInstancias);
  while(numInstancias) {
    // Lê os limites da instância.
    scanf("%u %u", &min, &max);
    // Imprime a ida.
    for(i = min; i <= max; i++) {
      printf("%u", i);
    }
    // Imprime a volta.
    for(i = max; i >= min; i--) {
      // Acha o tamanho do número.
      sprintf(buffer, "%u", i);
      tamNum = 1;
      while(buffer[tamNum] != '\0') {
        tamNum++;
      }
      tamNum--;
      // Inverte o número no buffer.
      j = 0;
      while(j < tamNum) {
        aux = buffer[j];
        buffer[j] = buffer[tamNum];
        buffer[tamNum] = aux;
        j++;
        tamNum--;
      }
      // Imprime o número invertido.
      printf("%s", buffer);
    }
    printf("\n");
    numInstancias--;
  }
  return 0;
}