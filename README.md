## Ex2048 - Azaleia

### Introdução 

Versão em c, para terminal, do jogo 2048.

Este programa é uma adaptação do famoso jogo 2048 para consoles. O usuário insere um comando para a direção que deseja mover os blocos, e o jogo exibe o novo tabuleiro. O jogo só aceita entradas de movimentos válidos, e, ao detectar que não há mais nenhum movimento válido, automaticamente encerra, exibindo a pontuação alcançada.

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

    Valid moves:udlr
      Next move:d
```
* Neste caso o usuário realizou o movimento 'd' (down) e a impressão seguinte do jogo foi:
```
   .      .      .      .


   .      .      .      .
   
   
   .      .      .      .
   
   
   .      .      4      2

    Valid moves:ul
      Next move:d
```
Caso haja a entrada de um movimento inválido, como no exemplo acima, o programa retorna 'Invalid Input' e pede para que haja outra entrada, com um movimento válido.
```
   .      .      .      .


   .      .      .      .
   
   
   .      .      .      .
   
   
   .      .      4      2

    Valid moves:ul
      Next move:d
    Invalid Input.
```
* **Compilação:** Para compilar o jogo, pode-se utilizar um dos comandos abaixo:
  * make ex2048.x SRC=exmain2048.c MAJOR=2 MINOR=1 DEBUG=0
  * gcc -Wall -Wextra -std=gnu99 -fdiagnostics-color=always -Ofast -DVERSION="\"2.1.170611.090824\"" -DBUILD="\"170611.090824\"" -DDEBUG=0 -DD_ -D_FORTIFY_SOURCE=1 -Wl,--defsym,BUILD_170611_090824=0 -lm -lpthread -lncurses -lcurl ex2048.c exmain2048.c -o ex2048.x 2>&1 | tee errors.err

### Orientação

* Autor: Prof. Dr. Ruben Carlo Benante
* Email: rcb@upe.br
* Data: 2017-06-11

### Alunos

* Bernardo de Azevedo Moreira             | bernardo.az.moreira@gmail.com   | https://github.com/BAMoreira      |
* Daidson Fonseca Alves                   | daidson.alves@gmail.com         | https://github.com/daidson        |
* Douglas Azevedo Pereira Dantas          | douglasazevedo839@gmail.com     | https://github.com/DodoAz         |
* Maria Eduarda Azevedo Saraiva de Moraes | eduardasaraivam@gmail.com       | https://github.com/eduardasaraiva |

### Licença

* GNU/GPL v2.0
