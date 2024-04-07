#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int entrada, i;

    (void)scanf("%u", &entrada);
    for(i = 1; i <= entrada; i++) {
        if(entrada % i == 0) {
            (void)printf("%u\n", i);
        }
    }
    return 0;
}