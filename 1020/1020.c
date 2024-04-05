#include <stdio.h>

int main(int argv, char** argc) {
    int years, months, days;

    (void)scanf("%d", &days);

    years = days / 365;
    days %= 365;
    months = days / 30;
    days %= 30;

    (void)printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", years, months, days);
    return 0;
}