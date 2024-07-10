#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCESSO 0
#define ERRO 1

/// TAD Imovel

#define IMOVEL_MAX_MORADORES 10
#define IMOVEL_MAX_CONSUMO 200

typedef struct SImovel {
    unsigned int NumMoradores;
    unsigned int ConsumoAgua;
} Imovel;

int Imovel_Constroi(Imovel *imovel, unsigned int numMoradores, unsigned int consumoAgua) {
    if(numMoradores > IMOVEL_MAX_MORADORES || consumoAgua > IMOVEL_MAX_CONSUMO) {
        return ERRO;
    }
    imovel->ConsumoAgua = consumoAgua;
    imovel->NumMoradores = numMoradores;
    return SUCESSO;
}

unsigned int Imovel_ConsumoPerCapta(Imovel *imovel) {
    return imovel->ConsumoAgua / imovel->NumMoradores;
}

/// TAD Cidade

#define CIDADE_MAX_IMOVEIS 1000000

typedef struct SCidade {
    Imovel *Imoveis;
    unsigned int NumImoveis;
} Cidade;

int Cidade_Constroi(Cidade *cidade, unsigned int numImoveis) {
    if(numImoveis > CIDADE_MAX_IMOVEIS) {
        return ERRO;
    }
    cidade->Imoveis = (Imovel *)malloc(numImoveis * sizeof(Imovel));
    if(cidade->Imoveis == NULL) {
        return ERRO;
    }
    cidade->NumImoveis = numImoveis;
    return SUCESSO;
}

void Cidade_Destroi(Cidade *cidade) {
    free(cidade->Imoveis);
    cidade->NumImoveis = 0;
}

double Cidade_CalculaConsumoMedio(Cidade *cidade) {
    unsigned int i;
    long long consumoTotal, numPessoas;

    consumoTotal = 0;
    numPessoas = 0;
    for(i = 0; i < cidade->NumImoveis; i++) {
        consumoTotal += cidade->Imoveis[i].ConsumoAgua;
        numPessoas += cidade->Imoveis[i].NumMoradores;
    }
    return (double)consumoTotal / numPessoas;
}

/// TAD TabelaConsumos

#define TABELA_CONSUMOS_TAM (IMOVEL_MAX_CONSUMO + 1)

typedef struct STabelaConsumos {
    unsigned int PessoasPorConsumo[TABELA_CONSUMOS_TAM];
} TabelaConsumos;

void TabelaConsumos_Limpa(TabelaConsumos *tabela) {
    memset(tabela, 0, sizeof(TabelaConsumos));
}

void TabelaConsumos_InsereImovel(TabelaConsumos *tabela, Imovel *imovel) {
    unsigned int consumoPerCapta;

    consumoPerCapta = Imovel_ConsumoPerCapta(imovel);
    tabela->PessoasPorConsumo[consumoPerCapta] += imovel->NumMoradores;
}

void TabelaConsumos_InsereCidade(TabelaConsumos *tabela, Cidade *cidade) {
    unsigned int i;

    for(i = 0; i < cidade->NumImoveis; i++) {
        TabelaConsumos_InsereImovel(tabela, &cidade->Imoveis[i]);
    }
}

/// Util

void leCidadeDaEntrada(Cidade *cidade) {
    unsigned int i;

    for(i = 0; i < cidade->NumImoveis; i++) {
        (void)scanf("%u %u", &cidade->Imoveis[i].NumMoradores, &cidade->Imoveis[i].ConsumoAgua);
    }
}

void imprimeTabelaConsumos(TabelaConsumos *tabela) {
    unsigned int i, primeiro;

    primeiro = 1;
    for(i = 0; i < TABELA_CONSUMOS_TAM; i++) {
        if(tabela->PessoasPorConsumo[i] > 0) {
            (void)printf(
                "%s%u-%u",
                primeiro ? "" : " ",
                tabela->PessoasPorConsumo[i],
                i);
            primeiro = 0;
        }
    }
    (void)printf("\n");
}

/// Ponto de entrada

int main(int argv, char **argc) {
    unsigned int tamCidade, numCidade;
    Cidade cidade;
    TabelaConsumos tabela;
    double consumoMedio;

    (void)scanf("%u", &tamCidade);
    numCidade = 1;
    while(tamCidade > 0) {
        // Cria e lê a cidade da entrada.
        if(Cidade_Constroi(&cidade, tamCidade) != SUCESSO) {
            return 1;
        }
        leCidadeDaEntrada(&cidade);
        (void)printf("Cidade# %u:\n", numCidade);
        // Calcula e imprime a tabela de consumos.
        TabelaConsumos_Limpa(&tabela);
        TabelaConsumos_InsereCidade(&tabela, &cidade);
        imprimeTabelaConsumos(&tabela);
        // Calcula e imprime o consumo médio.
        consumoMedio = Cidade_CalculaConsumoMedio(&cidade);
        consumoMedio *= 100.0;
        consumoMedio = floor(consumoMedio);
        consumoMedio /= 100.0;
        (void)printf("Consumo medio: %.2lf m3.\n", consumoMedio);
        // Lê o tamanho da próxima instância.
        Cidade_Destroi(&cidade);
        (void)scanf("%u", &tamCidade);
        numCidade++;
        // Se não foi a última instância, imprime uma linha em branco.
        if(tamCidade > 0) {
            (void)printf("\n");
        }
    }
    return 0;
}