#include <stdio.h>
#include <ctype.h>

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