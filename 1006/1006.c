#include <stdlib.h>
#include <stdio.h>

#define WEIGHT_A (2.0)
#define WEIGHT_B (3.0)
#define WEIGHT_C (5.0)
#define SUM_WEIGHTS (WEIGHT_A + WEIGHT_B + WEIGHT_C)

int main(int argv, char** argc) {
    double a, b, c, average;

    (void)scanf("%lf %lf %lf", &a, &b, &c);
    average = (a * WEIGHT_A + b * WEIGHT_B + c * WEIGHT_C) / SUM_WEIGHTS;
    (void)printf("MEDIA = %.1f\n", average);
    return 0;
}