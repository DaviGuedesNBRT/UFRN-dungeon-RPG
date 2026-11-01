# 📜 REGRAS DO JOGO: DUNGEON OF THE THREE REALMS

## 1. Menu Principal

* **Opções disponíveis:**
  1. `[1]` Iniciar Jogo (Vai para a escolha de personagem).
  2. `[2]` Sair do Jogo (Encerra a execução do programa).
* **Validação:** O terminal deve tratar entradas inválidas (ex: se o utilizador digitar uma letra ou um número fora do intervalo 1-2, o sistema exibe um aviso e solicita uma nova entrada).

## 2. Seleção de Personagem e Equipamentos

O jogador escolhe uma das 3 classes disponíveis. Cada classe possui atributos iniciais fixos e equipamentos padrão (que devem ser registrados na estrutura do personagem como strings: `Roupa` e `Arma`):

* **Guerreiro:** Focado em combate corpo a corpo. Alta vida e força bruta.
  * **Habilidade Especial:** *Golpe Poderoso* (Causa dano adicional direto).
* **Mago:** Focado em magia. Inteligência elevada e ataques em área.
  * **Habilidade Especial:** *Explosão Arcana* (Concede bônus multiplicador de dano no turno).
* **Arqueiro:** Focado em agilidade e precisão.
  * **Habilidade Especial:** *Tiro Preciso* (Maior chance de acerto crítico/dano máximo).

## 3. Estrutura de Fases, Missões e Monstros

O jogo possui **3 fases progressivas**. Cada fase tem uma **Missão Principal** que deve ser exibida no início, e um conjunto específico de monstros:

* **Fase 1: Floresta Sombria**
  * *Missão:* Encontrar a Chave Antiga e derrotar o Guardião da Floresta.
  * *Monstros:* Goblin, Lobo Selvagem, Esqueleto Guerreiro.
* **Fase 2: Masmorra Antiga**
  * *Missão:* Recuperar o Artefato e abrir o portão para o próximo reino.
  * *Monstros:* Orc Guerreiro, Aranha Gigante, Cavaleiro Amaldiçoado.
* **Fase 3: Fortaleza do Dragão**
  * *Missão:* Derrotar o Dragão Ancestral e recuperar o Tesouro Lendário.
  * *Monstros:* Demônio das Chamas, Golem de Pedra, Dragão Ancestral (Chefe Final).

### Funcionamento do Tabuleiro:
* **Tamanho do Tabuleiro:** Cada fase é composta por **10 casas** fixas.
* **Geração de Eventos por Casa (1 a 9):** Aleatoriamente (1 a 5):
  * `1` = **Combate com Monstro** (Gera um monstro da fase atual).
  * `2` = **Tesouro** (Ganha XP).
  * `3` = **Poção de Cura** (Recupera uma quantidade de vida).
  * `4` = **Armadilha** (Causa dano direto).
* **A Casa Final (Casa 10):** É obrigatoriamente o **Chefe da Fase** (o 3º monstro da lista). A fase só é concluída ao derrotá-lo.

## 4. Mecânicas de Jogo e Combate

### A. Progressão de Dificuldade
A dificuldade aumenta a cada fase de duas formas:
1. **Redutor do Jogador:** Fase 1 (100% do ataque), Fase 2 (90% do ataque), Fase 3 (75% do ataque).
2. **Fator de Escala dos Monstros:** Os atributos dos monstros aumentam conforme a fase usando a fórmula: `AtributoFinal = ceil(AtributoBase * fatorFase)`.
3. **Descrição do Inimigo:** Todo monstro gerado deve imprimir na tela "Uma breve descrição" antes do combate começar.

### B. Ações em Turnos de Combate
O combate ocorre em turnos. A cada turno, o jogador DEVE escolher uma das opções do menu exato:
* `[1]` Atacar
* `[2]` Defender
* `[3]` Habilidade Especial
* `[4]` Fugir

### C. Fórmulas de Rolagem de Dados e Dano (D10)
* **Cálculo da Defesa no Turno:** (Ao escolher Defender)
  * Rola-se um D10 ($X$).
  * $\text{DefesaFinal} = \text{DefesaAtual} + \left(\text{DefesaAtual} \times \frac{X}{10}\right)$
* **Cálculo do Ataque no Turno:** (Ao escolher Atacar)
  * Rola-se um D10 ($X$).
  * $\text{AtaqueTemporario} = \text{AtaqueAtualBase} + \left(\text{AtaqueAtualBase} \times \frac{X}{10}\right)$ (Lembrando de aplicar o redutor de fase no Ataque Base primeiro).
* **Cálculo do Dano Efetivo:**
  * $\text{DanoCausado} = \max(1, \text{AtaqueTemporario} - \text{DefesaDoOponente})$

### D. Sistema de Recompensas e Atributos (Pós-Combate)
* **XP e Bônus Aleatório:** Ao vencer um monstro, o jogador ganha Experiência (XP). Além disso, o sistema deve **sortear aleatoriamente** um atributo (Força, Defesa, Agilidade, Inteligência ou Vida Máxima) e conceder um bônus permanente (+1 ou +2) a esse status.
* **Cura de Fase:** Ao completar a Missão e passar para a próxima fase, a vida do jogador é totalmente restabelecida.