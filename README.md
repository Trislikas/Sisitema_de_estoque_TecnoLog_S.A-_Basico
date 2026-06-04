# Sistema de Gestão de Estoque em C

## Sobre o Projeto

Este projeto consiste em um sistema simples de gestão de estoque desenvolvido na linguagem C. O programa permite cadastrar mercadorias, registrar suas quantidades e preços unitários, calcular subtotais por item e gerar o valor total do estoque.

O sistema foi desenvolvido com o objetivo de praticar conceitos fundamentais da programação em C, incluindo estruturas (`struct`), funções, ponteiros, alocação dinâmica de memória e validação de entrada de dados.

---

## Funcionalidades

* Cadastro de mercadorias
* Registro de quantidade e preço unitário
* Cálculo automático do subtotal de cada item
* Cálculo do valor total do estoque
* Validação de entradas do usuário
* Relatório detalhado dos produtos cadastrados

---

## Conceitos Utilizados

### Estruturas (Struct)

Utilização da estrutura `Item` para armazenar informações relacionadas aos produtos:

* Nome
* Quantidade
* Preço unitário

### Ponteiros

O projeto utiliza ponteiros para acessar e manipular os dados armazenados na memória.

### Alocação Dinâmica

A memória é alocada dinamicamente utilizando:

```c
malloc()
```

e liberada ao final da execução com:

```c
free()
```

### Funções

O código foi dividido em funções para melhorar a organização e reutilização:

* `calcularEstoque()`
* `limparBufferEntrada()`
* `converterPreco()`

### Validação de Dados

O sistema verifica:

* Quantidades negativas
* Valores inválidos para preço
* Entradas incorretas do usuário

---

## Estrutura do Projeto

```text
├── estoque.c
└── README.md
```

---

## Exemplo de Uso

```text
Informe a quantidade de itens: 2

*** Item 1 ***
Nome: Teclado
Quantidade: 10
Preco unitario: 50,00

*** Item 2 ***
Nome: Mouse
Quantidade: 5
Preco unitario: 30,00
```

Saída:

```text
RELATORIO DE ESTOQUE

Item: Teclado
Quantidade: 10
Preco Unitario: R$ 50.00
Subtotal: R$ 500.00

Item: Mouse
Quantidade: 5
Preco Unitario: R$ 30.00
Subtotal: R$ 150.00

VALOR TOTAL DO ESTOQUE: R$ 650.00
```

---

## Compilação

Utilizando GCC:

```bash
gcc estoque.c -o estoque
```

Execução:

```bash
./estoque
```

No Windows:

```bash
estoque.exe
```

---

## Objetivo Acadêmico

Este projeto foi desenvolvido para fins de estudo da linguagem C e aplicação prática dos conceitos de:

* Estruturas de dados
* Ponteiros
* Alocação dinâmica de memória
* Modularização com funções
* Processamento de dados
* Validação de entradas

---

## Autor

Lucas Emanoel

Estudante de Tecnologia da Informação e entusiasta de programação, desenvolvimento de software e análise de sistemas.
