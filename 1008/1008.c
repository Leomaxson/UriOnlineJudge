#include <stdio.h>

int main(int argv, char** argc) {
    int number, hours;
    double hourPay;

    (void)scanf("%d %d %lf", &number, &hours, &hourPay);
    (void)printf("NUMBER = %d\nSALARY = U$ %.2f\n", number, hourPay * hours);
    return 0;
}