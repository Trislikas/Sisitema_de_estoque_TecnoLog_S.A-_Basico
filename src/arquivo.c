#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "estoque.h"
#include "produto.h"
#include "validacoes.h"

void salvarEstoque(

    const Item *estoque, int qtdItens)
{
    FILE *arquivo = fopen(
        "data/estoque.dat",
        "wb"
    );

    if (arquivo == NULL)
    {
        exibirMensagemErro("Erro ao salvar o estoque");

        return;
    }

    fwrite(
        &qtdItens, sizeof(int),
        1,
        arquivo
    );

    fwrite(
        estoque, sizeof(Item),
        qtdItens,
        arquivo
    );

    fclose(arquivo);
}

void carregarEstoque(

    Item **estoque, int *qtdItens)

{
    FILE *arquivo = fopen(
        "data/estoque.dat",
        "rb"
    );

    if (arquivo == NULL)
    {
        return;
    }

    fread(
        qtdItens, sizeof(int),
        1,
        arquivo
    );

    *estoque = malloc(
        (*qtdItens) * sizeof(**estoque)
    );

    if( *estoque == NULL)
    {
        fclose(arquivo);

        *qtdItens = 0;

        return;
    }

    fread(
        *estoque, sizeof(Item), *qtdItens, arquivo
    );

    fclose(arquivo);
}