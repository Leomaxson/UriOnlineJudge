#include <stdlib.h>
#include <stdio.h>

#define MAX_ELEMENTOS 1024
#define INSERCAO 1
#define RETIRADA 2

// Estrutura correspondente à uma lista genérica.
typedef struct SLista {
    unsigned int Inicio, Fim;
    unsigned int Elementos[MAX_ELEMENTOS];
} Lista;
typedef Lista * PTLista;

// Inicializa uma lista genérica.
void Lista_Cria(PTLista lista) {
    lista->Inicio = lista->Fim = 0;
}

// Verifica se uma lista genérica está vazia.
unsigned char Lista_Vazia(PTLista lista) {
    if(lista->Inicio == lista->Fim) {
        return 1;
    }
    return 0;
}

// Insere um elemento em uma fila.
void Fila_Insere(PTLista lista, unsigned int elemento) {
    lista->Elementos[lista->Fim] = elemento;
    lista->Fim++;
    lista->Fim %= MAX_ELEMENTOS;
}

// Retira um elemento de uma fila.
unsigned int Fila_Retira(PTLista lista) {
    unsigned int elemento;

    elemento = lista->Elementos[lista->Inicio];
    lista->Inicio++;
    lista->Inicio %= MAX_ELEMENTOS;
    return elemento;
}

// Insere um elemento em uma pilha.
void Pilha_Insere(PTLista lista, unsigned int elemento) {
    lista->Elementos[lista->Fim] = elemento;
    lista->Fim++;
}

// Retira um elemento de uma pilha.
unsigned int Pilha_Retira(PTLista lista) {
    lista->Fim--;
    return lista->Elementos[lista->Fim];
}

// Acha a posição de inserção de um elemento em uma fila de prioridades.
unsigned int achaPosicao(PTLista lista, unsigned int elemento) {
    unsigned int a;

    a = lista->Inicio;
    while(elemento < lista->Elementos[a] && a < lista->Fim) {
        a++;
    }
    return a;
}

unsigned int achaPosicao2(PTLista lista, unsigned int elemento) {
    unsigned int inf, sup, meio;

    inf = lista->Inicio;
    sup = lista->Fim - 1;
    while(inf != sup) {
        meio = (inf + sup) / 2;
        if(inf > sup) {
            meio = (meio + (MAX_ELEMENTOS >> 1)) % MAX_ELEMENTOS;
        }
        if(elemento == lista->Elementos[meio]) {
            return meio;
        }
        if(elemento < lista->Elementos[meio]) {
            sup = (meio - 1) % MAX_ELEMENTOS;
        } else {
            inf = (meio + 1) % MAX_ELEMENTOS;
        }
    }
    return lista->Fim;
}

// Insere um elemento em uma fila de prioridades.
void FilaPrioridade_Insere(PTLista lista, unsigned int elemento) {
    unsigned int posicao, i;

    posicao = achaPosicao2(lista, elemento);
    for(i = lista->Fim; i != posicao; i = (i - 1) % MAX_ELEMENTOS) {
        lista->Elementos[i] = lista->Elementos[(i - 1) % MAX_ELEMENTOS];
    }
    lista->Elementos[posicao] = elemento;
    lista->Fim++;
    lista->Fim %= MAX_ELEMENTOS;
}

// Retira um elemento de ma fila de prioridades.
unsigned int FilaPrioridade_Retira(PTLista lista) {
    return Fila_Retira(lista);
}

/**
* Ponto de entrada para o programa.
* @return Retorna sempre zero.
*/
int main(int argv, char** argc) {
    Lista pilha, fila, filaPrioridade;
    unsigned int numOperacoes, operacao, elemento, retirado;
    unsigned char pilhaValida, filaValida, filaPrioridadeValida;

    (void)scanf("%u", &numOperacoes);
    while(!feof(stdin)) {
      // Inicializa as três listas.
        Lista_Cria(&pilha);
        Lista_Cria(&fila);
        Lista_Cria(&filaPrioridade);
        pilhaValida = filaValida = filaPrioridadeValida = 1;
        while(numOperacoes) {
          // Lê uma operação.
            (void)scanf("%u %u", &operacao, &elemento);
            if(operacao == INSERCAO) {  // Inserção
              // Insere o elemento nas listas que ainda forem válidas.
                if(pilhaValida) {
                    Pilha_Insere(&pilha, elemento);
                }
                if(filaValida) {
                    Fila_Insere(&fila, elemento);
                }
                if(filaPrioridadeValida) {
                    FilaPrioridade_Insere(&filaPrioridade, elemento);
                }
            } else {  // Retirada
              // Se alguma das listas está vazia. A estrutura já é inválida pois retirou mais elementos do que inseriu.
                if(Lista_Vazia(&pilha)) {
                    pilhaValida = filaValida = filaPrioridadeValida = 0;
                }
                // Confere o elemento retirado de cada uma das listas ainda válidas.
                if(pilhaValida) {
                    if(Lista_Vazia(&pilha)) {
                        pilhaValida = 0;
                    } else {
                        retirado = Pilha_Retira(&pilha);
                        if(retirado != elemento) {
                            pilhaValida = 0;
                        }
                    }
                }
                if(filaValida) {
                    if(Lista_Vazia(&fila)) {
                        filaValida = 0;
                    } else {
                        retirado = Fila_Retira(&fila);
                        if(retirado != elemento) {
                            filaValida = 0;
                        }
                    }
                }
                if(filaPrioridadeValida) {
                    if(Lista_Vazia(&filaPrioridade)) {
                        filaPrioridadeValida = 0;
                    } else {
                        retirado = FilaPrioridade_Retira(&filaPrioridade);
                        if(retirado != elemento) {
                            filaPrioridadeValida = 0;
                        }
                    }
                }
            }
            numOperacoes--;
        }
        // Define o tipo de estrutura.
        if((filaValida && pilhaValida) ||
            (filaValida && filaPrioridadeValida) ||
           (pilhaValida && filaPrioridadeValida)) {  // Indefinida.
            (void)printf("not sure\n");
        } else if(filaValida) {
            (void)printf("queue\n");
        } else if(pilhaValida) {
            (void)printf("stack\n");
        } else if(filaPrioridadeValida) {
            (void)printf("priority queue\n");
        } else {
            (void)printf("impossible\n");
        }
        // Lê o tamanho da próxima instância.
        (void)scanf("%u", &numOperacoes);
    }
    return 0;
}