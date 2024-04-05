#include <stdlib.h>
#include <stdio.h>

#define MAX_ATRACOES (100)
#define MAX_TEMPO (600)

#define max(a,b) (((a) > (b)) ? (a) : (b))

int resolveMochilaIlimitada(int capacidade, int numItens, int lucroItens[], int pesoItens[]) {
  int mochilasParciais[MAX_TEMPO + 1], i, j;

  // Inicializa o vetor.
  for(i = 0; i <= capacidade; i++) {
    mochilasParciais[i] = 0;
  }
  // Calcula as mochilas parciais uma a uma.
  for(i = 0; i <= capacidade; i++) {
    for(j = 0; j < numItens; j++) {
      if(pesoItens[j] <= i) {
        mochilasParciais[i] = max(mochilasParciais[i], mochilasParciais[i - pesoItens[j]] + lucroItens[j]);
      }
    }
  }
  return mochilasParciais[capacidade];
}

// main
int main() {
  int instancia, numAtracoes, tempoDisponivel, i, pontuacao;
  int tempoAtracoes[MAX_ATRACOES], pontosAtracoes[MAX_ATRACOES];

  // Lê a primeira instância.
  scanf("%d %d", &numAtracoes, &tempoDisponivel);
  instancia = 1;
  while(numAtracoes > 0) {
    // Lê os valores das atrações.
    for(i = 0; i < numAtracoes; i++) {
      scanf("%d %d", &tempoAtracoes[i], &pontosAtracoes[i]);
    }
    // Encontra a maior pontuação possível.
    pontuacao = resolveMochilaIlimitada(tempoDisponivel, numAtracoes, pontosAtracoes, tempoAtracoes);
    // Imprime o resultado.
    printf("Instancia %d\n%d\n\n", instancia, pontuacao);
    // Lê a próxima instância.
    scanf("%d %d", &numAtracoes, &tempoDisponivel);
    instancia++;
  }
  return 0;
}