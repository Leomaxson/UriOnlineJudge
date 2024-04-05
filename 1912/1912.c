#include <stdlib.h>
#include <stdio.h>

#define MAX_TIRAS (100000)

int Compara(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int tiras[MAX_TIRAS], numTiras, areaEsperada, areaTotal, areaAtual, areaSecao, alturaCorte, i;
  double alturaCortePrecisa;

  // L� os tamanhos da primeira inst�ncia.
  scanf("%d %d", &numTiras, &areaEsperada);
  while(numTiras != 0 || areaEsperada != 0) {
    // L� o vetor e determina a �rea total das tiras.
    areaTotal = 0;
    for(i = 0; i < numTiras; i++) {
      scanf("%d", &tiras[i]);
      areaTotal += tiras[i];
    }
    if(areaTotal < areaEsperada) {  // Imposs�vel.
      printf("-.-\n");
    } else if(areaTotal == areaEsperada) {  // Nenhum corte precisa ser feito.
      printf(":D\n");
    } else {  // Precisa determinar o corte.
      qsort(tiras, numTiras, sizeof(int), Compara);
      areaAtual = areaTotal - areaEsperada;
      alturaCorte = 0;
      for(i = 0; i < numTiras; i++) {
        areaSecao = (numTiras - i) * (tiras[i] - alturaCorte);
        if(areaSecao > areaAtual) {
          // Ajuste fino do �ltimo corte.
          alturaCortePrecisa = (double)areaAtual;
          alturaCortePrecisa /= (numTiras - i);
          alturaCortePrecisa += alturaCorte;
          break;
        } else {
          // Cabe a se��o inteira.
          areaAtual -= areaSecao;
          alturaCorte = tiras[i];
        }
      }
      printf("%.4lf\n", alturaCortePrecisa);
    }
    // L� os tamanhos da pr�xima inst�ncia.
    scanf("%d %d", &numTiras, &areaEsperada);
  }
  return 0;
}