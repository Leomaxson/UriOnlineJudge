#include <stdio.h>

int main(int argv, char** argc) {
    int a, b;

    (void)scanf("%d %d", &a, &b);
    (void)printf("PROD = %d\n", a * b);
    return 0;
}