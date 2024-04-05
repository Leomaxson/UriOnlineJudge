/*
Problema: Lendo Livros (URI-1542)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Leio os n�meros de p�ginas/dia e a diferen�a em dias para cada entrada. Calculo o n�mero de 
p�ginas para cada inst�ncia de acordo com a f�rmula que relaciona as vari�veis:

X = N�mero de p�ginas do livro.
D = Diferen�a (em dias) das duas velocidades de leitura.
Q = Quantidade de p�ginas lidas por dia.
P = Quantidade de p�ginas que se desejaria ler por dia.

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