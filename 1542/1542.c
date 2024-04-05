/*
Problema: Lendo Livros (URI-1542)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Leio os números de páginas/dia e a diferença em dias para cada entrada. Calculo o número de 
páginas para cada instância de acordo com a fórmula que relaciona as variáveis:

X = Número de páginas do livro.
D = Diferença (em dias) das duas velocidades de leitura.
Q = Quantidade de páginas lidas por dia.
P = Quantidade de páginas que se desejaria ler por dia.

X = (D x Q x P) / (P - Q)
*/

#include <stdio.h>

int main() {
  unsigned int x, d, q, p;

  while(1) {
    scanf("%u", &q);
    if(q == 0) {
      break;
    }
    scanf("%u", &d);
    scanf("%u", &p);
    x = (d * q * p) / (p - q);
    if(x == 1) {
      printf("1 pagina\n");
    } else {
      printf("%u paginas\n", x);
    }
  }
  return 0;
}