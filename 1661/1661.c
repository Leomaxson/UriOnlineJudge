#include <stdio.h>

int main(int argv, char** argc) {
    char instancia;
    int numHabitantes, compras;
    long long trabalho, estado;
    FILE *in;

    // Faz a leitura do número de habitantes da primeira instância.
    instancia = 1;
    in = fopen("teste.txt", "r");
    while(instancia) {
        fscanf(in, "%d", &numHabitantes);
        // (void)scanf("%d", &numHabitantes);
        if(numHabitantes) {
            trabalho = 0;
            estado = 0;
            while(numHabitantes) {
                fscanf(in, "%d", &compras);
                // (void)scanf("%d", &compras);
                estado += compras;
                if(estado > 0) {
                    trabalho += estado;
                } else {
                    trabalho -= estado;
                }
                numHabitantes--;
            }
            (void)printf("%d\n", trabalho);
        } else {
            instancia = 0;
        }
    }
    return 0;
}
