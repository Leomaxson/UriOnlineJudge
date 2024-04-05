#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    int input;
    unsigned int count, in, out;

    (void)scanf("%u", &count);
    in = out = 0;
    while(count) {
        (void)scanf("%u", &input);
        if(input < 10 || input > 20) {
            out++;
        } else {
            in++;
        }
        count--;
    }
    (void)printf("%u in\n%u out\n", in, out);
    return 0;
}