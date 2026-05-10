# 🚀 Asteroid Dodge

> Um jogo de esquiva desenvolvido em Scratch como projeto da Semana 0 do **CS50x — Introduction to Computer Science** (Harvard University / edX).

<img width="1688" height="1256" alt="image" src="https://github.com/user-attachments/assets/fda61eaf-167a-4959-a71b-60b32a7f8501" />

---

## 📖 Sobre o projeto

**Asteroid Dodge** é um jogo de reflexo e sobrevivência no espaço. O jogador controla uma nave espacial e precisa desviar de asteroides que surgem e caem em velocidade crescente. Quanto mais tempo sobreviver, maior a pontuação, mas cada colisão custa uma vida.

O projeto foi desenvolvido como entrega do **Problem Set 0** do CS50x, com o objetivo de explorar os conceitos fundamentais de programação de forma visual e interativa usando o [Scratch](https://scratch.mit.edu/).

---

## 🎮 Como jogar

| Tecla | Ação |
|---|---|
| ← / → ou A / D | Mover a nave para os lados |
| ↑ / ↓ ou W / S| Mover a nave para cima e para baixo |

- **Desvie** dos asteroides que caem do topo da tela
- Cada colisão remove **1 vida**
- Quando as vidas acabam, o jogo termina
- A **pontuação** aumenta automaticamente com o tempo sobrevivido

---

## 🧩 Estrutura do projeto

O projeto é composto por **3 sprites** principais:

### 🛸 Sprite: `Stage` (Palco)
O palco funciona como o **gerenciador central** do jogo. É responsável por inicializar a pontuação e incrementá-la ao longo do tempo.

<img width="855" height="639" alt="image" src="https://github.com/user-attachments/assets/13dc2c70-0eb2-41e4-aa0b-8c49ed1922ce" />

```
quando ⚑ clicado
  mudar cenário para [space]
  definir Score como 0
  sempre
    se <(Life) > 0> então
      esperar 1 segundo
      mudar Score por 1
```

<img width="550" height="697" alt="image" src="https://github.com/user-attachments/assets/842b48e1-ec8d-4578-b966-0a8f8b184519" />

---

### 🚀 Sprite: `spaceship` (Nave)
A nave é o sprite controlado pelo jogador. Ela verifica continuamente quais teclas estão pressionadas e move-se na direção correspondente, respeitando os limites da tela com `se tocar na borda, volte`.

<img width="1119" height="834" alt="image" src="https://github.com/user-attachments/assets/9d029016-4cf4-4e83-b29b-714c21138aa5" />

```
quando ⚑ clicado
  mostrar
  definir Life como 3
  sempre
    se <tecla [← seta] pressionada?> então
      mude x por -6
      se tocar na borda, volte
    se <tecla [→ seta] pressionada?> então
      mude x por 6
      ...
    se <(Life) = 0> então
      esconder
      mudar cenário para [game over]
```

<img width="662" height="1188" alt="image" src="https://github.com/user-attachments/assets/aac48d5b-96ae-4963-93cc-e12e0c580e87" />

---

### ☄️ Sprite: `asteroid`
Este é o sprite mais complexo do projeto. Ele utiliza o sistema de **clones** do Scratch para gerar múltiplos asteroides sem precisar de sprites separados, e contém o **bloco customizado** exigido pelo CS50.

<img width="853" height="634" alt="image" src="https://github.com/user-attachments/assets/2cefc69e-a0de-49d4-8dc5-9a2a3faaa386" />

O sprite é organizado em **3 scripts**:

#### Script 1 — Gerador de clones
O sprite original fica escondido e cria um novo clone a cada intervalo, alimentando o jogo com asteroides continuamente.

```
quando ⚑ clicado
  esconder
  sempre
    criar clone de [mim mesmo]
    esperar (1) segundos
```

<img width="573" height="439" alt="image" src="https://github.com/user-attachments/assets/e10957b1-b54d-46a7-abfd-a41cb21dd843" />

#### Script 2 — Inicialização do clone
Cada clone, ao nascer, recebe valores aleatórios de posição, tamanho e velocidade, e então chama o bloco customizado `move` para começar a se mover.

```
quando eu começar como clone
  mostrar
  definir position como (número aleatório entre -200 e 200)
  definir size como (número aleatório entre 50 e 100)
  definir speed como (número aleatório entre 3 e 8)
  ir para x: (position) y: 180
  definir tamanho como (size) %
  move (speed)
```

<img width="653" height="614" alt="image" src="https://github.com/user-attachments/assets/eac5cb5c-6e8e-4863-99cf-84c89bdcca9e" />

#### Script 3 — Bloco customizado: `move (speed)`
Este é o núcleo da lógica de movimento. O bloco recebe a velocidade como **argumento** e executa um loop eterno que move o asteroide para baixo, verifica colisões e reage de acordo.

```
defina move (speed)
  sempre
    esperar 0.02 segundos
    mude y por -(speed)

    se <tocando em [spaceship]?> então        ← colisão com a nave
      [reposiciona o asteroide]
      mudar Life por -1
      mudar Score por -5

    se <(y) < -180> então                     ← saiu pela base da tela
      esconder
      [aguarda e reposiciona]

    se <(Life) = 0> então                     ← jogo encerrado
      [reposiciona o asteroide silenciosamente]
```

<img width="496" height="1150" alt="image" src="https://github.com/user-attachments/assets/41593ba7-4218-4f7d-8f13-6b4d47dfe4e5" />

---

## ✅ Requisitos do CS50 atendidos

| Requisito | Como foi atendido |
|---|---|
| ≥ 2 sprites, nenhum sendo o gato padrão | `spaceship` e `asteroid` |
| ≥ 3 scripts no total | 5 scripts distribuídos entre os sprites |
| Pelo menos 1 condicional | Múltiplos `se` em todos os sprites |
| Pelo menos 1 loop | `sempre` presente em todos os sprites |
| Pelo menos 1 variável | `Score`, `Life`, `speed`, `size`, `position` |
| Bloco customizado com ≥ 1 input | `move (speed)` com argumento `speed` |

<img width="1217" height="625" alt="image" src="https://github.com/user-attachments/assets/45735e97-505f-4ab1-868d-f482939e8791" />

---

## 💡 Decisões de design

**Por que usar clones em vez de sprites separados?**
A primeira versão do projeto tinha 9 sprites de asteroide separados, cada um com scripts idênticos. Isso funcionava, mas era repetitivo e difícil de manter. Migrar para um sistema de clones centralizou toda a lógica em um único sprite, tornando o código mais limpo e escalável.

**Por que separar o movimento em um bloco customizado?**
O bloco `move (speed)` isola toda a lógica de movimentação e colisão, recebendo a velocidade como parâmetro. Isso permite que cada clone tenha sua própria velocidade sem depender de variáveis globais, e facilita futuras alterações — basta modificar o bloco em um lugar.

**Velocidade e tamanho aleatórios**
Cada asteroide nasce com velocidade e tamanho aleatórios, o que cria uma sensação de imprevisibilidade e aumenta o desafio ao longo do tempo de forma orgânica.

---

## 🛠️ Tecnologias

- [Scratch 3.0](https://scratch.mit.edu/) — MIT Media Lab
- Lógica de programação visual com blocos
- Sistema de clones para gerenciamento de múltiplas instâncias

---

## 📚 Contexto acadêmico

Este projeto foi desenvolvido como parte do **CS50x** — o curso introdutório de Ciência da Computação da Universidade de Harvard, disponível gratuitamente pela plataforma edX.

O CS50 é reconhecido como um dos melhores cursos introdutórios de programação do mundo, cobrindo desde conceitos de baixo nível em C até desenvolvimento web e inteligência artificial.

- 🔗 [CS50x no edX](https://www.edx.org/course/introduction-computer-science-harvardx-cs50x)
- 🔗 [Enunciado original do Problem Set 0](https://cs50.harvard.edu/x/psets/0/scratch/)

---

## 👤 Autor

Desenvolvido por **Gabriel Braga Vitareli** como entrega do Problem Set 0 do CS50x.

[![Texto Alternativo](https://github.com/user-attachments/assets/eef40277-e50c-4356-9d70-3ab2080ae4eb)](https://github.com/gabriel-b-vitareli)
