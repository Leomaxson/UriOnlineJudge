#include <stdio.h>

int main(int argv, char** argc) {
    int a, n;

    do {
        (void)scanf("%d", &a);
    } while(a <= 0);
    do {
        (void)scanf("%d", &n);
    } while(n <= 0);
    (void)printf("%d\n", ((a + a + n - 1) * n) / 2);
    return 0;
}