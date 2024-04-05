#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int i;

    for (i = 2; i <= 100; i += 2) {
        printf("%u\n", i);
    }
    return 0;
}