#include <string.h>
#include <ctype.h>

#include "ordenacao.h"


void trocar(Item *a, Item *b)
{
    Item aux = *a;
    *a = *b;
    *b = aux;
}


/*
    Ordenação por nome
*/

int compararNomesIgnoreCase(
    const char *a,
    const char *b
)
{
    while(*a && *b)
    {
        char ca = tolower((unsigned char)*a);
        char cb = tolower((unsigned char)*b);

        if(ca != cb)
        {
            return ca - cb;
        }

        a++;
        b++;
    }

    return *a - *b;
}

void ordenarPorNome(Item *estoque, int qtdItens)
{
    for(int i = 0; i < qtdItens - 1; i++)
    {
        for(int j = i + 1; j < qtdItens; j++)
        {
            if(compararNomesIgnoreCase(estoque[i].nome, estoque[j].nome) > 0)
            {
                trocar(&estoque[i], &estoque[j]);
            }
        }
    }
}


/*
    Ordenação por preço
*/
void ordenarPorPreco(Item *estoque, int qtdItens)
{
    for(int i = 0; i < qtdItens - 1; i++)
    {
        for(int j = i + 1; j < qtdItens; j++)
        {
            if(estoque[i].preco > estoque[j].preco)
            {
                trocar(&estoque[i], &estoque[j]);
            }
        }
    }
}


/*
    Ordenação por quantidade
*/
void ordenarPorQuantidade(Item *estoque, int qtdItens)
{
    for(int i = 0; i < qtdItens - 1; i++)
    {
        for(int j = i + 1; j < qtdItens; j++)
        {
            if(estoque[i].quantidade < estoque[j].quantidade)
            {
                trocar(&estoque[i], &estoque[j]);
            }
        }
    }
}