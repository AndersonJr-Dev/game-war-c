#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 42
#define MAX_NOME 50
#define MAX_COR 20

// ==================== ESTRUTURAS ====================

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

typedef struct {
    Territorio* atacante;
    Territorio* defensor;
    int tropasAtacantes;
    int tropasDefensoras;
    int resultado;
} Ataque;

// ==================== FUNÇÕES DO NIVEL 1 (reutilizadas) ====================

void inicializarMapa(Territorio territorios[], int *numTerritorios) {
    territorios[0] = (Territorio){1, "Brasil", "Neutro", 1};
    territorios[1] = (Territorio){2, "Argentina", "Neutro", 1};
    territorios[2] = (Territorio){3, "Peru", "Neutro", 1};
    territorios[3] = (Territorio){4, "Venezuela", "Neutro", 1};
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

Territorio* encontrarTerritorio(Territorio territorios[], int numTerritorios, int id) {
    for(int i = 0; i < numTerritorios; i++) {
        if(territorios[i].id == id) {
            return &territorios[i];
        }
    }
    return NULL;
}

// ==================== FUNÇÕES DO NIVEL 2 ====================

Ataque* simularAtaque(Territorio* atacante, Territorio* defensor, int tropasUsadas) {
    // Alocar memória dinamicamente para o ataque
    Ataque* novoAtaque = (Ataque*)malloc(sizeof(Ataque));
    
    if(novoAtaque == NULL) {
        printf("Erro ao alocar memoria para o ataque!\n");
        return NULL;
    }
    
    // Configurar ataque
    novoAtaque->atacante = atacante;
    novoAtaque->defensor = defensor;
    novoAtaque->tropasAtacantes = tropasUsadas;
    novoAtaque->tropasDefensoras = defensor->tropas;
    
    // Simulação simples de batalha
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;
    
    printf("\n=== BATALHA ===\n");
    printf("%s (%s) ataca %s (%s)\n", 
           atacante->nome, atacante->cor, 
           defensor->nome, defensor->cor);
    printf("Dado atacante: %d vs Dado defensor: %d\n", dadoAtacante, dadoDefensor);
    
    if(dadoAtacante > dadoDefensor) {
        novoAtaque->resultado = 1; // Vitória
        printf("VITORIA! %s conquista %s!\n", atacante->nome, defensor->nome);
        
        // Transferir controle
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = tropasUsadas - 1;
        
    } else {
        novoAtaque->resultado = 0; // Derrota
        printf("DERROTA! %s defendeu seu territorio!\n", defensor->nome);
        atacante->tropas -= 1;
    }
    
    return novoAtaque;
}

void nivelAventureiro() {
    printf("\n=== NIVEL AVENTUREIRO - SISTEMA DE ATAQUE ===\n");
    
    Territorio territorios[MAX_TERRITORIOS];
    int numTerritorios;
    inicializarMapa(territorios, &numTerritorios);
    
    // Configurar alguns territórios para teste
    strcpy(territorios[0].cor, "Azul");
    territorios[0].tropas = 5;
    strcpy(territorios[1].cor, "Vermelho");
    territorios[1].tropas = 3;
    
    exibirMapa(territorios, numTerritorios);
    
    // Simular ataque
    printf("\n--- Simulando Ataque ---\n");
    Ataque* batalha = simularAtaque(&territorios[0], &territorios[1], 3);
    
    if(batalha != NULL) {
        printf("\nResultado da batalha:\n");
        printf("Atacante: %s (%s) com %d tropas\n", 
               batalha->atacante->nome, batalha->atacante->cor, batalha->tropasAtacantes);
        printf("Defensor: %s (%s) com %d tropas\n", 
               batalha->defensor->nome, batalha->defensor->cor, batalha->tropasDefensoras);
        printf("Resultado: %s\n", batalha->resultado ? "VITORIA" : "DERROTA");
        
        free(batalha);
    }
    
    printf("\n--- Mapa Apos Batalha ---\n");
    exibirMapa(territorios, numTerritorios);
}

// ==================== FUNÇÃO MAIN OBRIGATÓRIA ====================

int main() {
    srand(time(NULL));
    nivelAventureiro();
    return 0;
}