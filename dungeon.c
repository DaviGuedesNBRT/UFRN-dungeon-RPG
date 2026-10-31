// bibliotecas
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
}Personagem;

// estrutura de monstro
typedef struct {
    char nome[30];
    int vidaAtual;
    int vidaMaxima;
    int ataque;
    int defesa;
    int dificuldade;
    char descricao[100];
}Monstro;

// estrutura tabuleiro
typedef struct{
    int tipoEvento;
    int visitada;
}Casa;

