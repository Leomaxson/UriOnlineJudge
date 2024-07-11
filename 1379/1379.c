#include <stdio.h>

int main(int argv, char **argc) {
    int a, b, c;

    (void)scanf("%d %d", &a, &b);
    while(a != 0 && b != 0) {
        //  (a + b + c) / 3 = a   ->   c = 2 * a - b
        c = 2 * a - b;
        (void)printf("%d\n", c);
        (void)scanf("%d %d", &a, &b);
    }
    return 0;
}
