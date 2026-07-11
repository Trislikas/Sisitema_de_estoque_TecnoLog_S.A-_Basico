#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estoque.h"
#include "validacoes.h"
#include "produto.h"


/*
    Função responsável pelo cadastro de um item.
*/
void cadastrarItem(Item *item, int numeroItem)
{
    char entradaPreco[TAM_PRECO];

    printf("\n*** Item %d ***\n", numeroItem);

    printf("Nome: ");
    scanf(" %49[^\n]", item->nome);
    scanf("%19s", entradaPreco);

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
    Edita um produto existente.
*/
void editarProduto(Item *estoque, int qtdItens)
{
    char nome[TAM_NOME];
    char entradaPreco[TAM_PRECO];
    
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
        printf("Novo perco: ");
    }

    printf("\nProduto atalizado com sucesso!\n");

}
