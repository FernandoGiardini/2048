# 2048
Programando o jogo "2048".

Como trabalho final da disciplina de laboratório de programação I (2021/2022), foi pedida a implementação de um código para o jogo "2048" na linguagem C,
seguindo as descrições deste enunciado:

    2048 no Terminal

    Descrição do Jogo

    2048 é um jogo de raciocínio criado em março de 2014 pelo italiano Gabriele Cirulli, em que o objetivo é deslizar peças numeradas em uma grade, combiná-las
    e criar um azulejo com o número 2048. O 2048 clássico é jogado em um tabuleiro de 4x4, com peças numéricas que deslizam suavemente quando o jogador as move 
    usando as quatro setas (nesta versão iremos utilizar wasd para representar as setas direcionais). Cada vez, um novo número aparece aleatoriamente em um
    local vazio na placa com um valor de 2 ou 4. Os blocos deslizam o mais longe possível na direção escolhida até que sejam interrompidos por qualquer
    outro bloco ou a borda do tabuleiro.
    Se duas peças do mesmo número colidem durante a movimentação, elas irão se fundir em um azulejo com o valor total das duas peças que colidiram. 
    A peça resultante não pode se fundir com outra peça novamente na mesma jogada. Blocos de uma mesma pontuação deverão ter as mesmas cores. 
    Nesta versão o jogo será finalizado quando obter um azulejo com o valor 2048, além disso um ranking com os 5 menores tempos de resolução do jogo
    deve ser armazenado e apresentado ao final ao lado do nome do jogador.
    Quem quiser conhecer a versão clássica do jogo pode acessar https://rachacuca.com.br/raciocinio/2048/. Divirtam-se!!!

    Como medir o tempo gasto por uma função em C?

    Para calcular o tempo levado por um processo, podemos utilizar a função clock() que está disponível na biblioteca time.h. Pode-se chamar a função clock()
    no início e novamente ao final do trecho de código que se deseja medir, subtrair os valores, e então dividir por CLOCKS PER SEC 
    (o número de ticks de clock por segundo de sua CPU). Por exemplo:

    #include <time . h>
    ...
    clock_t inicio, fim;
    double tempo_de_cpu;
    inicio = clock ();
    /*Faca o trabalho.*/
    fim = clock ();
    tempo de cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    Como imprimir em cores no terminal?

    Nós temos 8 cores ANSI que podem ser utilizadas na saída do terminal. Isso pode ser dobrado para 16, se você levar em consideração que estas cores podem ser mostradas
    no modo padrão ou negrito. Para conseguir acessar essas cores precisamos utilizar o escape seguido pelo código da cor desejada, assim a impressão sairá em outra cor.

    printf ("\033 [0;31m"); //Ajusta a cor para vermelho
    printf ("Hello Colors\n"); //Exibe Hello Colors em vermelho
    printf (" n033[0m"); //Reseta para a cor padrão

    Exemplos de cores que podem ser utilizadas:

    Código 
    Cor
    [0;31m 
    Vermelho
    [1;31m 
    Vermelho Negrito
    [0;32m 
    Verde
    [1;32m 
    Verde Negrito
    [0;33m 
    Amarelo
    [01;33m 
    Amarelo Negrito
    [0;34m 
    Azul
    [1;34m 
    Azul Negrito
    [0;35m 
    Magenta
    [1;35m 
    Magenta Negrito
    [0;36m 
    Ciano
    [1;36m 
    Ciano Negrito



