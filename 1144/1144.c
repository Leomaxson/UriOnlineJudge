#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int entrada, i, i_2, i_3;

    (void)scanf("%u", &entrada);
    for(i = 1; i <= entrada; i++) {
        i_2 = i * i;
        i_3 = i_2 * i;
        (void)printf("%u %u %u\n%u %u %u\n", 
                     i, 
                     i_2, 
                     i_3, 
                     i, 
                     i_2 + 1, 
                     i_3 + 1);
    }
    return 0;
}