#include <stdlib.h>
#include <stdio.h>

#define DESLOC (12)

int main(int argv, char** argc) {
    int input, max;

    (void)scanf("%d", &input);
    max = input + DESLOC;
    if(input % 2 == 0) {
        input++;
    }
    for(; input < max; input += 2) {
        (void)printf("%d\n", input);
    }
    return 0;
}