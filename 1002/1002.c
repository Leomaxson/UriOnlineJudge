#include <stdio.h>

// Pi constant.
#define PI (3.14159)

int main(int argv, char** argc) {
    double radius;

    (void)scanf("%lf", &radius);
    (void)printf("A=%.4f\n", PI * radius * radius);
    return 0;
}