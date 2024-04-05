//#include <stdio.h>
//
//#define MAX_LISTA 100  // Tamanho máximo da lista de compras.
//
//typedef struct SLista {
//    unsigned int Tamanho;
//    unsigned int Itens[MAX_LISTA];
//    double Somas[MAX_LISTA];
//    double MenoresPrecos[MAX_LISTA];
//    unsigned int Encontrados;
//} Lista;
//
int main(int argv, char** argc) {
//    Lista lista;
//    unsigned int numProdutos, identificador, i;
//    double preco;
//
//    // Lê os tamanhos da primeira instância para começar o algoritmo.
//    scanf("%u %u", &lista.Tamanho, &numProdutos);
//    while(lista.Tamanho != 0 || numProdutos != 0) {
//      // Lê os elementos da lista.
//        for(i = 0; i < lista.Tamanho; i++) {
//            scanf("%u", &lista.Itens[i]);
//        }
//        // Ajusta alguns valores iniciais da lista.
//        lista.Encontrados = 0;
//        lista.Somas[0] = 0.0;
//        // Começa a ler os itens do supermercado.
//        while(numProdutos) {
//            scanf("%u %lf", &identificador, &preco);
//            // 1. Verifica se o produto está em algum item já encontrado da lista.
//            // 2. Se estiver, verifica se é mais barato do que o menor preço já encontrado para aquele 
//            //    item.
//            // 3. Se for mais barato que o menor preço registrado, atualiza o preço dele. Atualiza também 
//            //    a soma acumulada de acordo com o item anterior.
//            //for(i = 0; i < lista.Encontrados; i++) {
//            //    if(lista.Itens[i] == identificador) {
//            //        if()
//            //    }
//            //}
//            // Se ainda não encontrou todos, verifica se é o próximo da lista que ainda não foi pego. Se 
//            // for, ajusta a soma do item de acordo com o anterior à ele e o menor preço dele com este 
//            // primeiro preço encontrado.
//            if(lista.Encontrados < lista.Tamanho) {
//                if(lista.Itens[lista.Encontrados] == identificador) {
//                    if(lista.Encontrados > 0) {
//                        lista.Somas[lista.Encontrados] = lista.Somas[lista.Encontrados - 1] + lista.MenoresPrecos[lista.Encontrados - 1];
//                    }
//                    lista.MenoresPrecos[lista.Encontrados] = preco;
//                }
//                lista.Encontrados++;
//            }
//            numProdutos--;
//        }
//    }
//
//
//    // Lê o tamanho da primeira instância para começar o algoritmo.
//    scanf("%u", &numGenes);
//    casoTeste = 1;
//    while(numGenes) {
//      // Inicializa o vetor de genes.
//        for(i = 1; i <= numGenes; i++) {
//            genes[i] = i;
//        }
//        // Lê a quantidade de inversões e aplica cada uma delas ao vetor.
//        scanf("%u", &numInversoes);
//        while(numInversoes) {
//            scanf("%u %u", &i, &j);
//            // Aplica a inversão.
//            while(i < j) {
//                aux = genes[i];
//                genes[i] = genes[j];
//                genes[j] = aux;
//                i++;
//                j--;
//            }
//            numInversoes--;
//        }
//        // Imprime o número do caso de teste.
//        (void)printf("Genome %u\n", casoTeste);
//        // Lê a quantidade de consultas e escreve a resposta para cada uma delas.
//        scanf("%u", &numConsultas);
//        while(numConsultas) {
//            scanf("%u", &aux);
//            for(i = 1; i <= numGenes; i++) {
//                if(genes[i] == aux) {
//                    (void)printf("%u\n", i);
//                    break;
//                }
//            }
//            numConsultas--;
//        }
//        // Lê o tamanho da próxima instância.
//        scanf("%u", &numGenes);
//        casoTeste++;
//    }
    return 0;
}