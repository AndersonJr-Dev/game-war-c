# 🎮 War Game - Implementação em Linguagem C

**Disciplina**: Estruturas de Dados  
**Semestre**: 2º Semestre  
**Objetivo**: Implementar uma versão simplificada do jogo War em C, demonstrando conceitos de estruturas de dados, alocação dinâmica e modularização.

## 🎯 Objetivos de Aprendizado

- Estruturas de dados (`struct`)
- Vetores e manipulação de arrays
- Alocação dinâmica de memória (`malloc`, `free`)
- Ponteiros e passagem por referência
- Modularização e organização de código
- Ponteiros para funções
- Desenvolvimento incremental por níveis

## 📊 Estrutura do Projeto

O projeto está dividido em 3 níveis de complexidade crescente:

### 🎯 Nível 1 - Novato: Estrutura Básica
**Arquivo**: `nivel_novato.c`

#### Funcionalidades Implementadas:
- ✅ Estrutura `Territorio` com dados básicos
- ✅ Vetor estático de territórios
- ✅ Inicialização do mapa com 8 territórios
- ✅ Função de exibição do mapa
- ✅ Busca de territórios por ID
- ✅ Passagem de parâmetros por valor e referência

#### Conceitos Demonstrados:
```c
// Struct para representar territórios
typedef struct {
    int id;
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

// Vetor estático
Territorio territorios[MAX_TERRITORIOS];

// Passagem por referência
void inicializarMapa(Territorio territorios[], int *numTerritorios);

Saida esperada:

=== NIVEL NOVATO - ESTRUTURA BASICA ===

=== MAPA DO WAR ===
ID      Nome            Cor             Tropas
----------------------------------------
1       Brasil          Neutro          1
2       Argentina       Neutro          1
3       Peru            Neutro          1
4       Venezuela       Neutro          1
5       China           Neutro          1
6       India           Neutro          1
7       Japao           Neutro          1
8       Russia          Neutro          1

Digite o ID de um territorio para buscar:

## 👨‍💻 Autor

**Anderson Assumpção Junior**  
🎓 Estudante de Análise e Desenvolvimento de Sistemas  
🏫 Faculdade Estácio  
📚 2º Semestre - Disciplina: Estruturas de Dados  
📧 [juniorgn7dev@gmail.com]  
🔗 [https://andersondev-silk.vercel.app/]

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais como parte da disciplina de Estruturas de Dados.  
O código é aberto para estudo e referência.