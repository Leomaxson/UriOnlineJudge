#include <stdio.h>

#define VAGA_VAZIA 0

int main() {
  unsigned int tamanhoEstacionamento, i, faturamento, placa, numRegistros;
  unsigned char tamanhoVeiculo, espaco;
  char registro;
  unsigned int vagas[1000];

  // Esvazia o estacionamento antes de começar a instância.
  for(i = 0; i < tamanhoEstacionamento; i++) {
    vagas[i] = VAGA_VAZIA;
  }
  // Lê cada um dos registros.
  while(numRegistros > 0) {
    if(registro == 'S') {
      // Procedimento de saída. Busca o veículo no estacionamento e marca o espaço dele como "vago".
      i = 0;
      while(i < tamanhoEstacionamento) {
        if(vagas[i] == placa) {
          while(vagas[i] == placa) {
            vagas[i] = VAGA_VAZIA;
            i++;
          }
          break;
        }
        i++;
      }
    } else {
      // Procedimento de chegada. Busca um espaço que caiba o veículo. Se encontrar, marca como 
      // "ocupado" e incrementa o faturamento.
      for(i = 0; i < tamanhoEstacionamento; i++) {
        // Se a vaga está vazia, incrementa o espaço acumulado, senão, zera ele novamente.
        if(vagas[i] == VAGA_VAZIA) {
          espaco++;
        } else {
          espaco = 0;
        }
        // Se o espaço acumulado até aqui cabe o veículo, marca aquele espaço com o veículo, incrementa 
        // o faturamento e sai.
        if(espaco == tamanhoVeiculo) {
          while(espaco) {
            vagas[i] = placa;
            espaco--;
            i--;
          }
          faturamento += 10;
          break;
        }
      }
    }
    numRegistros--;
  }
  return 0;
}
