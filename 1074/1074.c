#include <stdio.h>

int main(int argv, char** argc) {
    int instancias, x;

    scanf("%d", &instancias);
    while(instancias > 0) {
        scanf("%d", &x);
        if(x != 0) {
            if(x & 0x00000001) {
                if(x >> 31) {
                    (void)printf("ODD NEGATIVE\n");
                } else {
                    (void)printf("ODD POSITIVE\n");
                }
            } else {
                if(x >> 31) {
                    (void)printf("EVEN NEGATIVE\n");
                } else {
                    (void)printf("EVEN POSITIVE\n");
                }
            }

        } else {
            (void)printf("NULL\n");
        }
        instancias--;
    }
    return 0;
}