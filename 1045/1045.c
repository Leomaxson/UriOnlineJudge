#include <stdio.h>

void swap(double *x, double *y) {
    double aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void trySwap(double *x, double *y) {
    if(*x < *y) {
        swap(x, y);
    }
}

void sortABC(double *a, double *b, double *c) {
    trySwap(a, b);
    trySwap(a, c);
    trySwap(b, c);
}

int main(int argv, char **argc) {
    double a, b, c;

    (void)scanf("%lf %lf %lf", &a, &b, &c);
    sortABC(&a, &b, &c);
    if(a >= b + c) {
        (void)printf("NAO FORMA TRIANGULO\n");
    } else {
        if((a * a) > (b * b + c * c)) {
            (void)printf("TRIANGULO OBTUSANGULO\n");
        } else if((a * a) < (b * b + c * c)) {
            (void)printf("TRIANGULO ACUTANGULO\n");
        } else {
            (void)printf("TRIANGULO RETANGULO\n");
        }
        if(a == b && b == c) {
            (void)printf("TRIANGULO EQUILATERO\n");
        } else if(a == b || b == c) {
            (void)printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}