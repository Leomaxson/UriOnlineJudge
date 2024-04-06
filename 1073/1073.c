#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int input, i;

    (void)scanf("%u", &input);
    for(i = 2; i <= input; i += 2) {
        (void)printf("%u^2 = %u\n", i, i * i);
    }
    return 0;
}