#include <stdio.h>
#include <string.h>

#include "estoque.h"
#include "validacoes.h"

/*
    Função responsável por calcular o valor total
    do estoque.
*/
float calcularEstoque(Item *estoque, int qtdItens)
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

    Retorna:
    - índice do produto encontrado.
    - -1 caso não exista.
*/
int buscarProduto(
    Item *estoque,
    int qtdItens,
    const char nome[])
{
    for (int i = 0; i < qtdItens; i++)
    {
        if (strcmp((estoque + i)->nome, nome) == 0)
        {
            return i;
        }
    }

    return -1;
}

/*
    Pesquisa um produto e exibe seus dados.
*/
void pesquisarProduto(
    Item *estoque,
    int qtdItens)
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
    Edita um produto existente.
*/
void editarProduto(Item *estoque, int qtdItens)
{
    char nome[50];
    char entradaPreco[20];
    
    if (estoque == NULL || qtdItens == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }
    
printf("\nNome do produto que deseja editar: ");
scanf(" %49[^\n]", nome);

int indice = buscarProduto(estoque, qtdItens, nome);

if (indice == -1)
{
    printf("\nProduto nao encontrado.\n");
    return;
}
    printf("\n=============================\n");
    printf(" EDITAR PRODUTO\n");
    printf("=============================\n");

    printf("Novo nome: ");
    scanf(" %49[^\n]", (estoque + indice)->nome);

    (estoque + indice)->quantidade = 
        lerQuantidadeValida(
            "Nova quantidade: ",
            0,
            "Quantidade invalida!"
        );

    printf("Novo preco: ");

    while (scanf("%19s", entradaPreco) != 1 || 
            converterPreco(
                entradaPreco,
                &(estoque + indice)->preco) == 0)
    {
        printf("Preco invalido!\n");
        limparBufferEntrada();
        print("Novo perco: ");
    }

    printf("\nProduto atalizado com sucesso!\n");

}


/*
    Função responsável pelo cadastro de um item.
*/
void cadastrarItem(Item *item, int numeroItem)
{
    char entradaPreco[20];

    printf("\n*** Item %d ***\n", numeroItem);

    printf("Nome: ");
    scanf(" %49[^\n]", item->nome);

    item->quantidade = lerQuantidadeValida(
        "Quantidade: ",
        0,
        "Quantidade invalida! Nao pode ser negativa."
    );

    printf("Preco unitario (R$ - use virgula ou ponto): ");

    while (scanf("%19s", entradaPreco) != 1 ||
           converterPreco(entradaPreco, &item->preco) == 0)
    {
        printf("Preco invalido! Use um valor positivo. Exemplo: 10,50 ou 10.50.\n");
        limparBufferEntrada();
        printf("Preco unitario (R$ - use virgula ou ponto): ");
    }
}

/*
    Exibe o relatório do estoque.
*/
void exibirRelatorio(Item *estoque, int qtdItens)
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