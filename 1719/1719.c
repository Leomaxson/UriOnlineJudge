#include <stdio.h>

#define TAMANHO_MEMORIA 32   // Tamanho da mem�ria do processador.
#define TAMANHO_INSTRUCAO 8  // Tamanho da instru��o, em bits, do processador.

typedef struct SProcessador {
  unsigned char Memoria[TAMANHO_MEMORIA];
  unsigned char Acumulador;
  unsigned char PC;
} Processador;

/**
 * Converte uma string representado uma instru��o em bin�rio para a instru��o propriamente.
 * @param leitura String representando a instru��o em bin�rio.
 * @return Retorna a instru��o convertida.
 */
unsigned char ConverteStringInstrucao(char leitura[TAMANHO_INSTRUCAO + 1]) {
  unsigned char i, instrucao;
  instrucao = 0;
  for(i = 0; i < TAMANHO_INSTRUCAO; i++) {
    if(leitura[i] == '1') {
      instrucao += 1 << (TAMANHO_INSTRUCAO - 1 - i);
    }
  }
  return instrucao;
}

/**
 * Ponto de entrada para o programa. Executa o la�o principal do processador, recebendo uma
 * inst�ncia por vez.
 * @return Retorna sempre zero.
 */
int main() {
  Processador p;
  unsigned char instrucao, posicaoMemoria, i;
  char leitura[TAMANHO_INSTRUCAO + 1];

  // Carrega uma inst�ncia para o processador. Se conseguir ler uma linha da inst�ncia para a 
  // mem�ria, l� as outras 31.
  while(fgets(leitura, TAMANHO_INSTRUCAO, stdin) != NULL) {
    p.Memoria[0] = ConverteStringInstrucao(leitura);
    for(i = 1; i < TAMANHO_MEMORIA; i++) {
      gets(leitura);
      p.Memoria[i] = ConverteStringInstrucao(leitura);
    }

    // Inicializa o processador e a condi��o de sa�da do la�o de execu��o.
    p.PC = 0;
    p.Acumulador = 0;
    i = 1;  // Condi��o utilizada para o t�rmino da execu��o (instru��o HLT).
    while(i) {
      // Busca e decodifica a instru��o e a posi��o de mem�ria.
      instrucao = p.Memoria[p.PC] >> 5;
      posicaoMemoria = p.Memoria[p.PC] & 0x1f;
      // Incrementa o PC.
      if(p.PC == 31) {
        p.PC = 0;
      } else {
        p.PC++;
      }
      // Executa a instru��o, de acordo com o bytecode.
      switch(instrucao) {
        case 0:  // STA x
          p.Memoria[posicaoMemoria] = p.Acumulador;
          break;
        case 1:  // LDA x
          p.Acumulador = p.Memoria[posicaoMemoria];
          break;
        case 2:  // BEQ x
          if(p.Acumulador == 0) {
            p.PC = posicaoMemoria;
          }
          break;
        case 3:  // NOP
          break;
        case 4:  // DEC
          p.Acumulador--;
          break;
        case 5:  // INC
          p.Acumulador++;
          break;
        case 6:  // JMP x
          p.PC = posicaoMemoria;
          break;
        case 7:  // HLT
          // Imprime, em bin�rio, o valor do acumulador.
          for(i = 0; i < TAMANHO_INSTRUCAO; i++) {
            if((p.Acumulador >> i) & 0x01) {
              leitura[TAMANHO_INSTRUCAO - 1 - i] = '1';
            } else {
              leitura[TAMANHO_INSTRUCAO - 1 - i] = '0';
            }
          }
          leitura[TAMANHO_INSTRUCAO] = '\0';
          i = 0;
          break;
      }
    }
    printf("%s\n", leitura);
  }
  return 0;
}