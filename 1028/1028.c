#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc) {
    unsigned int numInstancias, num1, num2, resto;

    // L� o n�mero de inst�ncias.
    (void)scanf("%u", &numInstancias);
    while(numInstancias) {
      // L� os dois n�meros da inst�ncia.
        (void)scanf("%u %u", &num1, &num2);
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
        (void)printf("%u\n", num1);
        numInstancias--;
    }
    return 0;
}