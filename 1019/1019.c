#include <stdio.h>

int main(int argv, char** argc) {
    int hours, minutes, seconds;

    (void)scanf("%d", &seconds);

    minutes = seconds / 60;
    seconds %= 60;
    hours = minutes / 60;
    minutes %= 60;

    (void)printf("%d:%d:%d\n", hours, minutes, seconds);
    return 0;
}