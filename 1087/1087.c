#include <stdio.h>
#include <stdlib.h>

int main() {
  int xInicial, yInicial, xFinal, yFinal, distancia;

  // Lê a instância inicial.
  scanf("%d %d %d %d", &xInicial, &yInicial, &xFinal, &yFinal);
  while(xInicial != 0 || yInicial != 0 || xFinal != 0 || yFinal != 0) {
    // Verifica a distância.
    if(xInicial == xFinal && yInicial == yFinal) {  // Mesma posição.
      distancia = 0;
    } else if(xInicial == xFinal || yInicial == yFinal) {  // Mesma linha ou coluna.
      distancia = 1;
    } else if(abs(xInicial - xFinal) == abs(yInicial - yFinal)) {  // Mesma diagonal.
      distancia = 1;
    } else {
      distancia = 2;
    }
    // Imprime o resultado.
    printf("%d\n", distancia);
    // Lê a próxima instância.
    scanf("%d %d %d %d", &xInicial, &yInicial, &xFinal, &yFinal);
  }
  return 0;
}