#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct
{
    char nome[50];
    int  quantidade;
    float preco;

} Item;

/* Funções do sistema */

float calcularEstoque(Item *estoque, int qtdItens);

void cadastrarItem(Item *item, int numeroItem);

void exibirRelatorio(Item *estoque, int qtdItens);

int lerOpcaoMenu(void);

int buscarProduto(Item *estoque, int qtdItens, const char nome[]);

void pesquisarProduto(Item *estoque, int qtdItens);

void editarProduto(Item *estoque, int qtdItens);


#endif 

/*
           estoque.h
          /         \
         /           \
    main.c       estoque.c
    
*/