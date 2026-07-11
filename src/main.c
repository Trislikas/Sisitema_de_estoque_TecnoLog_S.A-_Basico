#include <stdio.h>
#include <locale.h>

#include "estoque.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    executarSistema();

    return 0;
}