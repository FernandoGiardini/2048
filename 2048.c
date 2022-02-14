#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 4 :
                    
                    nverde();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 8 :
                
                    laranja();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 16 :
                
                    amarelo();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 32 :
                
                    vermelho();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 64 :
                
                    nvermelho();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 128 :
                
                    magenta();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 256 :
                    
                    nmagenta();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 512 :
                
                    nazul();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 1024 :
                
                    ciano();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                case 2048 :
                
                    nciano();
                    printf("%4d", mat[i][j]);
                    reset();

                    break;
                default:
                    reset();
                    printf("%4d", mat[i][j]);
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
            //mat[linha][coluna] = 1024;
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

int checaMatriz(int mat[4][4], int clonemat[4][4]){

    int iguais=0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(clonemat[i][j] = mat[i][j]){
                iguais++;
            }
        }    
    }

    return (iguais == 16);    
}

int sobeValores(int mat[4][4]){

    int matprefuncao[4][4],checagem;//A matriz é clonada ao entrar na função e será comparada com a matriz que sair da função(espera-se, modificada).
                                
    clonaMatriz(mat,matprefuncao);

    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int linhaAtual = i;
            
            while(mat[linhaAtual - 1][j] == 0 && mat[linhaAtual][j] != 0 && linhaAtual > 0){ //Enquanto o bloco de cima estiver vazio e o bloco atual não for vazio
                mat[linhaAtual - 1][j] = mat[linhaAtual][j]; //Bloco de cima recebe o que está no bloco atual
                mat[linhaAtual][j] = 0; //Bloco atual fica vazio
                linhaAtual--; //Verificando o bloco na linha anterior
            }
        }
    }

    checagem = checaMatriz(mat,matprefuncao); // Comparação da matriz inicial com a que saiu do while acima.

    //caso elas sejam idênticas(não houve mudança na matriz após passar pela função de movimentação) significa
    // que não é possível o movimento na direção desta função. Essa informação será usada para verificar se o jogador perdeu.
    return checagem;
}

int cima(int mat[4][4]){

    int possivelmover=0;

    sobeValores(mat); //Subindo todos os blocos antes de juntar
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i - 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o bloco em cima for igual ao bloco atual
                mat[i - 1][j] *= 2;         //Vai multiplicar por 2(mesma coisa que somar)
                mat[i][j] = 0;
            }
        }
    }
    possivelmover = sobeValores(mat);//Subindo os blocos novamente porque juntar gera lugares vazios
       
    return possivelmover;
}

int desceValores(int mat[4][4]){

    int matprefuncao[4][4],checagem;//A matriz é clonada ao entrar na função e será comparada com a matriz que sair da função(espera-se, modificada).
                                
    clonaMatriz(mat,matprefuncao);

    for(int i = 4 - 2; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            int linhaAtual = i;
            
            while(mat[linhaAtual + 1][j] == 0 && mat[linhaAtual][j] != 0 && linhaAtual < 4 - 1){ //Enquanto o bloco de baixo estiver vazio e o bloco atual não for vazio
                mat[linhaAtual + 1][j] = mat[linhaAtual][j]; //Bloco de baixo recebe o que está no bloco atual
                mat[linhaAtual][j] = 0; //Bloco atual fica vazio
                linhaAtual++; //Verificando o bloco na próxima linha
            }
        }
    }

    checagem = checaMatriz(mat,matprefuncao); // Comparação da matriz inicial com a que saiu do while acima.
    //caso elas sejam idênticas(não houve mudança na matriz após passar pela função de movimentação) significa
    // que não é possível o movimento na direção desta função. Essa informação será usada para verificar se o jogador perdeu.
    return checagem;
}

int baixo(int mat[4][4]){

    int possivelmover=0;

    for(int i = 4 - 2; i >= 0; i--){//Começando por baixo para juntar os blocos de baixo para cima, como o jogo funciona
        for(int j = 0; j < 4; j++){
            desceValores(mat); //Descendo todos os blocos antes de juntar
            if(mat[i + 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o bloco em baixo for igual ao bloco atual
                mat[i + 1][j] *= 2;         //Vai multiplicar por 2(mesma coisa que somar)
                mat[i][j] = 0;
            }
            possivelmover = desceValores(mat);//Descendo os blocos novamente porque juntar gera lugares vazios
        }
    }
    return possivelmover;
}

int moveValoresEsquerda(int mat[4][4]){ //Função de tipo inteiro para controle da flag de jogo.

    int matprefuncao[4][4],checagem;//A matriz é clonada ao entrar na função e será comparada com a matriz que sair da função(espera-se, modificada).
                                
    clonaMatriz(mat,matprefuncao);

    for(int i = 0; i < 4; i++){ 
        for(int j = 1; j < 4; j++){
            int colunaAtual = j;
            
            while(mat[i][colunaAtual - 1] == 0 && mat[i][colunaAtual] != 0 && colunaAtual > 0){ //Se o bloco da esquerda estiver vazio e o bloco atual não for vazio
                mat[i][colunaAtual - 1] = mat[i][colunaAtual]; //Bloco da esquerda recebe o que está no bloco atual
                mat[i][colunaAtual] = 0; //Bloco atual fica vazio
                colunaAtual--; //Verificando o bloco na coluna anterior
            }
        }
    }

    checagem = checaMatriz(mat,matprefuncao); // Comparação da matriz inicial com a que saiu do while acima.
    //caso elas sejam idênticas(não houve mudança na matriz após passar pela função de movimentação) significa
    // que não é possível o movimento na direção desta função. Essa informação será usada para verificar se o jogador perdeu.
    return checagem;
}

int esquerda(int mat[4][4]){

    int possivelmover=0;

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            moveValoresEsquerda(mat); //Movendo os blocos para a esquerda para 
            if(mat[i][j - 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da esquerda for igual ao valor da direita
                mat[i][j - 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
            possivelmover = moveValoresEsquerda(mat); //Movendo novamente porque juntar gera blocos vazios
        }
    }    

    return possivelmover;    
}

int moveValoresDireita(int mat[4][4]){

    int matprefuncao[4][4],checagem;//A matriz é clonada ao entrar na função e será comparada com a matriz que sair da função(espera-se, modificada).
                                
    clonaMatriz(mat,matprefuncao);

    for(int i = 0; i < 4; i++){
        for(int j = 4 - 2; j >= 0; j--){
            int colunaAtual = j;
            
            while(mat[i][colunaAtual + 1] == 0 && mat[i][colunaAtual] != 0 && colunaAtual < 4 - 1){ //Enquanto o bloco da direita estiver vazio e bloco atual não for vazio
                mat[i][colunaAtual + 1] = mat[i][colunaAtual]; //Bloco da direita recebe o que está no bloco atual
                mat[i][colunaAtual] = 0; //Bloco atual fica vazio
                colunaAtual++; //Verificando o bloco na próxima coluna
            }
        }
    }

    checagem = checaMatriz(mat,matprefuncao); // Comparação da matriz inicial com a que saiu do while acima.

    //caso elas sejam idênticas(não houve mudança na matriz após passar pela função de movimentação) significa
    // que não é possível o movimento na direção desta função. Essa informação será usada para verificar se o jogador perdeu.
    return checagem;
}    

int direita(int mat[4][4]){

    int possivelmover=0;

    for(int i = 0; i < 4; i++){
        for(int j = 4 - 2; j >= 0; j--){
            moveValoresDireita(mat); //Movendo os blocos para a direita
            if(mat[i][j + 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da direita for igual ao valor da esquerda
                mat[i][j + 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
            possivelmover = moveValoresDireita(mat); //Movendo novamente porque juntar gera espaços vazios
        }
    }

    return possivelmover;  
}

int ganhou(int mat[4][4]){// Esta função verifica se em alguma posição da matriz mapa há um bloco de valor 2048, que categoriza o fim de jogo.

    int vitoria=0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (mat[i][j] == 2048)
                vitoria = 1;
         
    return vitoria;
}

void top5(float tempos[25], char nome[]){

    int maior;
    float aux;

    for(int i = 0; i < 5; i++){
        maior = i;

        for(int j = i+1; j < 25; j++)
        if(tempos[j] > tempos[maior]){
            maior = j;
        }
        
        aux = tempos[i];
        tempos[i] = tempos[maior];
        tempos[maior] = aux;
    }
    
    printf("Jogador: \n");
    puts(nome);
    printf("\nMelhores tempos:\n");
    
    for (int k = 0; k < 5; k++) {
        printf("%.2f\n",tempos[k]);
    }

}

int joga(int mapa[4][4]) { 

    limpa_linha();//para limpar o buffer ao começar um novo round.
    int  naopode=0;
    char movimento, denovo=1;

    while (denovo == 1){
        scanf("%c", &movimento);
        if (movimento == 'w' || movimento == 'a' || movimento == 's' || movimento == 'd'){
           
            limpa_linha();

            switch (movimento){//switch para checar a movimentação do jogador.
            case 'w':
                naopode += cima(mapa);
                break;
            case 'a':
                naopode += esquerda(mapa);
                break;
            case 's':
                naopode += baixo(mapa);
                break;
            case 'd':
                naopode += direita(mapa);
                break;
            
            default:
                break;
            }
            if(naopode == 0){//Se houver um movimento válido, a função bota bloco irá acrescentar mais blocos na matriz.Se não, significa que o jogo acabou.
                botabloco(mapa);
            }else{
                denovo = 0;//então com o jogo acabado levantamos a flag para sair do while e da função joga.
            }
            
            if(ganhou(mapa))//se for verificado que há um bloco de valor 2048, o jogo também acaba.
                denovo = 0;

            imprime(mapa);

        }else{   
        
            while (movimento != 'w' && movimento != 'a' && movimento != 's' && movimento != 'd')
           {
               printf("Esse movimento não é possível, tente novamente!\n");
                scanf("%c", &movimento);
           }

            limpa_linha();
        }
    }

    printf("Deseja jogar novamente? \n Digite 's' para sim ou qualquer outra tecla para não..."); //Pergunta para construção da lista de top 5. 
    scanf("%c", &denovo);

    if(denovo == 's'){//Condicional para manter ou não a flag do laço de repetição responsável pelas partidas jogadas.
        return 1;
    }else{
        return 0;
    }
}


int main(){

    int k=0, denovo=1, mapa[4][4];
    char nomejogador[20];
    float tempoCpu, tempos[25];
    clock_t inicio, fim;

    printf("Informe o nome do jogador: ");
    fgets(nomejogador, 20, stdin);

    while(denovo == 1){
        inicializa(mapa);
        botabloco(mapa);
        botabloco(mapa);
        imprime(mapa);

        inicio = clock ();

        denovo = joga(mapa);

        fim = clock ();

        tempoCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

        tempos[k] = tempoCpu;
        k++;
    }
    
    top5(tempos, nomejogador);
    
    return 0;
}