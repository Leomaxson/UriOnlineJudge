#include <stdio.h>

int main(int argv, char** argc) {
    int i, j;

    for(i = 1; i <= 9; i += 2) {
        for(j = i + 6; j >= i + 4; j--) {
            (void)printf("I=%d J=%d\n", i, j);
        }
    }
    return 0;
}