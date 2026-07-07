#ifndef VALIDACOES_H
#define VALIDACOES_H

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

#endif