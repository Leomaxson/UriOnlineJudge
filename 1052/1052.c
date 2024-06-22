#include <stdio.h>

const char *NOMES_MESES[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

int main(int argv, char **argc) {
    int mes;

    (void)scanf("%d", &mes);
    mes--;
    (void)printf("%s\n", NOMES_MESES[mes]);
    return 0;
}