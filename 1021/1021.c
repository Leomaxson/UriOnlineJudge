#include <stdio.h>

typedef struct SExchange {
  int n100, n50, n20, n10, n5, n2;
  int m1, m050, m025, m010, m005, m001;
} Exchange;

inline int calcDivisionReturnRest(int *quocient, int dividend, int divisor) {
  *quocient = dividend / divisor;
  return dividend % divisor;
}

void Exchange_Calculate(Exchange *exchange, double price) {
  int m001Total;

  m001Total = (int)(price / 0.01);

  m001Total = calcDivisionReturnRest(&exchange->n100, m001Total, 10000);
  m001Total = calcDivisionReturnRest(&exchange->n50,  m001Total,  5000);
  m001Total = calcDivisionReturnRest(&exchange->n20,  m001Total,  2000);
  m001Total = calcDivisionReturnRest(&exchange->n10,  m001Total,  1000);
  m001Total = calcDivisionReturnRest(&exchange->n5,   m001Total,   500);
  m001Total = calcDivisionReturnRest(&exchange->n2,   m001Total,   200);
  m001Total = calcDivisionReturnRest(&exchange->m1,   m001Total,   100);
  m001Total = calcDivisionReturnRest(&exchange->m050, m001Total,    50);
  m001Total = calcDivisionReturnRest(&exchange->m025, m001Total,    25);
  m001Total = calcDivisionReturnRest(&exchange->m010, m001Total,    10);
  m001Total = calcDivisionReturnRest(&exchange->m005, m001Total,     5);
  exchange->m001 = m001Total;
}

void Exchange_Print(Exchange *exchange) {
  (void)printf("NOTAS:\n");
  (void)printf("%d nota(s) de R$ 100.00\n", exchange->n100);
  (void)printf("%d nota(s) de R$ 50.00\n",  exchange->n50);
  (void)printf("%d nota(s) de R$ 20.00\n",  exchange->n20);
  (void)printf("%d nota(s) de R$ 10.00\n",  exchange->n10);
  (void)printf("%d nota(s) de R$ 5.00\n",   exchange->n5);
  (void)printf("%d nota(s) de R$ 2.00\n",   exchange->n2);
  (void)printf("MOEDAS:\n");
  (void)printf("%d moeda(s) de R$ 1.00\n",  exchange->m1);
  (void)printf("%d moeda(s) de R$ 0.50\n",  exchange->m050);
  (void)printf("%d moeda(s) de R$ 0.25\n",  exchange->m025);
  (void)printf("%d moeda(s) de R$ 0.10\n",  exchange->m010);
  (void)printf("%d moeda(s) de R$ 0.05\n",  exchange->m005);
  (void)printf("%d moeda(s) de R$ 0.01\n",  exchange->m001);
}

int main(int argv, char** argc) {
  Exchange exchange;
  double price;

  (void)scanf("%lf", &price);
  Exchange_Calculate(&exchange, price);
  Exchange_Print(&exchange);

  return 0;
}