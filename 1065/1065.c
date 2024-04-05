#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    int input;
    unsigned int numPares, i;

    numPares = 0;
    for(i = 0; i < 5; i++) {
        (void)scanf("%d", &input);
        if((input % 2) == 0) {
            numPares++;
        }
    }
    (void)printf("%u valores pares\n", numPares);
    return 0;
}