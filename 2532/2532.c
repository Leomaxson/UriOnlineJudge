#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct SControleArvoreBusca {
    int *DanoMagia;
    int *ManaMagia;
    int NumMagias;
    int VidaTotal;
    int VidaAtual;
    int ManaAtual;
    int MinMana;
} ControleArvoreBusca;

void navegaArvoreBusca(ControleArvoreBusca * controle, int inicioBusca) {
    int i;

    for(i = inicioBusca; i < controle->NumMagias; i++) {
        // Se vai ser maior ou igual ao m�nimo j� encontrado, corta o ramo da �rvore.
        if(controle->ManaAtual + controle->ManaMagia[i] >= controle->MinMana) {
            continue;
        }
        // Se deu o total de vida do monstro, atualiza o m�nimo de mana.
        if(controle->VidaAtual + controle->DanoMagia[i] >= controle->VidaTotal) {
            controle->MinMana = controle->ManaAtual + controle->ManaMagia[i];
        } else {
            // Sen�o, adiciona a magia e chama recursivamente a partir da pr�xima.
            controle->VidaAtual += controle->DanoMagia[i];
            controle->ManaAtual += controle->ManaMagia[i];
            navegaArvoreBusca(controle, i + 1);
            controle->VidaAtual -= controle->DanoMagia[i];
            controle->ManaAtual -= controle->ManaMagia[i];
        }
    }
}

int main(int argv, char** argc) {
    int i;
    ControleArvoreBusca controle;

    while(!feof(stdin)) {
        // L� os tamanhos da inst�ncia.
        scanf("%d %d", &controle.NumMagias, &controle.VidaTotal);
        if(feof(stdin)) {
            break;
        }
        // L� a inst�ncia.
        controle.ManaMagia = (int *)malloc(controle.NumMagias * sizeof(int));
        controle.DanoMagia = (int *)malloc(controle.NumMagias * sizeof(int));
        for(i = 0; i < controle.NumMagias; i++) {
            scanf("%d %d", &controle.DanoMagia[i], &controle.ManaMagia[i]);
        }
        // Prepara o caminhamento na �rvore de busca.
        controle.ManaAtual = 0;
        controle.VidaAtual = 0;
        controle.MinMana = INT_MAX;
        // Navega na �rvore de busca, come�ando da magia de �ndice zero.
        navegaArvoreBusca(&controle, 0);
        // Verifica o resultado.
        if(controle.MinMana == INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n", controle.MinMana);
        }
        // Desaloca a mem�ria.
        free(controle.ManaMagia);
        free(controle.DanoMagia);
    }
    return 0;
}