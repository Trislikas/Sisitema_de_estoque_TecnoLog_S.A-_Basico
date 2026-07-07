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
    int novosItens = 0;
    int opcao;

    do
    {
        opcao = lerOpcaoMenu();

        switch (opcao)
        {
        case 1:

            novosItens = lerQuantidadeValida(
                "Qauntos produtos deseja cadastrar? ",
                1,
                "Quantidade invalida!"
            );

            Item *temp = realloc(
                estoque,
                (qtdItens + novosItens) * sizeof(Item)
            );
            
            if (temp == NULL)
            {
                printf("\nErro ao alocar memoria.\n");
                break;
            }

            estoque = temp;

            for (int i = qtdItens; i < qtdItens + novosItens; i++)
            {
                cadastrarItem(
                    &estoque[i],
                    i + 1
                );
            }
            qtdItens += novosItens; 

            printf("\nProdutos cadastrados com sucesso!\n");

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