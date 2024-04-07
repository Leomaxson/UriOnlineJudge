#include <stdio.h>

int main(int argv, char** argc) {
    int a, b;

    (void)scanf("%d %d", &a, &b);
    while(a != b) {
        if(a > b) {
            (void)printf("Decrescente\n");
        } else {
            (void)printf("Crescente\n");
        }
        (void)scanf("%d %d", &a, &b);
    }
    return 0;
}