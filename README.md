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

### 🎯 Nível Novato: Estrutura Básica
**Arquivo: war_game_novato.c**

#### Funcionalidades Implementadas:
- ✅ Estrutura `Territorio` com dados básicos
- ✅ Vetor estático de territórios
- ✅ Inicialização do mapa com 8 territórios
- ✅ Função de exibição do mapa
- ✅ Busca de territórios por ID
- ✅ Passagem de parâmetros por valor e referência

### ⚔️ Nível Aventureiro ✅ IMPLEMENTADO
- **Arquivo: war_game_aventureiro.c** - Sistema avançado de jogo
- ✅ Combate com múltiplos ataques e defesas
- ✅ Sistema de progressão e experiência
- ✅ Inventário expandido com equipamentos
- ✅ Missões e NPCs interativos
- ✅ Sistema de loja e economia

### 🏆 Nível Mestre ✅ IMPLEMENTADO
- **Arquivo: war_game_mestre.c** - Versão completa do jogo
- ✅ Sistema multiplayer (PvP e cooperativo)
- ✅ 4 classes especializadas: Guerreiro, Mago, Arqueiro, Curandeiro
- ✅ Dungeons aleatórias com layouts dinâmicos
- ✅ Chefes únicos com mecânicas complexas
- ✅ Sistema de guildas e personalização avançada
- ✅ IA avançada para inimigos
- ✅ Sistema completo de save/load

## 🚀 Como Executar

### Compilação Individual por Nível:
```bash
# Nível Novato
gcc -o war_game_novato war_game_novato.c
./war_game_novato

# Nível Aventureiro
gcc -o war_game_aventureiro war_game_aventureiro.c
./war_game_aventureiro

# Nível Mestre
gcc -o war_game_mestre war_game_mestre.c
./war_game_mestre

# Compilação Completa:
gcc -o war_game *.c
./war_game

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