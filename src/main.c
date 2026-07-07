#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "estoque.h"
#include "validacoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int qtdItens = 0;
    Item *estoque = NULL;

    do
    {
        opcao = lerOpcaoMenu();

        switch (opcao)
        {
        case 1:

            if (estoque != NULL)
            {
                free(estoque);
                estoque = NULL;
                qtdItens = 0;
            }

            qtdItens = lerQuantidadeValida(
                "Informe a quantidade de itens: ",
                1,
                "Quantidade de itens invalida!"
            );

            estoque = (Item *)malloc(qtdItens * sizeof(Item));

            if (estoque == NULL)
            {
                printf("Erro ao alocar memoria!\n");
                return 1;
            }

            for (int i = 0; i < qtdItens; i++)
            {
                cadastrarItem(estoque + i, i + 1);
            }

            printf("\nCadastro realizado com sucesso!\n");
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

    } while (opcao != 0);

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