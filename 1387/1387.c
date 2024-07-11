#include <stdio.h>

int main(int argv, char **argc) {
    int l, r;

    (void)scanf("%d %d", &l, &r);
    while(l != 0 && r != 0) {
        (void)printf("%d\n", l + r);
        (void)scanf("%d %d", &l, &r);
    }
    return 0;
}
