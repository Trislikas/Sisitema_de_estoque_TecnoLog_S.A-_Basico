#include <stdio.h>
#include <locale.h>

#include "estoque.h"
#include "produto.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    executarSistema();

    return 0;
}