#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned int numInstancias, num1, num2, resto;

    // Lê o número de instâncias.
    scanf("%u", &numInstancias);
    while(numInstancias) {
      // Lê os dois números da instância.
        scanf("%u %u", &num1, &num2);
        if(num2 > num1) {
            resto = num1;
            num1 = num2;
            num2 = resto;
        }
        // Calcula o MDC.
        resto = 1;
        while(resto != 0) {
            resto = num1 % num2;
            num1 = num2;
            num2 = resto;
        }
        // Imprime o resultado.
        printf("%u\n", num1);
        numInstancias--;
    }
    return 0;
}