#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    double input;
    unsigned int numPos, i;

    numPos = 0;
    for(i = 0; i < 6; i++) {
        (void)scanf("%lf", &input);
        if(input > 0.0) {
            numPos++;
        }
    }
    (void)printf("%u valores positivos\n", numPos);
    return 0;
}