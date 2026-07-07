# 📦 Sistema de Gestão de Estoque - TecnoLog S.A.

Projeto desenvolvido em linguagem C com o objetivo de simular um sistema de gerenciamento de estoque, aplicando conceitos fundamentais da programação estruturada.

## 📖 Sobre o projeto

O sistema permite cadastrar produtos, validar entradas de dados e gerar um relatório contendo o valor total do estoque.

O projeto foi desenvolvido como prática dos conceitos estudados na disciplina de Linguagem C e será evoluído continuamente com novas funcionalidades.

---

## 🚀 Funcionalidades

- Cadastro de produtos
- Validação da quantidade informada
- Validação do preço (aceita vírgula e ponto)
- Cálculo automático do valor total do estoque
- Relatório dos produtos cadastrados
- Alocação dinâmica de memória
- Utilização de ponteiros
- Modularização do projeto

---

## 🛠️ Tecnologias

- Linguagem C
- GCC
- Visual Studio Code

---

## 📂 Estrutura do projeto

```
SistemaEstoque/
│
├── include/
│   ├── estoque.h
│   └── validacoes.h
│
├── src/
│   ├── main.c
│   ├── estoque.c
│   └── validacoes.c
│
├── README.md
└── .gitignore
```

---

## ▶️ Como compilar

No terminal execute:

```bash
gcc src/main.c src/estoque.c src/validacoes.c -Iinclude -o sistema
```

---

## ▶️ Como executar

Windows

```bash
sistema.exe
```

Linux

```bash
./sistema
```

---

## 📚 Conceitos utilizados

- Estruturas (`struct`)
- Ponteiros
- Aritmética de ponteiros
- Modularização
- Funções
- Alocação dinâmica (`malloc` e `free`)
- Validação de entrada
- Manipulação de strings
- Organização em múltiplos arquivos (`.c` e `.h`)

---

## 📌 Melhorias planejadas

- [ ] Buscar produto
- [ ] Editar produto
- [ ] Excluir produto
- [ ] Entrada de estoque
- [ ] Saída de estoque
- [ ] Ordenação dos produtos
- [ ] Estatísticas do estoque
- [ ] Persistência em arquivos
- [ ] Interface mais organizada

---

## 👨‍💻 Autor

**Lucas Emanoel**

Estudante de Análise e Desenvolvimento de Sistemas, em constante aprendizado na área de desenvolvimento de software.
