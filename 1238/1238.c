#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 50+1

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
  char string1[TAMANHO], string2[TAMANHO], resultado[TAMANHO * 2];
  unsigned char i, j;
  unsigned int instancias;

  scanf("%u", &instancias);
  while(instancias > 0) {
    scanf("%s %s", string1, string2);
    i = 0;
    j = 0;
    while(string1[i] != '\0' && string2[i] != '\0') {
      resultado[j] = string1[i];
      j++;
      resultado[j] = string2[i];
      j++;
      i++;
    }
    if(string1[i] == '\0') {
      while(string2[i] != '\0') {
        resultado[j] = string2[i];
        i++;
        j++;
      }
    } else {
      while(string1[i] != '\0') {
        resultado[j] = string1[i];
        i++;
        j++;
      }
    }
    resultado[j] = '\0';
    printf("%s\n", resultado);
    instancias--;
  }
  return 0;
}