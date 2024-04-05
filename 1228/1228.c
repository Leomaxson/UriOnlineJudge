/*
Problema: Grid de Largada (URI-1246)

Leio os dois vetores. Em seguida, ordeno o segundo utilizando a ordem relativa listada no primeiro.
Para saber o n�mero de ultrapassagens, basta contar o n�mero de trocas para ordenar o vetor.
O algoritmo utilizado pega o primeiro elemento e busca no vetor. Neste ponto, � parecido com o
Selection Sort, com a vantagem de saber qual o elemento que � o menor buscado, eliminando a
necessidade de percorrer todo o vetor. Quando ele � encontrado, � permutado at� chegar no lugar.
Cada permuta��o incrementa o contador.
*/

#include <stdio.h>

#define MAX_PILOTOS 24

int main(int argv, char** argc) {
    unsigned int ordemLargada[MAX_PILOTOS], ordemChegada[MAX_PILOTOS];
    unsigned int numPilotos, i, j, numUltrapassagens, pilotoAtual;

    while(1) {
        scanf("%u", &numPilotos);
        if(feof(stdin)) {
            break;
        }
        // L� o grid de largada.
        for(i = 0; i < numPilotos; i++) {
            scanf("%u", &(ordemLargada[i]));
        }
        // L� o grid de chegada.
        for(i = 0; i < numPilotos; i++) {
            scanf("%u", &(ordemChegada[i]));
        }
        // Ordena o grid de chegada, com base no grid de largada. O n�mero de permuta��es � o n�mero 
        // de ultrapassagens.
        numUltrapassagens = 0;
        for(i = 0; i < numPilotos; i++) {
            pilotoAtual = ordemLargada[i];
            j = i;
            while(ordemChegada[j] != pilotoAtual) {
                j++;
            }
            // Soma o n�mero de ultrapassagens necess�rias.
            numUltrapassagens += j - i;
            // Realiza as permuta��es para colocar o piloto no lugar.
            while(j > i) {
                ordemChegada[j] = ordemChegada[j] ^ ordemChegada[j - 1];
                ordemChegada[j - 1] = ordemChegada[j] ^ ordemChegada[j - 1];
                ordemChegada[j] = ordemChegada[j] ^ ordemChegada[j - 1];
                j--;
            }
        }
        (void)printf("%u\n", numUltrapassagens);
    }
    return 0;
}