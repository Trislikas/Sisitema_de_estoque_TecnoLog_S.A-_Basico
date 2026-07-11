#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estoque.h"
#include "validacoes.h"
#include "produto.h"

/*
    executar Sistema
*/

void executarSistema(void)
 {

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
                printf("\nNunhum item cadastrado.\n");
            else 
                exibirRelatorio(estoque, qtdItens);
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

 }


/*
    Função responsável por calcular o valor total
    do estoque.
*/
float calcularEstoque(const Item *estoque, int qtdItens)
{
    float total = 0.0f;

    for (int i = 0; i < qtdItens; i++)
    {
        total += (estoque + i)->quantidade *
                 (estoque + i)->preco;
    }

    return total;
}

/*
    Procura um produto pelo nome.
*/
int buscarProduto(const Item *estoque, int qtdItens, const char nome[])
{
    for (int i = 0; i < qtdItens; i++)
    {
        if (compararIgnorandoMaiusculas(nome, estoque[i].nome))
        {
            return i;
        }
    }

    return -1;
}

/*
    Pesquisa um produto e exibe seus dados.
*/
void pesquisarProduto(const Item *estoque, int qtdItens)
{
    char nome[50];

    if (estoque == NULL || qtdItens == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome);

    int indice = buscarProduto(
        estoque,
        qtdItens,
        nome);

    if (indice == -1)
    {
        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("\n=============================\n");
    printf(" PRODUTO ENCONTRADO\n");
    printf("=============================\n");

    printf("Nome........: %s\n",
           (estoque + indice)->nome);

    printf("Quantidade..: %d\n",
           (estoque + indice)->quantidade);

    printf("Preco.......: R$ %.2f\n",
           (estoque + indice)->preco);

    printf("Subtotal....: R$ %.2f\n",
           (estoque + indice)->quantidade *
           (estoque + indice)->preco);
}


/*
    Função Cadastrar Produtos 
*/

void cadastrarProdutos(Item **estoque, int *qtdItens)
{
    int novosItens = lerQuantidadeValida(
        "Quantos produtos deseja cadastrar ? ",
        1,
        "Quantidade invalida!"
    );

    Item *temp = realloc(
        *estoque,
        (*qtdItens + novosItens) * sizeof(Item)
    );
    
    if (temp == NULL)
    {
        printf("\nErro ao alocar memoria.\n");
        return;
    }

    *estoque = temp;

    for (int i = *qtdItens; i < *qtdItens + novosItens; i++)
    {
        cadastrarItem(
            &(*estoque)[i], i + 1
        );
    }

    *qtdItens += novosItens;

    printf("\nProdutos cadastrados com sucesso!\n");
}

/*
    Exibe o relatório do estoque.
*/
void exibirRelatorio(const Item *estoque, int qtdItens)
{
    float valorTotal = calcularEstoque(estoque, qtdItens);

    printf("\n*************************************\n");
    printf("        RELATORIO DE ESTOQUE\n");
    printf("*************************************\n");

    for (int i = 0; i < qtdItens; i++)
    {
        float subtotal =
            (estoque + i)->quantidade *
            (estoque + i)->preco;

        printf("\nItem: %s\n", (estoque + i)->nome);
        printf("Quantidade: %d\n", (estoque + i)->quantidade);
        printf("Preco Unitario: R$ %.2f\n", (estoque + i)->preco);
        printf("Subtotal: R$ %.2f\n", subtotal);
    }

    printf("\n*************************************\n");
    printf("VALOR TOTAL DO ESTOQUE: R$ %.2f\n", valorTotal);
    printf("*************************************\n");
}

/*
    Exibe o menu e retorna a opção escolhida.
*/
int lerOpcaoMenu(void)
{
    int opcao;

    printf("\n***************************************\n");
    printf("     SISTEMA DE ESTOQUE TecnoLog S.A\n");
    printf("***************************************\n");
    printf("1 - Cadastrar estoque\n");
    printf("2 - Exibir relatorio\n");
    printf("3 - Buscar produto\n");
    printf("4 - Editar produto\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

    while (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 4)
    {
        printf("Opcao invalida!\n");
        limparBufferEntrada();
        printf("Escolha uma opcao: ");
    }

    return opcao;
}