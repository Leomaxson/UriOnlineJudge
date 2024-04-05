#include <stdlib.h>
#include <stdio.h>

#define MAX_ENDERECOS 100
#define MAX_CHAVES    200

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main() {
    unsigned int instancias;
    unsigned int numEnderecos, numChaves, chave, endereco, i, j;
    unsigned int hash[MAX_ENDERECOS][MAX_CHAVES + 1];

    (void)scanf("%u", &instancias);
    while(instancias > 0) {
        (void)scanf("%u %u", &numEnderecos, &numChaves);
        // Inicializa o hash.
        for(i = 0; i < numEnderecos; i++) {
            hash[i][0] = 0;
        }
        // Preenche o hash com as chaves.
        for(i = 0; i < numChaves; i++) {
          // Lê a próxima chave.
            (void)scanf("%u", &chave);
            endereco = chave % numEnderecos;
            // Acha uma posição no hash para a chave.
            j = 0;
            while(hash[endereco][j] != 0) {
                j++;
            }
            // Insere a chave no hash.
            hash[endereco][j] = chave;
            hash[endereco][j + 1] = 0;
        }
        // Imprime o hash.
        for(i = 0; i < numEnderecos; i++) {
            (void)printf("%u -> ", i);
            j = 0;
            while(hash[i][j] != 0) {
                (void)printf("%u -> ", hash[i][j]);
                j++;
            }
            (void)printf("\\\n");
        }
        instancias--;
        // Coloca um espacinho entre uma instância e outra.
        if(instancias > 0) {
            (void)printf("\n");
        }
    }
    return 0;
}