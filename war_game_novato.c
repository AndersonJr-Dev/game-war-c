#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 42
#define MAX_NOME 50
#define MAX_COR 20

// ==================== ESTRUTURAS ====================

// Estrutura para representar um território
typedef struct {
    int id;
    char nome[MAX_NOME];
    char cor[MAX_COR];  // Cor do jogador que controla
    int tropas;
} Territorio;

// ==================== FUNÇÕES DO NIVEL 1 ====================

// Função para inicializar o mapa
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
    
    *numTerritorios = 8; // Apenas alguns territórios para teste
}

// Função para exibir o mapa
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

// Função para encontrar território por ID
Territorio* encontrarTerritorio(Territorio territorios[], int numTerritorios, int id) {
    for(int i = 0; i < numTerritorios; i++) {
        if(territorios[i].id == id) {
            return &territorios[i];
        }
    }
    return NULL;
}

// Função principal do Nível 1
void nivelNovato() {
    printf("\n=== NIVEL NOVATO - ESTRUTURA BASICA ===\n");
    
    Territorio territorios[MAX_TERRITORIOS];
    int numTerritorios;
    
    // Inicializar mapa
    inicializarMapa(territorios, &numTerritorios);
    
    // Exibir mapa
    exibirMapa(territorios, numTerritorios);
    
    // Testar busca de território
    int idBusca;
    printf("\nDigite o ID de um territorio para buscar: ");
    scanf("%d", &idBusca);
    
    Territorio* encontrado = encontrarTerritorio(territorios, numTerritorios, idBusca);
    if(encontrado != NULL) {
        printf("Territorio encontrado: %s (%s) com %d tropas\n", 
               encontrado->nome, encontrado->cor, encontrado->tropas);
    } else {
        printf("Territorio nao encontrado!\n");
    }
}

// Função main apenas para teste do Nível 1
int main() {
    nivelNovato();
    return 0;
}