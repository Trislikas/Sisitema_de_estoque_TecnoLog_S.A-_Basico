#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

void executarSistema(void);

float calcularEstoque(Item *estoque, int qtdItens);

void exibirRelatorio(Item *estoque, int qtdItens);

int lerOpcaoMenu(void);

int buscarProduto(Item *estoque, int qtdItens, const char nome[]);

void pesquisarProduto(Item *estoque, int qtdItens);

void cadastrarProdutos(Item **estoque, int *qtdItens);

#endif 