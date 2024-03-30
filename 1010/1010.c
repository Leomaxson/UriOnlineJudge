#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
  int quant1, quant2;
  double price1, price2;

  (void)scanf("%*d %d %lf %*d %d %lf", &quant1, &price1, &quant2, &price2);
  (void)printf("VALOR A PAGAR: R$ %.2f\n", quant1 * price1 + quant2 * price2);
  return 0;
}