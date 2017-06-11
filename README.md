## Ex2048 - Azaleia

### Introdução 

Versão em c, para terminal, do jogo 2048.

Este programa é uma adaptação do famoso jogo 2048 para consoles. O usuário insere um comando para a direção que deseja mover os blocos, e o jogo exibe o novo tabuleiro. O jogo só aceita entradas de movimentos válidos, e ao detectar que não há mais nenhum movimento válido, automaticamente encerra, exibindo a pontuação alcançada.

A pontuação é dada pela soma do valor de todos os blocos fundidos durante o jogo.

### Uso

O programa sempre exibe os movimentos possíveis. Ao digitar uma das letras exibidas (possibilidades: udlr), o jogo executa o movimento. Movimentos inválidos retornam erro. O programa ignora caracteres após o primeiro e limpa o buffer de entrada a cada leitura.

* Ao iniciar o jogo, são escolhidos aleatoriamente duas posições onde são adicionados valores (90% de chance para 2 e 10% para 4):
```
Welcome to the 2048 - Azaleia game!


   .      .      .      .


   .      .      2      .


   .      .      .      .


   .      .      2      .

Valid moves:udlr.
Next move:d
```
* Neste casoo usuário realizou o moviento d (down) e a impressão seguinte do jogo foi:
```
   .      .      .      .


   .      .      .      .
   
   
   .      .      .      .
   
   
   .      .      4      2
Valid moves:ul.
Next move:
```

### Orientação

* Autor: Prof. Dr. Ruben Carlo Benante
* Email: rcb@upe.br
* Data: 2017-06-10
* Licença: GNU/GPL v2.0

