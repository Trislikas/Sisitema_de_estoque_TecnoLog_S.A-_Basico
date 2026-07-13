#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "produto.h"

/*
    Limpa o buffer de entrada do teclado.
*/
void limparBufferEntrada(void);

/*
    Lê uma quantidade válida.
*/
int lerQuantidadeValida(
    const char mensagem[],
    int valorMinimo,
    const char mensagemErro[]
);

/*
    Converte uma string para float,
    validando o formato do preço.
*/
int converterPreco(
    const char entradaPreco[],
    float *preco
);

/*
      Comparar os nomes 
*/

int compararIgnorandoMaiusculas(const char *texto1, const char *texto2);

/*
    Validar nomes de produtos vazios 
*/

int nomeProdutoValido(const char nome[]);

int produtoJaExiste(const Item *estoque, int qtdItens, const char nome[]);

void lerNomeValido(char nome[], int tamanho, const Item *estoque, int qtdItens);

#endif