#include <stdio.h>

#define MAX_CIDADES 50
// Cidades
#define NAO_VISITADO 0
#define VISITADO 1
// Pontes
#define VAZIA 0
#define PONTE 1

void navegaDFS(int numCidades, unsigned char pontes[MAX_CIDADES][MAX_CIDADES],
  unsigned char cidades[MAX_CIDADES], int cidadeAtual) {
  int i;

  cidades[cidadeAtual] = VISITADO;
  for(i = 0; i < numCidades; i++) {
    if(pontes[cidadeAtual][i] != VAZIA) {  // Se a cidade est� adjacente.
      if(cidades[i] != VISITADO) {
        navegaDFS(numCidades, pontes, cidades, i);
      }
    }
  }
}

int contabilizaFlorestas(int numCidades, unsigned char pontes[MAX_CIDADES][MAX_CIDADES]) {
  unsigned char cidades[MAX_CIDADES];
  int florestas, i;

  // Inicializa as cidades.
  for(i = 0; i < numCidades; i++) {
    cidades[i] = NAO_VISITADO;
  }

  // Contabiliza as florestas pelo n�mero de recurs�es da DFS.
  florestas = 0;
  for(i = 0; i < numCidades; i++) {
    if(cidades[i] == NAO_VISITADO) {
      florestas++;
      (void)navegaDFS(numCidades, pontes, cidades, i);
    }
  }
  return florestas;
}

int main() {
  unsigned char pontes[MAX_CIDADES][MAX_CIDADES];
  int numCidades, numPontes, numFlorestas, numFlorestasAnterior, i, j;
  FILE * entrada;

  //entrada = fopen("entrada.txt", "r");
  entrada = stdin;

  while(!feof(entrada)) {
    // L� as dimens�es da inst�ncia.
    (void)fscanf(entrada, "%d %d", &numCidades, &numPontes);
    if(feof(entrada)) {
      return 0;
    }

    // Inicializa as pontes.
    for(i = 0; i < numCidades; i++) {
      for(j = 0; j < numCidades; j++) {
        pontes[i][j] = VAZIA;
      }
    }

    // L� a inst�ncia.
    while(numPontes > 0) {
      (void)fscanf(entrada, "%d %d", &i, &j);
      i--;  // Decremento para come�ar os �ndices do zero.
      j--;  // Decremento para come�ar os �ndices do zero.
      pontes[i][j] = pontes[j][i] = PONTE;
      numPontes--;
    }

    // Caminha inicialmente para contabilizar o n�mero de florestas.
    numFlorestas = numFlorestasAnterior = contabilizaFlorestas(numCidades, pontes);

    // Remove sequencialmente cada uma das arestas. Se o n�mero de florestas 
    // aumentou, o n�mero de pontes aumentou.
    numPontes = 0;
    for(i = 0; i < numCidades; i++) {
      for(j = i + 1; j < numCidades; j++) {
        if(pontes[i][j] != VAZIA) {
          pontes[j][i] = pontes[i][j] = VAZIA;
          numFlorestas = contabilizaFlorestas(numCidades, pontes);
          if(numFlorestas > numFlorestasAnterior) {
            numPontes++;
          }
          pontes[j][i] = pontes[i][j] = PONTE;
        }
      }
    }

    // Imprime o resultado.
    (void)printf("%d\n", numPontes);
  }
  return 0;
}