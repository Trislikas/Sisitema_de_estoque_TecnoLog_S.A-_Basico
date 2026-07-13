#include <stdio.h>
#include <ctype.h>

#include "estoque.h"
#include "validacoes.h"


/*
    Limpa o buffer de entrada do teclado.
*/
void limparBufferEntrada(void)
{
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
    }
}

/*
    Lê uma quantidade válida informada pelo usuário.
*/
int lerQuantidadeValida(
    const char mensagem[],
    int valorMinimo,
    const char mensagemErro[])
{
    int quantidade;

    printf("%s", mensagem);

    while (scanf("%d", &quantidade) != 1 || quantidade < valorMinimo)
    {
        printf("%s\n", mensagemErro);
        limparBufferEntrada();
        printf("%s", mensagem);
    }

    limparBufferEntrada();


    return quantidade;
}

/*
    Converte uma string para float,
    aceitando vírgula ou ponto como separador decimal.
*/
int converterPreco(
    const char entradaPreco[],
    float *preco)
{
    float valor = 0.0f;
    float decimal = 0.1f;
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

/*
    Compara duas strings ignorando letras maiúsculas e minúsculas.
    Retorna 1 se forem iguais e 0 caso contrário.
*/
int compararIgnorandoMaiusculas(const char *texto1, const char *texto2)
{
    while (*texto1 != '\0' && *texto2 != '\0')
    {
        if (tolower((unsigned char)*texto1) !=
            tolower((unsigned char)*texto2))
        {
            return 0;
        }

        texto1++;
        texto2++;
    }

    return *texto1 == '\0' && *texto2 == '\0';
}

/*
      Validação de nomes e produtos vazios 
*/


int nomeProdutoValido(const char nome[])
{
    int temLetra = 0;

    for (int i = 0; nome [i] != '\0'; i++)
    {
        if (isalpha((unsigned char)nome[i]))
        {
            temLetra = 1;
        }
    }

    return temLetra;
}

int produtoJaExiste(const Item *estoque, int qtdItens, const char nome[])
{
    return buscarProduto(estoque, qtdItens, nome) != -1;
}

void lerNomeValido(char nome[], int tamanho, const Item *estoque, int qtdItens)
{
    while(1)
    {
        scanf(" %49[^\n]", nome);

        if (!nomeProdutoValido(nome))
        {
            printf("Nome invalido! Digite novamente: ");
            continue;
        }

        if (produtoJaExiste(estoque, qtdItens, nome))
        {
            printf("Produto ja cadastrado! Digite novamente: ");
            continue;
        }

        break;
    }
}
