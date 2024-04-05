#include <stdio.h>

#define RESTO 2
#define LIMITE 10000

int main(int argv, char** argc) {
    unsigned int n, i;

    (void)scanf("%u", &n);
    i = RESTO;
    while(i < LIMITE) {
        (void)printf("%u\n", i);
        i += n;
    }
    return 0;
}