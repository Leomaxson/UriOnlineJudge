#include <stdio.h>

int main() {
    int instancias, x;

    scanf("%d", &instancias);
    while(instancias > 0) {
        scanf("%d", &x);
        if(x != 0) {
            if(x & 0x00000001) {
                if(x >> 31) {
                    printf("ODD NEGATIVE\n");
                } else {
                    printf("ODD POSITIVE\n");
                }
            } else {
                if(x >> 31) {
                    printf("EVEN NEGATIVE\n");
                } else {
                    printf("EVEN POSITIVE\n");
                }
            }

        } else {
            printf("NULL\n");
        }
        instancias--;
    }
    return 0;
}