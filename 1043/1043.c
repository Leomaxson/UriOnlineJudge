#include <stdio.h>

int isTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main(int argv, char** argc) {
    double a, b, c;

    (void)scanf("%lf %lf %lf", &a, &b, &c);
    if(isTriangle(a, b, c)) {
        (void)printf("Perimetro = %.1lf\n", a + b + c);
    } else {
        (void)printf("Area = %.1lf\n", (a + b) * c / 2.0);
    }
    return 0;
}