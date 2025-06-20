# Como iniciar ⏯️ 

Com o projeto baixado, vá à pasta e abra no VScode.  
Caso seu sistema operacional não seja Windows, abra a pasta Linux no projeto e continue o passo a passo por lá. Caso seja Windows, fique na pasta raiz do projeto.

No terminal do VScode digite:

```bash
gcc main.c deckManager.c gameFeatures.c pokerHands.c -o main
```

Você pode iniciar o projeto direto no terminal do VScode, mas para uma experiência melhor, é recomendado que execute no CMD do Windows. Para abrir o CMD na pasta correta, execute o comando no terminal do VScode:

```bash
start cmd
```

Agora, com o CMD aberto, execute:

```bash
.\main
```

Agora você já está executando o projeto.

**OBS**: Eu não sei como funciona o sistema do Linux, então caso esteja usando um e não consiga abrir o CMD, execute o projeto direto no VScode e aumente o tamanho do terminal :)

# ❔Como jogar?

Você já jogou **Balatro**? Se sim, a interface do jogo será bem familiar, pois o projeto é fortemente inspirado no jogo. Caso não tenha jogado ainda, preste atenção na explicação porque será importante para o compreendimento do funcionamento do projeto.

## Entenda a interface 📺

A interface abaixo é a interface principal do projeto:

```bash
--------------------------------------------------------
|000| x |000|             44/52                    |050|
--------------------------------------------------------
Pontuação atual: 000
Mãos: 04 | Descartes: 04

Sua jogada:


Sua mão

3 de Ouros id: 0
6 de Paus id: 1
9 de Copas id: 2
2 de Ouros id: 3
5 de Espadas id: 4
As de Copas id: 5
Rainha de Espadas id: 6
6 de Espadas id: 7
```

Vamos separar por partes para um melhor entendimento.

Esta é a parte principal da interface:

```bash
--------------------------------------------------------
|000| x |000|             44/52                    |050|
--^-------^---------------^--------------------------^--
Fichas   Multi       Cartas restantes           Blind atual
```

**O que significa cada coisa?**

- **Fichas**: são as fichas adquiridas no round atual por meio de cartas jogadas ou mãos.
- **Multi**: o Multi é o multiplicador de fichas que só pode ser conseguido jogando mãos específicas.
- **Cartas restantes**: são as cartas que ainda podem ser adquiridas — cuidado para não ficar sem.
- **Blind atual**: é a pontuação necessária para alcançar a vitória do round atual. Ela muda a cada round.

```bash
Pontuação atual: 000
Mãos: 04 | Descartes: 04
```

- **Pontuação atual**: é o resultado da multiplicação das fichas e do Multi. Ela precisa alcançar o Blind atual para vencer o round.
- **Mãos**: representa a quantidade de jogadas que você pode fazer durante o round.
- **Descartes**: representa a quantidade de descartes que você pode fazer durante o round.

```bash
Sua jogada:


Sua mão

3 de Ouros id: 0
6 de Paus id: 1
9 de Copas id: 2
2 de Ouros id: 3
5 de Espadas id: 4
As de Copas id: 5
Rainha de Espadas id: 6
6 de Espadas id: 7
```

- **Sua jogada**: mostra as cartas selecionadas para serem jogadas ou descartadas.
- **Sua mão**: mostra as cartas que você pode selecionar para jogar ou descartar.

## Entenda o jogo 🎮

Selecione cartas e jogue para conseguir pontuação suficiente para passar para o próximo round.

Para fazer isso, jogue mãos específicas para fazer mais pontos. Aqui está a lista de mãos implementadas:

1. **Par**: jogue 2 cartas do mesmo rank em uma mão.
2. **Dois Pares**: jogue 2 pares em uma mão.
3. **Trio**: jogue 3 cartas do mesmo rank em uma mão.
4. **Full House**: jogue um par e um trio na mesma mão.
5. **Sequência**: jogue 5 cartas de ranks consecutivos na mesma mão.
6. **Flush**: jogue 5 cartas do mesmo naipe na mesma mão.
7. **Straight Flush**: jogue uma sequência com todas as cartas do mesmo naipe (dá muitos pontos).

# Fluxo de Funcionamento

### Salvar e Carregar

Ao iniciar o projeto ele te dá 2 opções:
1. **Novo Jogo**
2. **Carregar Jogo**

Caso escolha a opção de **Carregar Jogo**, ele vai procurar pelo arquivo `save.txt` e vasculhar por jogos salvos. Caso encontre, vai pedir para o jogador escolher um save para carregar o Blind atual e o round de onde o jogador parou.

Caso escolha **Novo Jogo**, será iniciado um novo jogo com tudo padrão.

### Tela principal 

Após passar pela tela principal, o jogo dá ao jogador 2 opções:

- **Modificar jogada**: ao escolher essa opção o jogador pode fazer 2 ações:
  - Inserir uma nova carta no baralho selecionado.
  - Remover uma carta do baralho selecionado.
  
- **Confirmar Jogada**: ao selecionar essa opção o jogador pode fazer 2 ações:
  - **Jogar mão selecionada**: joga a mão selecionada e pontua, perdendo uma mão pela duração total do round.
  - **Descartar mão selecionada**: descarta todas as cartas da mão selecionada e perde um descarte pela duração total do round.

# Avisos ⚠️

### Código não implementado

Durante o código é possível perceber uma variável `STAMP` e um enum `STAMP` nas cartas. Esses seriam selos que modificariam o comportamento das cartas e poderiam ser adquiridos no final de cada round.

Porém, não puderam ser implementados a tempo, mas ainda podem ser adicionados em atualizações futuras.
