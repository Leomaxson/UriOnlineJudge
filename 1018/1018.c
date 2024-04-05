#include <stdio.h>

int main(int argv, char** argc) {
    int value, n100, n50, n20, n10, n5, n2, n1;

    (void)scanf("%d", &value);

    n100 = value / 100;
    n1 = value % 100;
    n50 = n1 / 50;
    n1 %= 50;
    n20 = n1 / 20;
    n1 %= 20;
    n10 = n1 / 10;
    n1 %= 10;
    n5 = n1 / 5;
    n1 %= 5;
    n2 = n1 / 2;
    n1 %= 2;

    (void)printf("%d\n", value);
    (void)printf("%d nota(s) de R$ 100,00\n", n100);
    (void)printf("%d nota(s) de R$ 50,00\n", n50);
    (void)printf("%d nota(s) de R$ 20,00\n", n20);
    (void)printf("%d nota(s) de R$ 10,00\n", n10);
    (void)printf("%d nota(s) de R$ 5,00\n", n5);
    (void)printf("%d nota(s) de R$ 2,00\n", n2);
    (void)printf("%d nota(s) de R$ 1,00\n", n1);
    return 0;
}