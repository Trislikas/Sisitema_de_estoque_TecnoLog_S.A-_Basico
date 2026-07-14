#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "estoque.h"
#include "validacoes.h"
#include "produto.h"
#include "interface.h"
#include "arquivo.h"
#include "ordenacao.h"

/*
    executar Sistema
*/

void executarSistema(void)
 {

    Item *estoque = NULL;
    int qtdItens = 0;
    carregarEstoque( &estoque, &qtdItens);
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
                exibirMensagemErro("Nenhum item cadastrado.");
            else 
                exibirRelatorio(estoque, qtdItens);
            break;

        case 3:
            
            pesquisarProduto(estoque, qtdItens);
            break;

        case 4:
            
            editarProduto(estoque, qtdItens);

            salvarEstoque(estoque,qtdItens);
            break;

        case 5:

            excluirProduto(&estoque, &qtdItens);
            break;

        case 6:
            
            movimentarEstoque(estoque, qtdItens);
            break;
        
        case 7:
        
            ordenarPorNome(estoque, qtdItens);

            salvarEstoque(estoque, qtdItens);

            printf("\nOrdenado por nome!\n");
            break;

        case 8:

            ordenarPorPreco(estoque, qtdItens);
            
            salvarEstoque(estoque, qtdItens);

            printf("\nOrdenado por preço!\n");
            break;

        case 9:

            ordenarPorQuantidade(estoque, qtdItens);
            
            salvarEstoque(estoque, qtdItens);

            printf("\nOrdenado por quandidade!\n");
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

int buscarProdutoParcial(const Item *estoque, int qtdItens,const char termo[])
{
    for(int i = 0; i < qtdItens; i++)
    {
        if(strstr(estoque[i].nome, termo) != NULL)
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
        exibirMensagemErro("Nenhum item cadastrado.");

        return;
    }

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome);

    int indice = buscarProdutoParcial(
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
        exibirMensagemErro("Erro ao alocar memoria");
        return;
    }

    *estoque = temp;

    for (int i = *qtdItens; i < *qtdItens + novosItens; i++)
    {
        cadastrarItem(
            &(*estoque)[i], i + 1,
            *estoque, i

        );
    }

    *qtdItens += novosItens;

    salvarEstoque( *estoque, *qtdItens); 

   exibirMensagemSucesso(
        "Produtos cadastrados com sucesso!"
   );
}

/*
    Exibe o relatório do estoque.
*/
void exibirRelatorio(const Item *estoque, int qtdItens)
{
    float valorTotal = calcularEstoque(estoque, qtdItens);

    exibirTitulo("RELATORIO DE ESTOQUE");

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
    exluir Produto 
*/

void excluirProduto(Item **estoque, int *qtdItens)

{

    if (*estoque == NULL || *qtdItens == 0)
    {
        exibirMensagemErro("Nenhum produto cadastrado.");
            return;
    }
    char nome[TAM_NOME];

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome);

    int indice = buscarProduto(
        *estoque, *qtdItens, nome);

    if (indice == -1)
    {
        exibirMensagemErro("Produti não encontrado.");

            return;
    }

    printf("\nProduto encontrado:\n");
    printf("Nome: %s\n", (*estoque)[indice].nome);
    printf("Quantidade: %d\n", (*estoque)[indice].quantidade);
    printf("Preco: R$ %.2f\n", (*estoque)[indice].preco);

    char resposta;
        printf("\nDeseja excluir este produto? (S/N): ");
        scanf(" %c", &resposta);
    
    if (toupper((unsigned char)resposta) != 'S')
    {
        printf("\nOperação cancelada.\n");
        return;
    }

    for (int i = indice; i < *qtdItens - 1; i++ )
    {
        (*estoque)[i] = (*estoque)[i + 1];
    }
    
    (*qtdItens) --;

    if (*qtdItens == 0)
    {
        free (*estoque);
        *estoque = NULL;
    }

    else
    {
        Item *temp = realloc(
            *estoque,
            (*qtdItens) * sizeof(Item)
        );
    }

    salvarEstoque(*estoque, *qtdItens);

    exibirMensagemSucesso("Produto excluido com sucesso!");
}

/*
     movimentar estoque entrda e saida
*/

void movimentarEstoque(Item *estoque, int qtdItens)
{
    if (estoque == NULL || qtdItens == 0)
    {
        exibirMensagemErro("Nenhum produto cadastrado.");
        return;
    }

    char nome[TAM_NOME];

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome);

    int indice = buscarProduto(estoque, qtdItens, nome);

    if (indice == -1)
    {
        exibirMensagemErro("Produto nâo encontrado.");
        return;
    }

    printf("\nProduto: %s\n", estoque[indice].nome);
    printf("Quantidade atual: %d\n", estoque[indice].quantidade);
    printf("Preco: R$ %.2f\n", estoque[indice].preco);

    int movimentacao;

    printf("\nMovimenracao (+ adiciona / - retira): ");

    while (scanf("%d", &movimentacao) != 1)
    {
        limparBufferEntrada();

        printf("Valor invalido.\n");
        printf("Movimentação: ");
    }

    int novaQuantidade = estoque[indice].quantidade + movimentacao;

    if (novaQuantidade < 0)
    {
        exibirMensagemErro("Estoque inseficiente.");
        return;
    }

    estoque[indice].quantidade = novaQuantidade;

    salvarEstoque(estoque, qtdItens);

    exibirMensagemSucesso("Movimentação realizada com sucesso!");

}

/*
    Exibe o menu e retorna a opção escolhida.
*/
int lerOpcaoMenu(void)
{
    exibirMenu();

    return lerQuantidadeValida(
        "Escolha uma opção: ",
        0,
        "Opção inválida!"
    );
}