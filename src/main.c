#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "estoque.h"
#include "validacoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Item *estoque = NULL;
    int qtdItens = 0;
    int opcao;
    
    do
    {
        opcao = lerOpcaoMenu();

        switch (opcao)
        {
        case 1:

            cadastrarProdutos(&estoque, &qtdItens);

            break;

        case 2:

            if (estoque == NULL || qtdItens == 0)
            {
                printf("\nNenhum item cadastrado.\n");
            }
            else
            {
                exibirRelatorio(estoque, qtdItens);
            }

            break;

        case 3:
            
            pesquisarProduto(estoque, qtdItens);

            break;

        case 4:
            
            editarProduto(estoque, qtdItens);

            break;

        case 0:

            printf("\nEncerrando o sistema...\n");
            
            break;
        }

    }  while (opcao != 0);

    free(estoque);

    return 0;
}

/*Usuário escolheu opção 1
        │
        ▼
Pergunte a quantidade
        │
        ▼
Aloque memória
        │
        ▼
Cadastre os itens*/