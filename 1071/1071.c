#include <stdio.h>
#include <stdlib.h>

int main() {
    int v1, v2, aux;

    scanf("%d %d", &v2, &aux);
    v1 = min(v2, aux);
    v2 = max(v2, aux);
    if(v1 % 2 == 0) {
        v1++;
    }
    aux = 0;
    while(v1 < v2) {
        aux += v1;
        v1 += 2;
    }

    return 0;
}