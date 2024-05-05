#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula da lista encadeada
struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

// Função para imprimir todos os valores da lista
void imprimirLista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para calcular a quantidade de memória gasta por uma instância da célula
size_t tamanhoCelula() {
    return sizeof(celula);
}

// Função para remover todos os elementos da lista
void limparLista(celula **inicio) {
    celula *atual = *inicio;
    celula *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

// Função para calcular o máximo de elementos possíveis na fila com base na memória disponível
int maxElementosPossiveis() {
    size_t memoria_disponivel = /* calcular a memória disponível no seu sistema */;
    size_t tamanho_celula = sizeof(celula);
    return (int)(memoria_disponivel / tamanho_celula);
}

int main() {
    // Criando três instâncias do objeto célula
    celula *celula1 = (celula *)malloc(sizeof(celula));
    celula *celula2 = (celula *)malloc(sizeof(celula));
    celula *celula3 = (celula *)malloc(sizeof(celula));

    // Inicializando os valores das células
    celula1->conteudo = 10;
    celula1->prox = celula2;
    celula2->conteudo = 20;
    celula2->prox = celula3;
    celula3->conteudo = 30;
    celula3->prox = NULL;

    // Imprimindo todos os valores da lista
    printf("Valores da lista: ");
    imprimirLista(celula1);

    // Calculando a quantidade de memória gasta por cada instância da célula
    printf("Tamanho de uma célula: %zu bytes\n", tamanhoCelula());

    // Removendo os elementos da lista e liberando a memória
    limparLista(&celula1);
    printf("Lista limpa\n");

    // Calculando o máximo de elementos possíveis na fila
    printf("Máximo de elementos possíveis na fila: %d\n", maxElementosPossiveis());

    return 0;
}
