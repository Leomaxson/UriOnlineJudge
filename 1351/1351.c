//#include <stdio.h>
//
//#define MAX_LISTA 100  // Tamanho m�ximo da lista de compras.
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
//    // L� os tamanhos da primeira inst�ncia para come�ar o algoritmo.
//    scanf("%u %u", &lista.Tamanho, &numProdutos);
//    while(lista.Tamanho != 0 || numProdutos != 0) {
//      // L� os elementos da lista.
//        for(i = 0; i < lista.Tamanho; i++) {
//            scanf("%u", &lista.Itens[i]);
//        }
//        // Ajusta alguns valores iniciais da lista.
//        lista.Encontrados = 0;
//        lista.Somas[0] = 0.0;
//        // Come�a a ler os itens do supermercado.
//        while(numProdutos) {
//            scanf("%u %lf", &identificador, &preco);
//            // 1. Verifica se o produto est� em algum item j� encontrado da lista.
//            // 2. Se estiver, verifica se � mais barato do que o menor pre�o j� encontrado para aquele 
//            //    item.
//            // 3. Se for mais barato que o menor pre�o registrado, atualiza o pre�o dele. Atualiza tamb�m 
//            //    a soma acumulada de acordo com o item anterior.
//            //for(i = 0; i < lista.Encontrados; i++) {
//            //    if(lista.Itens[i] == identificador) {
//            //        if()
//            //    }
//            //}
//            // Se ainda n�o encontrou todos, verifica se � o pr�ximo da lista que ainda n�o foi pego. Se 
//            // for, ajusta a soma do item de acordo com o anterior � ele e o menor pre�o dele com este 
//            // primeiro pre�o encontrado.
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
//    // L� o tamanho da primeira inst�ncia para come�ar o algoritmo.
//    scanf("%u", &numGenes);
//    casoTeste = 1;
//    while(numGenes) {
//      // Inicializa o vetor de genes.
//        for(i = 1; i <= numGenes; i++) {
//            genes[i] = i;
//        }
//        // L� a quantidade de invers�es e aplica cada uma delas ao vetor.
//        scanf("%u", &numInversoes);
//        while(numInversoes) {
//            scanf("%u %u", &i, &j);
//            // Aplica a invers�o.
//            while(i < j) {
//                aux = genes[i];
//                genes[i] = genes[j];
//                genes[j] = aux;
//                i++;
//                j--;
//            }
//            numInversoes--;
//        }
//        // Imprime o n�mero do caso de teste.
//        (void)printf("Genome %u\n", casoTeste);
//        // L� a quantidade de consultas e escreve a resposta para cada uma delas.
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
//        // L� o tamanho da pr�xima inst�ncia.
//        scanf("%u", &numGenes);
//        casoTeste++;
//    }
    return 0;
}