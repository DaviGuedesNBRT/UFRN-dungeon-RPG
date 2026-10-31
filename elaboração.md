# 📜 REGRAS DO JOGO: DUNGEON OF THE THREE REALMS

## 1. Menu Principal
* **Opções disponíveis:**
  1. `[1]` Iniciar Jogo (Vai para a escolha de personagem).
  2. `[2]` Sair do Jogo (Encerra a execução do programa).
* **Validação:** O terminal deve tratar entradas inválidas (ex: se o utilizador digitar uma letra ou um número fora do intervalo 1-2, o sistema exibe um aviso e solicita uma nova entrada).

---

## 2. Seleção de Personagem
O jogador escolhe uma das 3 classes disponíveis. Cada uma possui atributos iniciais fixos e uma habilidade especial única:
* **Guerreiro:** Focado em combate corpo a corpo, alta vida e força bruta.
* **Mago:** Focado em magia, inteligência elevada e ataques em área.
* **Arqueiro:** Focado em agilidade e alta precisão de acerto crítico.

---

## 3. Estrutura de Fases e Tabuleiro
O jogo possui **3 fases progressivas**:
* **Fase 1:** Floresta Sombria
* **Fase 2:** Masmorra Antiga
* **Fase 3:** Fortaleza do Dragão

### Funcionamento do Tabuleiro:
* **Tamanho do Tabuleiro:** Cada fase é composta por **10 casas** fixas (vetor de tamanho 10).
* **Geração de Eventos por Casa:** 
  * Ao iniciar a fase, uma função percorre o tabuleiro de 1 a 10 e utiliza um gerador de números aleatórios de **1 a 5** para injetar o tipo de evento em cada casa:
    * `1` = **Combate com Monstro** (Gera um monstro aleatório adequado à fase).
    * `2` = **Tesouro** (Ganha XP ou itens de atributos).
    * `3` = **Poção de Cura** (Recupera uma quantidade de vida).
    * `4` = **Armadilha** (Causa dano direto ou reduz temporariamente um atributo).
    * `5` = **Evento Neutro / Vazio** (Acontece uma narrativa curta ou nada acontece).
  * **A Casa Final (Casa 10):** A última casa da fase é obrigatoriamente o **Chefe da Fase** (o 3º monstro, mais forte). Só é possível avançar de fase após derrotar o chefe.
* **Progressão de Fase:** 
  * Ao completar as 10 casas e derrotar o chefe, o jogador transita para a próxima fase.
  * **Cura total:** A vida do jogador é totalmente restabelecida ao mudar de fase.
  * **Aumento de Dificuldade:** A cada fase, a dificuldade global aumenta, aplicando penalizadores no ataque do jogador.

---

## 4. Mecânicas de Jogo e Combate

### A. Progressão de Dificuldade vs. Ataque Base
A dificuldade da fase afeta diretamente a eficiência ofensiva do personagem:
* **Fase 1 (Nível 1):** O personagem mantém **100%** do seu ataque base.
* **Fase 2 (Nível 2):** O personagem sofre penalização e fica com **90%** do seu ataque base.
* **Fase 3 (Nível 3):** O personagem sofre maior penalização e fica com **75%** do seu ataque base.

### B. Ações em Turnos de Combate
O combate ocorre em turnos (Jogador vs. Monstro) até que a vida de um deles chegue a zero. Em cada turno, o jogador pode escolher entre opções como:
1. Atacar
2. Defender
3. Usar Habilidade Especial
4. Fugir

### C. Fórmulas de Rolagem de Dados e Dano (D10 e D20)
As ações de ataque e defesa utilizam percentuais baseados em rolagens de dados (D10):

* **Cálculo da Defesa no Turno:**
  * O jogador ou o monstro rola um D10. Se o resultado for $X$:
  * $$\text{DefesaFinal} = \text{DefesaAtual} + \left(\text{DefesaAtual} \times \frac{X}{10}\right)$$

* **Cálculo do Ataque no Turno:**
  * O atacante rola um D10. Se o resultado for $X$:
  * $$\text{AtaqueTemporario} = \text{AtaqueAtualBase} + \left(\text{AtaqueAtualBase} \times \frac{X}{10}\right)$$
  *(Nota: Aplicar primeiro o redutor de dificuldade de 100%, 90% ou 75% sobre o ataque base antes de somar a porcentagem do dado).*

* **Cálculo do Dano Efetivo:**
  * $$\text{DanoCausado} = \max(1, \text{AtaqueTemporario} - \text{DefesaDoOponente})$$
  *(Garante que o dano mínimo seja sempre 1).*

### D. Sistema de XP e Atributos
* Ao vencer um combate, o jogador recebe **XP (Experiência)**.
* O XP acumulado converte-se em pontos de melhoria que o jogador pode distribuir livremente entre os seus atributos (Força, Defesa, Agilidade ou Inteligência).

### E. Drops de Monstros
* Sempre que um monstro comum ou chefe é derrotado, ele gera um **drop de buff aleatório** (como poções bônus ou aumentos temporários de atributos) aplicado diretamente ao personagem.
