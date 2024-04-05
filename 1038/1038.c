#include <stdio.h>

double getPrecoItem(int codItem) {
    double precos[] = { 0.00, 4.00, 4.50, 5.00, 2.00, 1.50 };

    if(codItem > 0 && codItem <= 5) {
        return precos[codItem];
    }
    return precos[0];
}

int main(int argv, char** argc) {
    int codItem, quant;

    (void)scanf("%d %d", &codItem, &quant);
    (void)printf("Total: R$ %.2lf\n", getPrecoItem(codItem) * quant);
    return 0;
}