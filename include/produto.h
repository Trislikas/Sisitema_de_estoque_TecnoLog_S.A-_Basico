#ifndef PRODUTO_H
#define PRODUTO_H
#define TAM_NOME 50
#define TAM_PRECO 20


typedef struct
{
    char nome[TAM_NOME];
    int  quantidade;
    float preco;

} Item;

void editarProduto(Item *estoque, int qtdItens);

void cadastrarItem(Item *item, int numeroItem, const Item *estoque, int qtdItens);

#endif