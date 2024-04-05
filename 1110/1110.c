#include <stdlib.h>
#include <stdio.h>

#define MAX_FILA (64)

typedef struct SFila {
    int Item[MAX_FILA];
    int Inicio;
    int Fim;
    int Tamanho;
} Fila;

void Fila_Cria(Fila * fila) {
    fila->Inicio = 0;
    fila->Fim = fila->Inicio;
    fila->Tamanho = 0;
}

void Fila_CriaInicializada(Fila * fila, int tam) {
    fila->Inicio = 0;
    for(fila->Fim = 0; fila->Fim < tam; fila->Fim++) {
        fila->Item[fila->Fim] = fila->Fim + 1;
    }
    fila->Tamanho = tam;
}

void Fila_Enfileira(Fila * fila, int x) {
    fila->Item[fila->Fim] = x;
    fila->Fim = (fila->Fim + 1) % MAX_FILA;
    fila->Tamanho++;
}

int Fila_Desenfileira(Fila * fila) {
    int item;

    item = fila->Item[fila->Inicio];
    fila->Inicio = (fila->Inicio + 1) % MAX_FILA;
    fila->Tamanho--;
    return item;
}

int main() {
    int tamanho, carta;
    Fila fila, filaDescarte;

    // Lê a primeira instância.
    scanf("%d", &tamanho);
    while(tamanho > 0) {
      // Inicializa as filas.
        Fila_CriaInicializada(&fila, tamanho);
        Fila_Cria(&filaDescarte);
        // Itera até que tenha apenas uma carta na fila.
        while(fila.Tamanho > 1) {
          // Retira uma.
            carta = Fila_Desenfileira(&fila);
            Fila_Enfileira(&filaDescarte, carta);
            // Passa a do topo pra base.
            carta = Fila_Desenfileira(&fila);
            Fila_Enfileira(&fila, carta);
        }
        // Mostra a lista de cartas descartadas.
        printf("Discarded cards: ");
        while(filaDescarte.Tamanho > 1) {
            carta = Fila_Desenfileira(&filaDescarte);
            printf("%d, ", carta);
        }
        carta = Fila_Desenfileira(&filaDescarte);
        printf("%d\n", carta);
        // Mostra a carta remanescente.
        carta = Fila_Desenfileira(&fila);
        printf("Remaining card: %d\n", carta);
        // Busca o tamanho da próxima instância.
        scanf("%d", &tamanho);
    }
    return 0;
}