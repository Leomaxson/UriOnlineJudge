#include <stdio.h>

int main(int argv, char** argc) {
    int i, j;

    for(i = 1, j = 60; j >= 0; i += 3, j -= 5) {
        (void)printf("I=%d J=%d\n", i, j);
    }
    return 0;
}