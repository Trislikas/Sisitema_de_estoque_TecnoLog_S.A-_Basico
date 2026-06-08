#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/*Foi utilizada uma struct para agrupar informações
    relacionadas a uma mercadoria, como nome,
    quantidade e preço unitário.*/

typedef struct
{
    char nome[50];
    int  quantidade;
    float preco;

} Item;

/*
    Função responsável por calcular o valor total
    do estoque.

    Recebe um ponteiro para o vetor de itens e a
    quantidade de itens cadastrados.

    A função utiliza aritmética de ponteiros para
    acessar cada posição da memória alocada.
*/

float calcularEstoque(Item *estoque, int qtdItens)
{
    float total = 0.0;

    for (int i = 0; i < qtdItens; i++)
    {
        total += (estoque + i)->quantidade *
                 (estoque + i)->preco;
    }

    return total;
}

void limparBufferEntrada()
{
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
    }
}

int converterPreco(char entradaPreco[], float *preco)
{
    float valor = 0.0;
    float decimal = 0.1;
    int separador = 0;
    int temDigito = 0;
    int temDigitoDepoisSeparador = 0;

    if (entradaPreco[0] == '-' || entradaPreco[0] == '\0')
    {
        return 0;
    }

    for (int i = 0; entradaPreco[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)entradaPreco[i]))
        {
            temDigito = 1;

            if (separador)
            {
                temDigitoDepoisSeparador = 1;
                valor += (entradaPreco[i] - '0') * decimal;
                decimal /= 10;
            }
            else
            {
                valor = valor * 10 + (entradaPreco[i] - '0');
            }
        }
        else if (entradaPreco[i] == ',' || entradaPreco[i] == '.')
        {
            if (separador)
            {
                return 0;
            }

            separador = 1;
        }
        else
        {
            return 0;
        }
    }

    if (!temDigito || (separador && !temDigitoDepoisSeparador))
    {
        return 0;
    }

    *preco = valor;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int qtdItens;
    float valorTotal;

    printf("***************************************\n");
    printf(" SISTEMA DE ESTOQUE TecnoLog S.A\n");
    printf("****************************************\n");

    printf("informe a quantidade de itens: ");
    while (scanf("%d", &qtdItens) != 1 || qtdItens <= 0)
    {
        printf("Quantidade de itens invalida!\n");
        limparBufferEntrada();
        printf("informe a quantidade de itens: ");
    }

    /*
    Alocação dinâmica de memória.

    A quantidade de itens é informada pelo usuário
    durante a execução do programa. Por esse motivo,
    não é possível definir previamente o tamanho
    do vetor.

    A função malloc reserva na memória espaço
    suficiente para armazenar todos os itens.
*/

    Item *estoque = (Item *)malloc(qtdItens * sizeof(Item));

    if (estoque == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    /*
    Cadastro dos produtos.

    Os dados informados pelo usuário são armazenados
    na memória utilizando ponteiros e aritmética
    de ponteiros.
*/

    for (int i = 0; i < qtdItens; i++)
    {
        char entradaPreco[20];

        printf("\n *** Item %d ***\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", (estoque + i)->nome);

        printf("Quantidade: ");
        while (scanf("%d", &(estoque + i)->quantidade) != 1 ||
               (estoque + i)->quantidade < 0)
        {
            printf("Quantidade invalida! Nao pode ser negativa.\n");
            limparBufferEntrada();
            printf("Quantidade: ");
        }

        printf("Preco unitario (R$ - use virgula ou ponto para centavos): ");
        while (scanf("%19s", entradaPreco) != 1 ||
               converterPreco(entradaPreco, &(estoque + i)->preco) == 0)
        {
            printf("Preco invalido! Use valor positivo, exemplo: 10,50 ou 10.50.\n");
            limparBufferEntrada();
            printf("Preco unitario (R$ - use virgula ou ponto para centavos): ");
        }
    }

    //Processamento

    valorTotal = calcularEstoque(estoque, qtdItens);

    //Relatório

    printf("\n*****************************\n");
    printf(" RELATORIO DE ESTOQUE\n");
    printf("\n*****************************\n");

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

    printf("\n*****************************\n");
    printf("VALOR TOTAL DO ESTOQUE: R$ %.2f\n", valorTotal);
    printf("\n*****************************\n");

/*
    Libera a memória alocada dinamicamente.

    Essa etapa é importante para evitar
    desperdício de memória durante a execução
    do programa.
*/

    free(estoque);

    return 0;
}

/*
                GESTÃO DE ESTOQUE - TecnoLog S.A.

                              |
    -------------------------------------------------------
    |                     |                   |           |
  Struct             Ponteiros           Funções    Alocação
    |                     |                   |       Dinâmica
    |                     |                   |           |
 Nome               Item *estoque     calcularEstoque() malloc()
 Quantidade              |                   |           |
 Preço              estoque + i        Valor Total      free()
                           |
                      Operador ->
                           |
                  Acesso aos membros

                              |
                       Processamento
                              |
                Quantidade × Preço Unitário
                              |
                      Soma dos Subtotais
                              |
                   Valor Total do Estoque

                              |
                         Validações
                              |
          -----------------------------------------
          |                    |                  |
   Quantidade > 0      Preço válido      Entrada correta
*/