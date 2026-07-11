#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct
{
    char nome[50];
    int  quantidade;
    float preco;

} Item;

void editarProduto(Item *estoque, int qtdItens);

void cadastrarItem(Item *item, int numeroItem);

#endif