#include <stdio.h>

int main(int argv, char** argc) {
    int distanceKm;

    (void)scanf("%d", &distanceKm);
    (void)printf("%d minutos\n", distanceKm * 2);
    return 0;
}