#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int input, i;

    (void)scanf("%u", &input);
    for(i = 1; i <= 10; i++) {
        (void)printf("%u x %u = %u\n", i, input, i * input);
    }
    return 0;
}