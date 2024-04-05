#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 50 + 1
#define MENOR_LETRA 'a'
#define MAIOR_LETRA 'z'
#define NUM_LETRAS (MAIOR_LETRA - MENOR_LETRA + 1)


/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
  char texto[TAMANHO_MAXIMO];
  unsigned char letras[26], i, j, primeiro;

  // Faz a leitura das instâncias e processa uma a uma. Se receber uma instância nula, sai e termina.
  while(gets(texto) != NULL) {
    // Inicializa os flags como zero.
    for(i = 0; i < NUM_LETRAS; i++) {
      letras[i] = 0;
    }
    // Marca os flags das letras utilizadas no texto.
    i = 0;
    while(texto[i] != '\0') {
      letras[texto[i] - MENOR_LETRA] = 1;
      i++;
    }
    // Percorre o vetor de flags agrupando letras seguidas.
    i = 0;
    primeiro = 1;
    while(i < NUM_LETRAS) {
      if(letras[i]) {
        j = i + 1;
        while(letras[j] && j < NUM_LETRAS) {
          j++;
        }
        if(primeiro) {
          printf("%c:%c", i + MENOR_LETRA, j + MENOR_LETRA - 1);
          primeiro = 0;
        } else {
          printf(", %c:%c", i + MENOR_LETRA, j + MENOR_LETRA - 1);
        }
        i = j;
      }
      i++;
    }
    printf("\n");
  }
  return 0;
}