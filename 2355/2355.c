/*
Problema: (A) Brazil and Germany
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Basta calcular separadamente as fra��es inteiras e o resto do tempo dividido por 90 minutos.
*/

#include <stdlib.h>
#include <stdio.h>

#define DURACAO_PARTIDA (90)

int main(int argv, char** argc) {
    unsigned int tempo, golsBrasil, golsAlemanha;

    // L� a primeira inst�ncia.
    scanf("%u", &tempo);
    // Executa enquanto o tempo for diferente de zero.
    while(tempo != 0) {
        // Calcula o n�mero de gols do Brasil, arredondado para baixo.
        golsBrasil = tempo / DURACAO_PARTIDA;
        // Calcula o n�mero de gols da Alemanha, arredondado para cima.
        tempo *= 7;
        golsAlemanha = tempo / DURACAO_PARTIDA;
        if(tempo % DURACAO_PARTIDA) {
            golsAlemanha++;
        }
        // Imprime o resultado da inst�ncia.
        printf("Brasil %u x Alemanha %u\n", golsBrasil, golsAlemanha);
        // L� o tempo da pr�xima inst�ncia.
        scanf("%u", &tempo);
    }
    return 0;
}
