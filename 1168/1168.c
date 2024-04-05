// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TAMANHO 100+1

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
  unsigned int instancias, num_leds;
  unsigned char tamanho_numero, i;
  char numero[TAMANHO];

  scanf("%u", &instancias);
  while(instancias > 0) {
    scanf("%s", &numero);
    tamanho_numero = strlen(numero);
    num_leds = 0;
    for(i = 0; i < tamanho_numero; i++) {
      switch(numero[i]) {
        case '1':  // 2 leds
          num_leds += 2;
          break;
        case '7':  // 3 leds
          num_leds += 3;
          break;
        case '4':  // 4 leds
          num_leds += 4;
          break;
        case '2':  // 5 leds
        case '3':  // 5 leds
        case '5':  // 5 leds
          num_leds += 5;
          break;
        case '0':  // 6 leds
        case '6':  // 6 leds
        case '9':  // 6 leds
          num_leds += 6;
          break;
        case '8':  // 7 leds
          num_leds += 7;
      }
    }
    printf("%u leds\n", num_leds);
    instancias--;
  }
  return 0;
}