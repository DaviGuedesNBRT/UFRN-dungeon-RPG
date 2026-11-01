#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// estrutura do jogador
typedef struct{
    char classe[20];
    int vidaAtual;
    int vidaMaxima;
    int ataque;
    int defesa;
    int agilidade;
    int inteligencia;
    char roupa[30];
    char arma[30];
    char habilidade[50];
    int experiencia;
} Personagem;

// estrutura de monstro
typedef struct {
    char nome[30];
    int vidaAtual;
    int vidaMaxima;
    int ataque;
    int defesa;
    int dificuldade;
    char descricao[100];
} Monstro;

// estrutura tabuleiro
typedef struct{
    int tipoEvento;
    int visitada;
} Casa;

void limparTerminal() {
    #ifdef _WIN32
        system("cls");   
    #else
        system("clear"); 
    #endif
}

void gerarTabuleiro(Casa tabuleiro[], int tamanho){
    for (int i=0; i < tamanho - 1; i++){
        tabuleiro[i].tipoEvento = (rand() % 5) + 1;
        tabuleiro[i].visitada = 0;
    }
    tabuleiro[tamanho - 1].tipoEvento = 6;
    tabuleiro[tamanho - 1].visitada = 0;
}

void escolhaPersonagem(Personagem *p){
    int opcao = 0;

    limparTerminal();
    printf("=========================================\n");
    printf("           ESCOLHA A SUA CLASSE          \n");
    printf("=========================================\n");
    printf("[1] Guerreiro - Combate corpo a corpo\n");
    printf("[2] Mago - Magia e ataque especial\n");
    printf("[3] Arqueiro - Precisao e agilidade\n");
    printf("=========================================\n");

    while (opcao < 1 || opcao > 3){
        printf("\nDigite o numero da sua escolha (1-3): ");
        scanf("%d", &opcao);
        
        // Limpa o "Enter" fantasma do buffer para não pular os próximos textos!
        while (getchar() != '\n'); 

        if (opcao < 1 || opcao > 3){
            printf("Opcao invalida, tente novamente.\n");
        }
    }

    switch (opcao) {
        case 1:
            strcpy(p->classe, "Guerreiro");
            p->vidaMaxima = 120; p->vidaAtual = 120;
            p->ataque = 12; p->defesa = 10;
            p->agilidade = 5; p->inteligencia = 5;
            strcpy(p->roupa, "Armadura de placas");
            strcpy(p->arma, "Espada longa");
            strcpy(p->habilidade, "Golpe Poderoso");
            break;
            
        case 2:
            strcpy(p->classe, "Mago");
            p->vidaMaxima = 80; p->vidaAtual = 80;
            p->ataque = 5; p->defesa = 5;
            p->agilidade = 6; p->inteligencia = 14;
            strcpy(p->roupa, "Tunica arcana");
            strcpy(p->arma, "Cajado magico");
            strcpy(p->habilidade, "Explosao Arcana");
            break;
            
        case 3:
            strcpy(p->classe, "Arqueiro");
            p->vidaMaxima = 100; p->vidaAtual = 100;
            p->ataque = 8; p->defesa = 7;
            p->agilidade = 13; p->inteligencia = 6;
            strcpy(p->roupa, "Armadura de couro");
            strcpy(p->arma, "Arco e flechas");
            strcpy(p->habilidade, "Tiro Preciso");
            break;
    }
    
    p->experiencia = 0;
    
    printf("\nExcelente! Voce escolheu o %s.\n", p->classe);
    printf("Pressione [ENTER] para iniciar a jornada...");
    getchar();
}

int rolarDado(int lados){
    printf("\nPressione [ENTER] para rolar o dado...");
    getchar();

    int dado = (rand() % lados) + 1;
    printf(">> Voce rolou um %d! <<\n", dado);
    
    return dado;
}

void abrirTesouro(Personagem *p, int lados, int fase){
    limparTerminal();
    printf("=========================================\n");
    printf("            BAU ENCONTRADO               \n");
    printf("=========================================\n");
    printf("Voce tenta decifrar o mecanismo da fechadura...\n");

    int dado = rolarDado(lados);
    int resultado = p->inteligencia * dado; 
    
    int dificuldade = ((rand() % 28) + 2) * fase; //dificuldade variavel conforme a fase

    printf("\nTeste de Intelecto: %d (Sua Inteligencia) x %d (Dado) = %d\n", p->inteligencia, dado, resultado);
    printf("Dificuldade da Fechadura: %d\n", dificuldade);

    if (resultado >= dificuldade){
        printf("\n[ SUCESSO! VOCE ABRIU O BAU! ]\n");

        int conteudo = (rand() % 3) + 1;

        switch (conteudo) {
            case 1:
                printf("-> Voce encontrou pergaminhos antigos! Ganhou 30 de XP!\n");
                p->experiencia += 30;
                break;
        
            case 2:
                printf("-> Voce encontrou uma pocao! Curou 20 de Vida.\n");
                p->vidaAtual += 20;
                if (p->vidaAtual > p->vidaMaxima){
                    p->vidaAtual = p->vidaMaxima;
                }
                break;

            case 3:
                printf("-> Voce caiu em uma armadilha toxica! Perdeu 15 de Vida.\n");
                p->vidaAtual -= 15;
                break;
        }
    } else {
        printf("\n[ FALHA! ] A fechadura travou e o bau nao pode mais ser aberto.\n");
    }
    
    printf("\nStatus atual -> Vida: %d/%d | XP: %d\n", p->vidaAtual, p->vidaMaxima, p->experiencia);
}

int main(){
    srand(time(NULL));

    Personagem jogador;
    int faseAtual = 1;
    int ladosDado = 10;
    int posicaoTabuleiro = 0; // Variável renomeada para corrigir o erro de digitação
    int tamanhoTabuleiro = 10;
    Casa tabuleiro[10]; // Tamanho fixado em 10 para evitar problemas de escopo de array dinâmico em algumas versões de compilador
    int jogoRodando = 1;

    limparTerminal();
    printf("=========================================\n");
    printf("      DUNGEON OF THE THREE REALMS        \n");
    printf("=========================================\n");
    printf("Pressione [ENTER] para comecar...");
    getchar();
 
    // 1. Escolha de personagem
    escolhaPersonagem(&jogador);

    // 2. Geração do tabuleiro
    gerarTabuleiro(tabuleiro, tamanhoTabuleiro);

    // 3. Teste do Baú
    abrirTesouro(&jogador, ladosDado, faseAtual);

    printf("\n=========================================\n");
    printf("Pressione [ENTER] para sair do teste...");
    getchar();
    limparTerminal();

    while (jogador.vidaAtual > 0 && faseAtual <=3){
        int eventoAtual = tabuleiro[posicaoTabuleiro].tipoEvento;
        printf("\n=== CASA %d ===\n", posicaoTabuleiro +1);

        switch (eventoAtual)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
        
        //se o jogador morrer, o jogo acaba!
        if (jogador.vidaAtual <= 0){
            printf("\nvoce foi derrotado... fim de jogo.\n");
            break;
        }

        posicaoTabuleiro++; // se o jogador nao morrer, ele passa de casa.

        if (posicaoTabuleiro == 10){
            printf("\nVoce concluiu a fase %d!\n", faseAtual);
            faseAtual ++;
            posicaoTabuleiro = 0;
            gerarTabuleiro(tabuleiro, tamanhoTabuleiro);
        }
    }

    return 0;
}