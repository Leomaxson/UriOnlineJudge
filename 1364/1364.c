#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMOTICONS (100)
#define MAX_TAM_EMOTICON (20)
#define MAX_TEXTO (100)
#define MAX_TAM_TEXTO (100)
#define MAX_INTERVALOS (10000)

// Entrada de uma instância.
typedef struct SEntrada {
  char Texto[MAX_TEXTO][MAX_TAM_TEXTO];
  char Emoticons[MAX_EMOTICONS][MAX_TAM_EMOTICON];
  int NumLinhas;
  int NumEmoticons;
} Entrada;

void LeEntrada(Entrada *entrada) {
  int i;

  scanf("%d %d", &entrada->NumEmoticons, &entrada->NumLinhas);
  if(entrada->NumEmoticons != 0 || entrada->NumLinhas != 0) {
    for(i = 0; i < entrada->NumEmoticons; i++) {
      scanf("%s", entrada->Emoticons[i]);
    }
    getchar();
    for(i = 0; i < entrada->NumLinhas; i++) {
      fgets(entrada->Texto[i], MAX_TAM_TEXTO, stdin);
    }
  }
}

// Intervalo de aparecimento de um emoticon.
typedef struct SIntervalo {
  int Inicio;
  int Fim;
} Intervalo;

int ComparaIntervalo(const void *a, const void *b) {
  int aux;

  aux = ((Intervalo*)a)->Fim - ((Intervalo*)b)->Fim;
  if(aux == 0) {
    return ((Intervalo*)a)->Inicio - ((Intervalo*)b)->Inicio;
  }
  return aux;
}

int BuscaEmoticonsLinha(Entrada *entrada, Intervalo *intervalos, int linha) {
  int i, numIntervalos, tamEmoticon;
  char *posLinha;

  numIntervalos = 0;
  for(i = 0; i < entrada->NumEmoticons; i++) {
    tamEmoticon = strlen(entrada->Emoticons[i]);
    posLinha = entrada->Texto[linha];
    while((posLinha = strstr(posLinha, entrada->Emoticons[i])) != NULL) {
      intervalos[numIntervalos].Inicio = posLinha - entrada->Texto[linha];
      intervalos[numIntervalos].Fim = intervalos[numIntervalos].Inicio + tamEmoticon - 1;
      numIntervalos++;
      posLinha++;
    }
  }
  return numIntervalos;
}

int main() {
  int numIntervalos, numSubstituicoes, i, j, ultimaSubst;
  Entrada entrada;
  Intervalo intervalos[MAX_INTERVALOS];

  // Lê a primeira instância.
  LeEntrada(&entrada);
  while(entrada.NumEmoticons != 0 || entrada.NumLinhas != 0) {
    numSubstituicoes = 0;
    // Calcula linha a linha.
    for(i = 0; i < entrada.NumLinhas; i++) {
      // Busca todos os intervalos contendo os emoticons em uma linha e ordena.
      numIntervalos = BuscaEmoticonsLinha(&entrada, intervalos, i);
      qsort(intervalos, numIntervalos, sizeof(Intervalo), ComparaIntervalo);
      // Conta quantas mudanças são necessárias para a linha.
      ultimaSubst = -1;
      for(j = 0; j < numIntervalos; j++) {
        if(intervalos[j].Inicio > ultimaSubst) {
          ultimaSubst = intervalos[j].Fim;
          numSubstituicoes++;
        }
      }
    }
    // Imprime o resultado.
    i = printf("%d\n", numSubstituicoes);
    // Lê a próxima instância.
    LeEntrada(&entrada);
  }
  return 0;
}