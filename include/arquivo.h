#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "produto.h"

void salvarEstoque(
    
    const Item *estoque, int qtdItens);

void carregarEstoque(

    Item **estoque, int *qtdItens);

#endif