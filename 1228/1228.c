/*
Problema: Grid de Largada (URI-1246)

Leio os dois vetores. Em seguida, ordeno o segundo utilizando a ordem relativa listada no primeiro.
Para saber o número de ultrapassagens, basta contar o número de trocas para ordenar o vetor.
O algoritmo utilizado pega o primeiro elemento e busca no vetor. Neste ponto, é parecido com o
Selection Sort, com a vantagem de saber qual o elemento que é o menor buscado, eliminando a
necessidade de percorrer todo o vetor. Quando ele é encontrado, é permutado até chegar no lugar.
Cada permutação incrementa o contador.
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
        // Lê o grid de largada.
        for(i = 0; i < numPilotos; i++) {
            scanf("%u", &(ordemLargada[i]));
        }
        // Lê o grid de chegada.
        for(i = 0; i < numPilotos; i++) {
            scanf("%u", &(ordemChegada[i]));
        }
        // Ordena o grid de chegada, com base no grid de largada. O número de permutações é o número 
        // de ultrapassagens.
        numUltrapassagens = 0;
        for(i = 0; i < numPilotos; i++) {
            pilotoAtual = ordemLargada[i];
            j = i;
            while(ordemChegada[j] != pilotoAtual) {
                j++;
            }
            // Soma o número de ultrapassagens necessárias.
            numUltrapassagens += j - i;
            // Realiza as permutações para colocar o piloto no lugar.
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