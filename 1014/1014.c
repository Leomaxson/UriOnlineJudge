#include <stdio.h>

int main(int argv, char** argc) {
    int distanceKm;
    double spentFuel;

    (void)scanf("%d %lf", &distanceKm, &spentFuel);
    (void)printf("%.3lf km/l\n", distanceKm / spentFuel);
    return 0;
}