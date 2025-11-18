#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 42
#define MAX_NOME 50
#define MAX_COR 20
#define MAX_MISSOES 5

// ==================== ESTRUTURAS ====================

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

typedef struct {
    char descricao[100];
    int (*verificarMissao)(Territorio[], int); // Ponteiro para função
    int concluida;
} Missao;

// ==================== FUNÇÕES DOS NÍVEIS ANTERIORES ====================

void inicializarMapa(Territorio territorios[], int *numTerritorios) {
    // América do Sul
    territorios[0] = (Territorio){1, "Brasil", "Neutro", 1};
    territorios[1] = (Territorio){2, "Argentina", "Neutro", 1};
    territorios[2] = (Territorio){3, "Peru", "Neutro", 1};
    territorios[3] = (Territorio){4, "Venezuela", "Neutro", 1};
    
    // Ásia
    territorios[4] = (Territorio){5, "China", "Neutro", 1};
    territorios[5] = (Territorio){6, "India", "Neutro", 1};
    territorios[6] = (Territorio){7, "Japao", "Neutro", 1};
    territorios[7] = (Territorio){8, "Russia", "Neutro", 1};
    
    *numTerritorios = 8;
}

void exibirMapa(Territorio territorios[], int numTerritorios) {
    printf("\n=== MAPA DO WAR ===\n");
    printf("ID\tNome\t\tCor\t\tTropas\n");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < numTerritorios; i++) {
        printf("%d\t%-12s\t%-10s\t%d\n", 
               territorios[i].id, 
               territorios[i].nome, 
               territorios[i].cor, 
               territorios[i].tropas);
    }
}

// ==================== FUNÇÕES DO NIVEL 3 - SISTEMA DE MISSÕES ====================

// Missão 1: Conquistar a América do Sul
int verificarAmericaSul(Territorio territorios[], int numTerritorios) {
    printf("\n--- Verificando Missao: America do Sul ---\n");
    
    char corDono[20] = "";
    int primeiro = 1;
    int territoriosConquistados = 0;
    
    // Territórios da América do Sul (IDs 1-4)
    for(int i = 0; i < 4 && i < numTerritorios; i++) {
        printf("  - %s: %s\n", territorios[i].nome, territorios[i].cor);
        
        if(strcmp(territorios[i].cor, "Neutro") != 0) {
            if(primeiro) {
                strcpy(corDono, territorios[i].cor);
                primeiro = 0;
            }
            
            if(strcmp(territorios[i].cor, corDono) == 0) {
                territoriosConquistados++;
            }
        }
    }
    
    int sucesso = (territoriosConquistados == 4);
    printf("  Resultado: %s\n", sucesso ? "CONQUISTADA!" : "Pendente");
    return sucesso;
}

// Missão 2: Conquistar a Ásia
int verificarAsia(Territorio territorios[], int numTerritorios) {
    printf("\n--- Verificando Missao: Asia ---\n");
    
    char corDono[20] = "";
    int primeiro = 1;
    int territoriosConquistados = 0;
    
    // Territórios da Ásia (IDs 5-8)
    for(int i = 4; i < 8 && i < numTerritorios; i++) {
        printf("  - %s: %s\n", territorios[i].nome, territorios[i].cor);
        
        if(strcmp(territorios[i].cor, "Neutro") != 0) {
            if(primeiro) {
                strcpy(corDono, territorios[i].cor);
                primeiro = 0;
            }
            
            if(strcmp(territorios[i].cor, corDono) == 0) {
                territoriosConquistados++;
            }
        }
    }
    
    int sucesso = (territoriosConquistados == 4);
    printf("  Resultado: %s\n", sucesso ? "CONQUISTADA!" : "Pendente");
    return sucesso;
}

// Missão 3: Ter pelo menos 6 territórios
int verificar6Territorios(Territorio territorios[], int numTerritorios) {
    printf("\n--- Verificando Missao: 6 Territorios ---\n");
    
    int contagemPorCor[10] = {0}; // Array para contar territórios por cor
    char cores[10][20] = {0};
    int numCores = 0;
    
    for(int i = 0; i < numTerritorios; i++) {
        if(strcmp(territorios[i].cor, "Neutro") != 0) {
            int encontrada = 0;
            
            // Verifica se a cor já foi registrada
            for(int j = 0; j < numCores; j++) {
                if(strcmp(territorios[i].cor, cores[j]) == 0) {
                    contagemPorCor[j]++;
                    encontrada = 1;
                    break;
                }
            }
            
            // Se é uma cor nova, adiciona ao array
            if(!encontrada) {
                strcpy(cores[numCores], territorios[i].cor);
                contagemPorCor[numCores] = 1;
                numCores++;
            }
        }
    }
    
    // Verifica se alguma cor tem pelo menos 6 territórios
    for(int i = 0; i < numCores; i++) {
        printf("  - %s: %d territorios\n", cores[i], contagemPorCor[i]);
        if(contagemPorCor[i] >= 6) {
            printf("  Resultado: CONQUISTADA! (%s tem %d territorios)\n", cores[i], contagemPorCor[i]);
            return 1;
        }
    }
    
    printf("  Resultado: Pendente (nenhuma cor tem 6 territorios)\n");
    return 0;
}

// Função para inicializar missões
void inicializarMissoes(Missao missoes[], int *numMissoes) {
    missoes[0] = (Missao){"Conquistar a America do Sul", verificarAmericaSul, 0};
    missoes[1] = (Missao){"Conquistar a Asia", verificarAsia, 0};
    missoes[2] = (Missao){"Controlar pelo menos 6 territorios", verificar6Territorios, 0};
    *numMissoes = 3;
}

// Função para exibir status das missões
void exibirMissoes(Missao missoes[], int numMissoes) {
    printf("\n=== MISSOES ESTRATEGICAS ===\n");
    for(int i = 0; i < numMissoes; i++) {
        printf("%d. %s - [%s]\n", 
               i + 1, 
               missoes[i].descricao,
               missoes[i].concluida ? "✓ CONCLUIDA" : "⌛ PENDENTE");
    }
}

// Função para verificar vitória
int verificarVitoria(Missao missoes[], int numMissoes, Territorio territorios[], int numTerritorios) {
    printf("\n=== VERIFICANDO CONDICOES DE VITORIA ===\n");
    
    int missoesConcluidas = 0;
    
    for(int i = 0; i < numMissoes; i++) {
        printf("\nMissao %d: %s\n", i + 1, missoes[i].descricao);
        int status = missoes[i].verificarMissao(territorios, numTerritorios);
        missoes[i].concluida = status;
        
        if(status) {
            missoesConcluidas++;
            printf("  🎯 MISSÃO CUMPRIDA!\n");
        }
    }
    
    return (missoesConcluidas >= 2); // Vitória se completar pelo menos 2 missões
}

// Função para simular conquistas (para teste)
void simularConquistas(Territorio territorios[], int numTerritorios) {
    printf("\n=== SIMULANDO CONQUISTAS ===\n");
    
    // Jogador Azul conquista América do Sul
    for(int i = 0; i < 4; i++) {
        strcpy(territorios[i].cor, "Azul");
        territorios[i].tropas = 2;
    }
    
    // Jogador Azul conquista 2 territórios na Ásia
    strcpy(territorios[4].cor, "Azul");
    strcpy(territorios[5].cor, "Azul");
    territorios[4].tropas = 2;
    territorios[5].tropas = 2;
    
    printf("Jogador Azul conquistou:\n");
    printf("- America do Sul completa (4 territorios)\n");
    printf("- 2 territorios na Asia\n");
    printf("- Total: 6 territorios\n");
}

void nivelMestre() {
    printf("\n=== NIVEL MESTRE - SISTEMA DE MISSOES ===\n");
    printf("Objetivo: Complete pelo menos 2 missoes estrategicas para vencer!\n");
    
    Territorio territorios[MAX_TERRITORIOS];
    int numTerritorios;
    
    // Inicializar estruturas
    inicializarMapa(territorios, &numTerritorios);
    
    Missao missoes[MAX_MISSOES];
    int numMissoes;
    inicializarMissoes(missoes, &numMissoes);
    
    // Simular algumas conquistas para teste
    simularConquistas(territorios, numTerritorios);
    
    // Exibir mapa atual
    printf("\n");
    exibirMapa(territorios, numTerritorios);
    
    // Exibir missões
    exibirMissoes(missoes, numMissoes);
    
    // Verificar condições de vitória
    if(verificarVitoria(missoes, numMissoes, territorios, numTerritorios)) {
        printf("\n🎉🎉🎉 PARABENS! VOCE VENCEU O JOGO! 🎉🎉🎉\n");
        printf("Voce completou as missoes estrategicas e dominou o mundo!\n");
    } else {
        printf("\n💪 Continue a expansao! Voce precisa completar mais missoes.\n");
    }
    
    // Resumo final
    printf("\n=== RESUMO FINAL ===\n");
    exibirMissoes(missoes, numMissoes);
}

// ==================== FUNÇÃO MAIN ====================

int main() {
    srand(time(NULL)); // Inicializar semente para números aleatórios
    nivelMestre();
    return 0;
}