#include <stdio.h>

int areMultiple(int a, int b) {
  return (a % b == 0) || 
         (b % a == 0);
}

int main(int argv, char** argc) {
  int a, b;

  (void)scanf("%d %d", &a, &b);
  if(areMultiple(a, b)) {
    (void)printf("Sao Multiplos\n");
  } else {
    (void)printf("Nao sao Multiplos\n");
  }
  return 0;
}