/*
Problema: (A) Brazil and Germany
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Basta calcular separadamente as frações inteiras e o resto do tempo dividido por 90 minutos.
*/

#include <stdlib.h>
#include <stdio.h>

#define DURACAO_PARTIDA (90)

int main(int argv, char** argc) {
    unsigned int tempo, golsBrasil, golsAlemanha;

    // Lê a primeira instância.
    scanf("%u", &tempo);
    // Executa enquanto o tempo for diferente de zero.
    while(tempo != 0) {
        // Calcula o número de gols do Brasil, arredondado para baixo.
        golsBrasil = tempo / DURACAO_PARTIDA;
        // Calcula o número de gols da Alemanha, arredondado para cima.
        tempo *= 7;
        golsAlemanha = tempo / DURACAO_PARTIDA;
        if(tempo % DURACAO_PARTIDA) {
            golsAlemanha++;
        }
        // Imprime o resultado da instância.
        printf("Brasil %u x Alemanha %u\n", golsBrasil, golsAlemanha);
        // Lê o tempo da próxima instância.
        scanf("%u", &tempo);
    }
    return 0;
}
