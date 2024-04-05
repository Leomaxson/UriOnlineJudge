#include <stdio.h>

#define VAGA_VAZIA 0

int main() {
  unsigned int tamanhoEstacionamento, i, faturamento, placa, numRegistros;
  unsigned char tamanhoVeiculo, espaco;
  char registro;
  unsigned int vagas[1000];

  // Esvazia o estacionamento antes de come�ar a inst�ncia.
  for(i = 0; i < tamanhoEstacionamento; i++) {
    vagas[i] = VAGA_VAZIA;
  }
  // L� cada um dos registros.
  while(numRegistros > 0) {
    if(registro == 'S') {
      // Procedimento de sa�da. Busca o ve�culo no estacionamento e marca o espa�o dele como "vago".
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
      // Procedimento de chegada. Busca um espa�o que caiba o ve�culo. Se encontrar, marca como 
      // "ocupado" e incrementa o faturamento.
      for(i = 0; i < tamanhoEstacionamento; i++) {
        // Se a vaga est� vazia, incrementa o espa�o acumulado, sen�o, zera ele novamente.
        if(vagas[i] == VAGA_VAZIA) {
          espaco++;
        } else {
          espaco = 0;
        }
        // Se o espa�o acumulado at� aqui cabe o ve�culo, marca aquele espa�o com o ve�culo, incrementa 
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
