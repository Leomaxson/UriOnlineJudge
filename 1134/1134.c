#include <stdio.h>

#define ALCOOL   (1)
#define GASOLINA (2)
#define DIESEL   (3)
#define FIM      (4)

int main(int argv, char** argc) {
    unsigned int entrada, alcool, gasolina, diesel;
    
    alcool = gasolina = diesel = 0;
    do {
        (void)scanf("%u", &entrada);
        switch(entrada) {
            case ALCOOL:
                alcool++;
                break;
            case GASOLINA:
                gasolina++;
                break;
            case DIESEL:
                diesel++;
                break;
        }
    } while(entrada != FIM);
    (void)printf("MUITO OBRIGADO\nAlcool: %u\nGasolina: %u\nDiesel: %u\n", alcool, gasolina, diesel);
    return 0;
}