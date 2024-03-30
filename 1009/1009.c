#include <stdlib.h>
#include <stdio.h>

// Percentage of bonus over sales.
#define SALES_BONUS (0.15)

int main(int argv, char** argc) {
  double salary, sales;

  (void)scanf("%*s %lf %lf", &salary, &sales);
  (void)printf("TOTAL = R$ %.2f\n", salary + sales * SALES_BONUS);
  return 0;
}