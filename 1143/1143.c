#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int entrada, i;

    (void)scanf("%u", &entrada);
    for(i = 1; i <= entrada; i++) {
        (void)printf("%u %u %u\n", i, i * i, i * i * i);
    }
    return 0;
}