#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<float.h>

int cima(int mat[4][4]);
int baixo(int mat[4][4]);
int esquerda(int mat[4][4]);
int direita(int mat[4][4]);

void verde(){//Linha  4 à 54 são funções para facilitar a troca de cores dos valores da matriz.
    printf("\033[0;32m");
}

void nverde(){
    printf("\033[1;32m");
}

void laranja(){
    printf("\033[0;33m");
}

void amarelo(){
    printf("\033[1;33m");
}

void vermelho(){
    printf("\033[0;31m");
}

void nvermelho(){
    printf("\033[1;31m");
}

void magenta(){
    printf("\033[0;35m");
}

void nmagenta(){
    printf("\033[1;35m");
} 

void azul(){
    printf("\033[0;34m");
}

void nazul(){
    printf("\033[1;34m");
}

void ciano(){
    printf("\033[0;36m");
}

void nciano(){
    printf("\033[1;36m");
}

void reset(){
    printf("\033[0m");
}

void imprime(int mat[4][4]){ //função que imprime na tela do terminal o estado atual da matriz mapa(mapa do jogo/tabuleiro).

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){//Famoso for duplo pra percorrer a matriz de duas dimensões.
            switch(mat[i][j]){// switch para fazer a checagem de valores e assim poder alocar as cores de cada valor. 
                case 2 :
                    
                    verde();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 4 :
                    
                    nverde();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 8 :
                
                    laranja();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 16 :
                
                    amarelo();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 32 :
                
                    vermelho();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 64 :
                
                    nvermelho();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 128 :
                
                    magenta();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 256 :
                    
                    nmagenta();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 512 :
                
                    nazul();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 1024 :
                
                    ciano();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                case 2048 :
                
                    nciano();
                    printf("%5d", mat[i][j]);
                    reset();

                    break;
                default:
                    reset();
                    printf("%5d", mat[i][j]);
                    break;
            }
        }
        printf("\n");//printf usado para separar a matriz corretamente(linha por linha).
    }
    printf("\n");
}

void limpa_linha() {
    scanf("%*[^\n]");   // aqui vai ler lido qualquer lixo do buffer q houver exceto o '\n'
    scanf("%*c");    // aqui vai ser lido o '\n' que é gerado ao se dar um ENTER e vai descatá-lo
}

void inicializa(int mat[4][4]){//função que entrega a todas as posições da matriz o valor 0.

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            mat[i][j]= 0;
        }
    }
}

void botabloco(int mat[4][4]){ //Essa função adiciona a cada movimento do jogador, o valor 2 ou 4 em um espaço vazio(valor 0) da matriz mapa.

    int botou=0, linha=0, coluna=0;// botou é uma variável de controle para o laço de repetição(flag).

    srand(time(NULL));
    do{
        linha = rand() % 4;
        coluna = rand() % 4;   

        if (mat[linha][coluna] == 0){//usando a função rand nas variáveis anteriores,e este if, achamos as posições da matriz que podem  
                                    //receber os novos blocos de valor 2 ou 4(as que tem valor 0).
            mat[linha][coluna] = ((rand() % 2) + 1) * 2;
            //mat[linha][coluna] = 256;
            botou = 1;  //Na linha 92 onde ja foi encontrada uma posição disponível, ela recebe (0+1*2= 2) ou(1+1*2 = 4).
        }               //E levantamos a flag (botou=1) para sair do laço.

    } while(botou == 0);
}

void clonaMatriz(int mat[4][4], int clonemat[4][4]){ //Função para clonar a matriz, necessária para verificar se houve movimento na matriz.

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            clonemat[i][j] = mat[i][j];
        }    
    }
}

int matrizIgual(int mat1[4][4], int mat2[4][4]){
    int quantidadeIguais = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(mat1[i][j] == mat2[i][j]){
                quantidadeIguais++;
            }
        }    
    }

    return quantidadeIguais == 16;
}

int sobeValores(int mat[4][4]){
    int movimentou = 0;
    
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int linhaAtual = i;
            
            while(mat[linhaAtual - 1][j] == 0 && mat[linhaAtual][j] != 0 && linhaAtual > 0){ //Enquanto o bloco de cima estiver vazio e o bloco atual não for vazio
                mat[linhaAtual - 1][j] = mat[linhaAtual][j]; //Bloco de cima recebe o que está no bloco atual
                mat[linhaAtual][j] = 0; //Bloco atual fica vazio
                linhaAtual--; //Verificando o bloco na linha anterior
                movimentou = 1;
            }
        }
    }

    return movimentou;
}

int cima(int mat[4][4]){
    int movimentou = 0;

    movimentou = sobeValores(mat); //Subindo todos os blocos antes de juntar
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i - 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o bloco em cima for igual ao bloco atual
                mat[i - 1][j] *= 2;         //Vai multiplicar por 2(mesma coisa que somar)
                mat[i][j] = 0;
                movimentou = 1;
            }
        }
    }

    if(!movimentou){
        movimentou = sobeValores(mat);
    }
    else{
        sobeValores(mat);
    }

    return movimentou;
}

int desceValores(int mat[4][4]){

    int movimentou = 0;

    for(int i = 4 - 2; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            int linhaAtual = i;
            
            while(mat[linhaAtual + 1][j] == 0 && mat[linhaAtual][j] != 0 && linhaAtual < 4 - 1){ //Enquanto o bloco de baixo estiver vazio e o bloco atual não for vazio
                mat[linhaAtual + 1][j] = mat[linhaAtual][j]; //Bloco de baixo recebe o que está no bloco atual
                mat[linhaAtual][j] = 0; //Bloco atual fica vazio
                linhaAtual++; //Verificando o bloco na próxima linha
                movimentou = 1;
            }
        }
    }

    return movimentou;
}

int baixo(int mat[4][4]){

    int movimentou = 0;
    
    movimentou = desceValores(mat);//Descendo todos os blocos antes de juntar
    for(int i = 4 - 2; i >= 0; i--){//Começando por baixo para juntar os blocos de baixo para cima, como o jogo funciona
        for(int j = 0; j < 4; j++){
            if(mat[i + 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o bloco em baixo for igual ao bloco atual
                mat[i + 1][j] *= 2;         //Vai multiplicar por 2(mesma coisa que somar)
                mat[i][j] = 0;
                movimentou = 1;
            }
        }
    }
    if(!movimentou){
        movimentou = desceValores(mat);//Descendo os blocos novamente porque juntar gera lugares vazios
    }
    else{
        desceValores(mat);//Descendo os blocos novamente porque juntar gera lugares vazios
    }

    return movimentou;
}

int moveValoresEsquerda(int mat[4][4]){ //Função de tipo inteiro para controle da flag de jogo.

    int movimentou = 0;

    for(int i = 0; i < 4; i++){ 
        for(int j = 1; j < 4; j++){
            int colunaAtual = j;
            
            while(mat[i][colunaAtual - 1] == 0 && mat[i][colunaAtual] != 0 && colunaAtual > 0){ //Se o bloco da esquerda estiver vazio e o bloco atual não for vazio
                mat[i][colunaAtual - 1] = mat[i][colunaAtual]; //Bloco da esquerda recebe o que está no bloco atual
                mat[i][colunaAtual] = 0; //Bloco atual fica vazio
                colunaAtual--; //Verificando o bloco na coluna anterior
                movimentou = 1;
            }
        }
    }


    return movimentou;
}

int esquerda(int mat[4][4]){

    int movimentou;

    movimentou = moveValoresEsquerda(mat); //Movendo os blocos para a esquerda para 
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(mat[i][j - 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da esquerda for igual ao valor da direita
                mat[i][j - 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
                movimentou = 1;
            }
        }
    }
    if(!movimentou){
        movimentou = moveValoresEsquerda(mat); //Movendo novamente porque juntar gera blocos vazios
    }
    else{
        moveValoresEsquerda(mat); //Movendo novamente porque juntar gera blocos vazios
    }

    return movimentou;    
}

int moveValoresDireita(int mat[4][4]){

    int movimentou = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 4 - 2; j >= 0; j--){
            int colunaAtual = j;
            
            while(mat[i][colunaAtual + 1] == 0 && mat[i][colunaAtual] != 0 && colunaAtual < 4 - 1){ //Enquanto o bloco da direita estiver vazio e bloco atual não for vazio
                mat[i][colunaAtual + 1] = mat[i][colunaAtual]; //Bloco da direita recebe o que está no bloco atual
                mat[i][colunaAtual] = 0; //Bloco atual fica vazio
                colunaAtual++; //Verificando o bloco na próxima coluna
                movimentou = 1;
            }
        }
    }

    return movimentou;
}    

int direita(int mat[4][4]){

    int movimentou = 0;

    movimentou = moveValoresDireita(mat); //Movendo os blocos para a direita

    for(int i = 0; i < 4; i++){
        for(int j = 4 - 2; j >= 0; j--){
            if(mat[i][j + 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da direita for igual ao valor da esquerda
                mat[i][j + 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
                movimentou = 1;
            }
        }
    }

    if(!movimentou){
        movimentou = moveValoresDireita(mat); //Movendo novamente porque juntar gera espaços vazios
    }
    else{
        moveValoresDireita(mat); //Movendo novamente porque juntar gera espaços vazios
    }

    return movimentou;
}

int ganhou(int mat[4][4]){// Esta função verifica se em alguma posição da matriz mapa há um bloco de valor 2048, que categoriza o fim de jogo.
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (mat[i][j] == 2048){
                return 1;
            }
        }
    }
    return 0;
}

void top5(double tempos[25], char nome[]){

    int indiceAnterior, indiceAtual, valorAuxiliar;
    for(int i = 1; i < 25; i++){
        indiceAnterior = i - 1;
        while(indiceAnterior >= 0){ //Enquanto a posição anterior for maior que zero, quer dizer que eu posso verificar as coisas
            indiceAtual = indiceAnterior + 1; //indiceAtual é a variável que armazena o indice do que está sendo verificada
            if(tempos[indiceAtual] < tempos[indiceAnterior]){ //Se tempos na posição que está sendo verificada for menor do que o da posição anterior.
                                                              //Se a posição anterior for 0 e a posição atual for diferente de 0 ele também vai colocar como se fosse maior
                int valorAuxiliar = tempos[indiceAnterior]; //Ele vai armazenar o valor que está na posição anterior numa variavel auxiliar
                tempos[indiceAnterior] = tempos[indiceAtual]; //Então vai colocar o valor da posição atual na posição anterior
                tempos[indiceAtual] = valorAuxiliar; //Vai pegar o valor que foi salvo antes na variavel auxiliar e colocar na posição atual
            }
            else{
                break; //Se a posição anterior não for menor ele para o while
            }
            indiceAnterior -= 1; //Diminui o valor do indice anterior
        }
    }
    printf("Jogador: ");
    puts(nome);
    printf("\nMelhores tempos:\n");
    
    int minutos, segundos, milisegundos;

    for (int k = 0; k < 5; k++) {
        if(tempos[k] == DBL_MAX){
            tempos[k] = 0;
        }
        minutos = tempos[k] / 60;
        segundos = tempos[k] - (tempos[k] / 60);
        milisegundos = (tempos[k] - (int)tempos[k]) * 100;
        printf("%02d:%02d.%02d\n", minutos, segundos, milisegundos);
    }

}

int podeMovimentar(int mat[4][4]){ //função para verificar se pode ser feito algum movimento
    int cloneMatriz[4][4];
    clonaMatriz(mat, cloneMatriz);

    cima(cloneMatriz);

    if(!matrizIgual(mat, cloneMatriz)){ //se a matriz original for diferente da matriz depois de mover quer dizer que o movimento pode ser feito
        return 1;
    }

    baixo(cloneMatriz);

    if(!matrizIgual(mat, cloneMatriz)){
        return 1;
    }

    esquerda(cloneMatriz);

    if(!matrizIgual(mat, cloneMatriz)){
        return 1;
    }

    direita(cloneMatriz);
    
    if(!matrizIgual(mat, cloneMatriz)){
        return 1;
    }

    return 0;
}

int joga(int mapa[4][4]) { 
    int  movimentou = 0;
    char movimento[2], denovo=1;

    while (denovo == 1){
        limpa_linha();
        scanf("%1s", movimento);
        if (movimento[0] == 'w' || movimento[0] == 'a' || movimento[0] == 's' || movimento[0] == 'd'){
            switch(movimento[0]){//switch para checar a movimentação do jogador.
            case 'w':
                movimentou = cima(mapa);
                break;
            case 'a':
                movimentou = esquerda(mapa);
                break;
            case 's':
                movimentou = baixo(mapa);
                break;
            case 'd':
                movimentou = direita(mapa);
                break;
            
            default:
                break;
            }
            if(movimentou){//Se houver um movimento válido, a função bota bloco irá acrescentar mais blocos na matriz.Se não, significa que o jogo acabou.
                botabloco(mapa);
            }else{
                if(!podeMovimentar(mapa)){
                    denovo = 0;//então com o jogo acabado levantamos a flag para sair do while e da função joga.
                }
            }
            imprime(mapa);
            denovo = podeMovimentar(mapa);
            if(ganhou(mapa)){//se for verificado que há um bloco de valor 2048, o jogo também acaba.
                denovo = 0;
                printf("Você Venceu!!\n\n");
            }
            else if(denovo == 0){
                printf("Você Perdeu :(\n\n");
            }

        }else{   
            if(movimento[0] != 'w' && movimento[0] != 'a' && movimento[0] != 's' && movimento[0] != 'd'){
                printf("Esse movimento não é possível, tente novamente!\n");
            }
        }
    }

    limpa_linha();
    printf("Deseja jogar novamente?\nDigite 's' para sim ou qualquer outra tecla para não...\n"); //Pergunta para construção da lista de top 5. 
    scanf("%c", &denovo);

    return denovo =='s';//Condicional para manter ou não a flag do laço de repetição responsável pelas partidas jogadas.
}


int main(){

    int k=0, denovo=1, mapa[4][4];
    char nomejogador[20];
    double tempos[25];

    for(int i = 0; i < 25; i++){
        tempos[i] = DBL_MAX;
    }

    struct timespec comeco, fimtempo;

    printf("Informe o nome do jogador: ");
    scanf("%19[^\n]s", nomejogador);

    while(denovo == 1){
        inicializa(mapa);
        botabloco(mapa);
        botabloco(mapa);
        imprime(mapa);

        clock_gettime(CLOCK_REALTIME, &comeco);
        denovo = joga(mapa);

        clock_gettime(CLOCK_REALTIME, &fimtempo);

        double tempoGasto = (fimtempo.tv_sec - comeco.tv_sec) + (fimtempo.tv_nsec - comeco.tv_nsec)/ 1000000000.0;
        tempos[k] = tempoGasto;
        k++;
    }
    
    top5(tempos, nomejogador);
    
    return 0;
}