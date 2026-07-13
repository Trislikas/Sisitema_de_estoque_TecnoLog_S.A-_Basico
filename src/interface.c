#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interface.h"

void exibirMenu(void)
{
    exibirTitulo("SISTEMA DE ESTOQUE TECNOLOG S.A.");

    printf("1 - Cadastrar produtos\n");
    printf("2 - Exibir relatorio\n");
    printf("3 - Pesquisar produto\n");
    printf("4 - Editar produto\n");
    printf("5 - Excluir produto\n");
    printf("6 - Movimentar estoque\n");
    printf("0 - Sair\n");

    exibirSeparador();
}

void exibirSeparador(void)
{
    printf("=========================================\n");
}

void exibirTitulo(const char titulo[])
{
    exibirSeparador();

    printf("%s\n", titulo);

    exibirSeparador();
}

void exibirMensagemSucesso(const char mensagem[])
{
    printf("\n[SUCESSO] %s\n", mensagem);

}

void exibirMensagemErro(const char mensagem[])
{
    printf("\n[ERRO] %s\n", mensagem);
}

void pausarSistema(void)
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void limparTela(void)
{
    system("cls");
    system("clear");
}