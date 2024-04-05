#include <stdio.h>

int modulo(int a) {
    if(a < 0) {
        return -a;
    }
    return a;
}

typedef struct SFracao {
    int Numerador;
    int Denominador;
} Fracao;

int mdc(Fracao f) {
    int dividendo, divisor, resto;

    dividendo = modulo(f.Numerador);
    divisor = modulo(f.Denominador);
    if(divisor > dividendo) {
        resto = dividendo;
        dividendo = divisor;
        divisor = resto;
    }
    resto = 1;
    while(resto != 0) {
        resto = dividendo % divisor;
        dividendo = divisor;
        divisor = resto;
    };
    return dividendo;
}

Fracao Fracao_Simplifica(Fracao f) {
    int fator;
    Fracao simplificada;

    fator = mdc(f);
    simplificada.Numerador = f.Numerador / fator;
    simplificada.Denominador = f.Denominador / fator;
    return simplificada;
}

Fracao Fracao_Soma(Fracao f1, Fracao f2) {
    Fracao resultado;

    resultado.Numerador = f1.Numerador * f2.Denominador + f2.Numerador * f1.Denominador;
    resultado.Denominador = f1.Denominador * f2.Denominador;
    return resultado;
}

Fracao Fracao_Subtrai(Fracao f1, Fracao f2) {
    Fracao resultado;

    resultado.Numerador = f1.Numerador * f2.Denominador - f2.Numerador * f1.Denominador;
    resultado.Denominador = f1.Denominador * f2.Denominador;
    return resultado;
}

Fracao Fracao_Multiplica(Fracao f1, Fracao f2) {
    Fracao resultado;

    resultado.Numerador = f1.Numerador * f2.Numerador;
    resultado.Denominador = f1.Denominador * f2.Denominador;
    return resultado;
}

Fracao Fracao_Divide(Fracao f1, Fracao f2) {
    Fracao resultado;

    resultado.Numerador = f1.Numerador * f2.Denominador;
    resultado.Denominador = f2.Numerador * f1.Denominador;
    return resultado;
}

int main(int argv, char** argc) {
    unsigned int numInstancias;
    Fracao f1, f2;
    char op;

    // Lê o número de instâncias.
    (void)scanf("%d", &numInstancias);
    while(numInstancias) {
        // Lê as duas frações e a operação.
        (void)scanf("%d / %d %c %d / %d", &f1.Numerador, &f1.Denominador, &op, &f2.Numerador, &f2.Denominador);
        // Opera, de acordo com o op.
        switch(op) {
            case '+':
                f1 = Fracao_Soma(f1, f2);
                break;
            case '-':
                f1 = Fracao_Subtrai(f1, f2);
                break;
            case '*':
                f1 = Fracao_Multiplica(f1, f2);
                break;
            case '/':
                f1 = Fracao_Divide(f1, f2);
                break;
        }
        // Calcula a fração simplificada.
        f2 = Fracao_Simplifica(f1);
        // Imprime o resultado.
        (void)printf("%d/%d = %d/%d\n", f1.Numerador, f1.Denominador, f2.Numerador, f2.Denominador);
        numInstancias--;
    }
    return 0;
}