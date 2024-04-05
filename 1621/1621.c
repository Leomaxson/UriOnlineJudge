#include <stdlib.h>
#include <stdio.h>

typedef struct SPosicao {
  int Coluna;
  int Linha;
} Posicao;

typedef struct SItem {
  Posicao Posicao;
  Posicao PosicaoAnt;
  int Distancia;
} Item;

typedef struct SFila {
  Item * Itens;
  int Inicio;
  int Fim;
  int TamanhoFila;
} Fila;

void Fila_Cria(Fila * fila, int tamanhoFila) {
  fila->TamanhoFila = tamanhoFila;
  fila->Inicio = 0;
  fila->Fim = 0;
  fila->Itens = (Item *)malloc(tamanhoFila * sizeof(Item));
}

void Fila_Destroi(Fila * fila) {
  fila->TamanhoFila = 0;
  fila->Inicio = 0;
  fila->Fim = 0;
  free(fila->Itens);
}

unsigned int Fila_Vazia(Fila * fila) {
  if(fila->Inicio == fila->Fim) {
    return 1;
  }
  return 0;
}

void Fila_Enfilera(Fila * fila, Item item) {
  fila->Itens[fila->Fim] = item;
  fila->Fim = (fila->Fim + 1) % fila->TamanhoFila;
}

Item Fila_Desenfilera(Fila * fila) {
  Item item;

  item = fila->Itens[fila->Inicio];
  fila->Inicio = (fila->Inicio + 1) % fila->TamanhoFila;
  return item;
}


int main() {
  int numLinhas, numColunas, i, j, trocouMax, maiorDistancia;
  char ** labirinto;
  Item item, itemAnt, itemMax;
  Fila fila;

  // L� os tamanhos da primeira inst�ncia.
  scanf("%d %d", &numLinhas, &numColunas);
  while(numLinhas != 0 || numColunas != 0) {
    // Aloca a matriz do labirinto.
    labirinto = (char **)malloc(numLinhas * sizeof(char *));
    for(i = 0; i < numLinhas; i++) {
      labirinto[i] = (char *)malloc(numColunas * sizeof(char) + 1);
    }
    // Faz a leitura do labirinto.
    for(i = 0; i < numLinhas; i++) {
      scanf("%s", labirinto[i]);
    }
    // Encontra um v�rtice para come�ar a busca.
    itemMax.Distancia = -1;
    for(i = 0; i < numLinhas; i++) {
      for(j = 0; j < numColunas; j++) {
        if(labirinto[i][j] == '.') {
          itemMax.Distancia = 0;
          itemMax.Posicao.Linha = i;
          itemMax.Posicao.Coluna = j;
          itemMax.PosicaoAnt = itemMax.Posicao;
          break;
        }
      }
      if(itemMax.Distancia == 0) {
        break;
      }
    }
    // Cria a fila.
    Fila_Cria(&fila, numLinhas * numColunas);
    // Fica no loop navegando enquanto trocar a maior dist�ncia.
    trocouMax = 1;
    maiorDistancia = 0;
    while(trocouMax) {
      // Come�a a partir do v�rtice de maior dist�ncia da itera��o anterior (na primeira definido em zero).
      Fila_Enfilera(&fila, itemMax);
      // Faz o caminhamento em largura, atualizando o v�rtice de maior dist�ncia se for o caso.
      while(!Fila_Vazia(&fila)) {
        // Pega o v�rtice da fila e j� ajusta elementos do pr�ximo.
        itemAnt = Fila_Desenfilera(&fila);
        item.Posicao = itemAnt.Posicao;
        item.PosicaoAnt = itemAnt.Posicao;
        item.Distancia = itemAnt.Distancia + 1;
        // Verifica os v�rtices dispon�veis para navega��o. Enfileira eles se poss�vel.
        // Cima.
        item.Posicao.Linha--;
        if(itemAnt.Posicao.Linha - 1 != itemAnt.PosicaoAnt.Linha &&
          item.Posicao.Linha >= 0 &&
          labirinto[item.Posicao.Linha][item.Posicao.Coluna] == '.') {
          Fila_Enfilera(&fila, item);
          if(item.Distancia > itemMax.Distancia) {
            itemMax = item;
          }
        }
        item.Posicao.Linha++;
        // Baixo.
        item.Posicao.Linha++;
        if(itemAnt.Posicao.Linha + 1 != itemAnt.PosicaoAnt.Linha &&
          item.Posicao.Linha < numLinhas &&
          labirinto[item.Posicao.Linha][item.Posicao.Coluna] == '.') {
          Fila_Enfilera(&fila, item);
          if(item.Distancia > itemMax.Distancia) {
            itemMax = item;
          }
        }
        item.Posicao.Linha--;
        // Esquerda.
        item.Posicao.Coluna--;
        if(itemAnt.Posicao.Coluna - 1 != itemAnt.PosicaoAnt.Coluna &&
          item.Posicao.Coluna >= 0 &&
          labirinto[item.Posicao.Linha][item.Posicao.Coluna] == '.') {
          Fila_Enfilera(&fila, item);
          if(item.Distancia > itemMax.Distancia) {
            itemMax = item;
          }
        }
        item.Posicao.Coluna++;
        // Direita.
        item.Posicao.Coluna++;
        if(itemAnt.Posicao.Coluna + 1 != itemAnt.PosicaoAnt.Coluna &&
          item.Posicao.Coluna < numColunas &&
          labirinto[item.Posicao.Linha][item.Posicao.Coluna] == '.') {
          Fila_Enfilera(&fila, item);
          if(item.Distancia > itemMax.Distancia) {
            itemMax = item;
          }
        }
        item.Posicao.Coluna--;
      }
      // Verifica se a dist�ncia do item � maior que a global.
      if(itemMax.Distancia > maiorDistancia) {
        maiorDistancia = itemMax.Distancia;
        trocouMax = 1;
      } else {
        trocouMax = 0;
      }
      // Deixa s� a posi��o no item de maior dist�ncia.
      itemMax.PosicaoAnt = itemMax.Posicao;
      itemMax.Distancia = 0;
    }
    // Destroi a fila.
    Fila_Destroi(&fila);
    // Imprime a resposta da maior dist�ncia.
    printf("%d\n", maiorDistancia);
    // L� os tamanhos da pr�xima inst�ncia.
    scanf("%d %d", &numLinhas, &numColunas);
  }
  return 0;
}