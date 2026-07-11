#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

void executarSistema(void);

float calcularEstoque(const Item *estoque, int qtdItens);

void exibirRelatorio(const Item *estoque, int qtdItens);

int lerOpcaoMenu(void);

int buscarProduto(const Item *estoque, int qtdItens, const char nome[]);

void pesquisarProduto(const Item *estoque, int qtdItens);

void cadastrarProdutos(Item **estoque, int *qtdItens);

#endif 