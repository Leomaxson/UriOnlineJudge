#include <stdio.h>

int main(int argv, char** argc) {
    int x, y;

    while(1) {
        (void)scanf("%d %d", &x, &y);
        if(x == 0 || y == 0) {
            break;
        }

        if(x > 0) {
            if(y > 0) {
                (void)printf("primeiro\n");
            } else {
                (void)printf("quarto\n");
            }
        } else {
            if(y > 0) {
                (void)printf("segundo\n");
            } else {
                (void)printf("terceiro\n");
            }
        }
    }
    return 0;
}