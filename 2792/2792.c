#include <stdlib.h>
#include <stdio.h>

#define LSB(i) ((i) & -(i))

int getSoma(int *A, int i) {
    int sum = 0;
    while(i > 0)
        sum += A[i], i -= LSB(i);
    return sum;
}

void decrementa(int *A, int tam, int i) {
    while(i < tam) {
        A[i] += -1;
        i += LSB(i);
    }
}


int main(int argv, char** argc) {
  //int *vetor, tamVetor, numero, i, j;

  //// Lê o tamanho do vetor e inicializa ele.
  //scanf("%d", &tamVetor);
  //vetor = (int *)malloc((tamVetor + 1) * sizeof(int));
  //for(i = 1; i <= tamVetor; i++) {
  //  vetor[i] = i;
  //}
  //// Lê cada um dos números até o penúltimo, imprime o índice para remoção dele e decrementa o índice dos números 
  //// posteriores.
  //i = tamVetor;
  //while(i > 1) {
  //  scanf("%d", &numero);
  //  (void)printf("%d ", vetor[numero]);
  //  for(j = numero + 1; j <= tamVetor; j++) {
  //    vetor[j]--;
  //  }
  //  i--;
  //}
  //scanf("%d", &numero);
  //(void)printf("%d\n", vetor[numero]);
  //free(vetor);
    return 0;
}