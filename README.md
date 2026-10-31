# 🛡️ Dungeon of the Three Realms

Projeto de um RPG de tabuleiro desenvolvido em linguagem **C (ANSI C)** para a prova prática de programação[cite: 1]. O jogo simula uma aventura dividida em 3 fases progressivas, onde o jogador assume o papel de um herói (Guerreiro, Mago ou Arqueiro) para enfrentar monstros, coletar tesouros e cumprir missões diretamente pelo terminal[cite: 1].

## ⚔️ Características do Jogo
* **Personagens Jogáveis:** Escolha entre Guerreiro, Mago e Arqueiro, cada um com atributos únicos de vida, força, defesa, agilidade e inteligência, além de habilidades especiais[cite: 1].
* **Progressão de Fases:** 
  1. *Floresta Sombria*[cite: 1]
  2. *Masmorra Antiga*[cite: 1]
  3. *Fortaleza do Dragão* (com combate contra o Chefe Final)[cite: 1]
* **Mecânicas de Tabuleiro:** Sistema de movimentação baseado em lançamento de dados (d6), eventos aleatórios por casa (combate, cura, tesouros e armadilhas)[cite: 1].
* **Sistema de Combate por Turnos:** Combates táticos utilizando rolagens de dados (d20) e fórmulas de cálculo de dano baseadas nos atributos dos personagens e monstros[cite: 1].
* **Evolução de Atributos:** Ganho de experiência e bônus aleatórios ao derrotar inimigos[cite: 1].

## 🛠️ Requisitos Técnicos Implementados
* Desenvolvido inteiramente em **C (ANSI C)**[cite: 1].
* Uso restrito às bibliotecas permitidas: `stdio.h`, `stdlib.h`, `string.h`, `time.h` e `math.h`[cite: 1].
* Aplicação intensiva de **structs, vetores, matrizes, ponteiros, funções e estruturas de controle/repetição**[cite: 1].
* Código totalmente modularizado, legível e organizado em arquivo único[cite: 1].

## 🚀 Como Compilar e Executar

Certifica-te de que tens um compilador C instalado (como o `gcc`). No terminal, executa os seguintes comandos:

```bash
# Clonar o repositório
git clone [https://github.com/DaviGuedesNBRT/nome-do-repositorio.git](https://github.com/DaviGuedesNBRT/nome-do-repositorio.git)

# Aceder ao diretório
cd nome-do-repositorio

# Compilar o código
gcc dungeon.c -o dungeon -lm

# Executar o jogo
./dungeon
