/*
Problema: Mergulho (URI-1471)
Leonardo Maxson Bernardes Costa de Assis - 2014043110

Determino o n�mero de volunt�rios. Em seguida vou marcando em um vetor de flags cada um que
retornou. Para determinar quem n�o retornou, percorro novamente o vetor.
*/

#include <stdio.h>

#define MAX_VOLUNTARIOS 10000 + 1

int main(int argv, char** argc) {
    unsigned char voluntarios[MAX_VOLUNTARIOS];
    unsigned int numVoluntarios, totalVoluntarios, voluntario;

    while(1) {
      // L� o total de volunt�rios e zera o vetor at� a posi��o.
        (void)scanf("%u", &totalVoluntarios);
        if(feof(stdin)) {
            break;
        }
        for(voluntario = 1; voluntario <= totalVoluntarios; voluntario++) {
            voluntarios[voluntario] = 0;
        }
        // L� o n�mero de volunt�rios que retornaram e as placas deles.
        (void)scanf("%u", &numVoluntarios);
        if(numVoluntarios == totalVoluntarios) {
          // Se todos os volunt�rios retornaram, n�o precisa marcar quais voltaram.
            while(numVoluntarios) {
                (void)scanf("%*u");
                numVoluntarios--;
            }
            (void)printf("*\n");
        } else {
          // Marca quais voltaram.
            while(numVoluntarios) {
                (void)scanf("%u", &voluntario);
                voluntarios[voluntario] = 1;
                numVoluntarios--;
            }
            // Imprime os que n�o voltaram.
            for(voluntario = 1; voluntario <= totalVoluntarios; voluntario++) {
                if(voluntarios[voluntario] == 0) {
                    (void)printf("%u ", voluntario);
                }
            }
            (void)printf("\n");
        }
    }
    return 0;
}