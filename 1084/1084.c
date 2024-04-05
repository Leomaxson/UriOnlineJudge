#include <stdio.h>

#define MAX_DIGITOS 100000

int main(int argv, char** argc) {
    int d, n, i, j, pos;
    char numero[MAX_DIGITOS + 1], digito, encontrou;

    while(1) {
      // Lê os tamanhos da instância e verifica se não é a condição de término.
        scanf("%i %i", &d, &n);
        if(d == 0 && n == 0) {
            break;
        }
        // Lê os dígitos do número.
        scanf("%s", &numero);
        /*pos = 0;
        for(digito = '9'; digito >= '1'; digito--) {
          for(i = pos; i <= pos + n; i++) {
            if(numero[i] == digito) {
              n -= i - pos;
              // TODO: Dá pra melhorar o n-- depois.
              while(pos < i) {
                numero[pos] = ' ';
                pos++;
              }
              digito = '9';
              pos++;
            }
          }
        }*/
        i = 0;
        j = 1;
        while(n) {
            if(numero[i] < numero[j]) {
                numero[i] = ' ';
                n--;
            }
            if(j == i) {
                j++;
            }
        }
        // Se ainda restou dígitos para retirar, é porque sobraram zeros.
        if(n) {
            for(i = 0; i < n; i++) {
                numero[pos + i] = ' ';
            }
        }
        // Compacta o número antes de mandar imprimir.
        i = 0;
        pos = 0;
        while(pos < d) {
            while(numero[pos] == ' ') {
                pos++;
            }
            numero[i] = numero[pos];
            i++;
            pos++;
        }
        numero[i] = '\0';
        printf("%s\n", numero);
    }
    return 0;
}
