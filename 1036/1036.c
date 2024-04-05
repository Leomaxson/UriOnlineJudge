#include <stdio.h>
#include <math.h>

int main(int argv, char** argc) {
    double a, b, c, delta;

    (void)scanf("%lf %lf %lf", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if(delta < 0.0 || a == 0.0) {
        printf("Impossivel calcular\n");
    } else {
        printf("R1 = %.5lf\n", (-b + sqrt(delta)) / (2.0 * a));
        printf("R2 = %.5lf\n", (-b - sqrt(delta)) / (2.0 * a));
    }
    return 0;
}