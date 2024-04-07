#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int instancias;
    int x, y;

    (void)scanf("%u", &instancias);
    while(instancias) {
        (void)scanf("%d %d", &x, &y);
        if(y == 0) {
            (void)printf("divisao impossivel\n");
        } else if(x == 0) {
            (void)printf("0.0\n");
        } else {
            (void)printf("%.1lf\n", (double)x / (double)y);
        }
        instancias--;
    }
    return 0;
}