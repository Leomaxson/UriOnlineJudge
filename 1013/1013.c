#include <stdlib.h>
#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main(int argv, char** argc) {
    int a, b, c;

    (void)scanf("%d %d %d", &a, &b, &c);
    (void)printf("%d eh o maior\n", max(a, max(b, c)));
    return 0;
}