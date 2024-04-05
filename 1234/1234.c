#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCA (60)

int main() {
  unsigned int i, maiuscula;
  char sentenca[MAX_SENTENCA];

  while(!feof(stdin)) {
    // L� uma senten�a da entrada.
    fgets(sentenca, MAX_SENTENCA, stdin);
    if(feof(stdin)) {
      continue;
    }
    // Percorre os caracteres alternando entre mai�scula e min�scula.
    i = 0;
    maiuscula = 1;
    while(sentenca[i] != '\0') {
      if(isalpha(sentenca[i])) {
        if(maiuscula) {
          maiuscula = 0;
          sentenca[i] = toupper(sentenca[i]);
        } else {
          maiuscula = 1;
          sentenca[i] = tolower(sentenca[i]);
        }
      }
      i++;
    }
    // Imprime a senten�a modificada.
    printf("%s", sentenca);
  }
  return 0;
}