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
                    
                    break;
                case 4 :
                    
                    nverde();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 8 :
                
                    laranja();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 16 :
                
                    amarelo();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 32 :
                
                    vermelho();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 64 :
                
                    nvermelho();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 128 :
                
                    magenta();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 256 :
                    
                    nmagenta();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 512 :
                
                    nazul();
                    printf("%4d", mat[i][j]);
                
                    break;
                case 1024 :
                
                    ciano();
                    printf("%4d", mat[i][j]);
                    
                    break;
                case 2048 :
                
                    nciano();
                    printf("%4d", mat[i][j]);
                    
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
            botou = 1;  //Na linha 92 onde ja foi encontrada uma posição disponível, ela recebe (0+1*2= 2) ou(1+1*2 = 4).
        }               //E levantamos a flag (botou=1) para sair do laço.

    } while(botou == 0);
}

/* Por enquanto a movimentação não ta se comportando da maneira que deve.
   Se ele unir, ele não vai movimentar pro lugar que ele tem que ir se ficar um zero.
   Tô pensando em montar um while no segundo if, onde verifica se é 0.
*/

void sobeValores(int mat[4][4]){
    for(int i = 1; i < 4; i++){ //A operação de juntar dois gera blocos vazios, então utiliza-se o seguinte algoritmo para subir os blocos que podem
        for(int j = 0; j < 4; j++){
            int linhaAtual = i;
            
            while(mat[linhaAtual - 1][j] == 0 && mat[linhaAtual][j] != 0 && linhaAtual > 0){ //Enquanto a linha de cima estiver vazia e a linha atual não for vazia
                mat[linhaAtual - 1][j] = mat[linhaAtual][j]; //Linha de cima recebe o que está na linha atual
                mat[linhaAtual][j] = 0; //Linha atual fica vazia
                linhaAtual--; //Linha atual se tornará a linha anterior a ela
            }
        }
    }
}

void cima(int mat[4][4]){
    sobeValores(mat);
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i - 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o valor em cima for igual ao valor em baixo
                mat[i - 1][j] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
        }
    }
    sobeValores(mat);
}

void baixo(int mat[4][4]){
    for(int i = 0; i < 4 - 1; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i + 1][j] == mat[i][j] && mat[i][j] != 0){ //Se o valor em baixo for igual ao valor em cima
                mat[i + 1][j] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
            if(mat[i + 1][j] == 0 && mat[i][j] != 0){ //Se o valor de baixo for 0 quer dizer que está vazio e pode descer
                mat[i + 1][j] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }
}

void esquerda(int mat[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(mat[i][j - 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da esquerda for igual ao valor da direita
                mat[i][j - 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
            if(mat[i][j - 1] == 0 && mat[i][j] != 0){ //Se o valor da esquerda for 0 quer dizer que está vazio e pode se movimentar
                mat[i][j - 1] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }
}

void direita(int mat[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4 - 1; j++){
            if(mat[i][j + 1] == mat[i][j] && mat[i][j] != 0){ //Se o valor da direita for igual ao valor da esquerda
                mat[i][j + 1] *= 2;         //Vai multiplicar por 2, mesma coisa que somar
                mat[i][j] = 0;
            }
            if(mat[i][j + 1] == 0 && mat[i][j] != 0){ //Se o valor da direita for 0 quer dizer que está vazio e pode se movimentar
                mat[i][j + 1] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }
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

    int fim=0;
    char movimento, denovo;

    while (fim != 1){
        scanf("%c", &movimento);
        scanf("%*c");

        switch (movimento){//switch para checar a movimentação do jogador.
        case 'w':
            cima(mapa);
            break;
        case 'a':
            esquerda(mapa);
            break;
        case 's':
            baixo(mapa);
            break;
        case 'd':
            direita(mapa);
            break;
        
        default:
            break;
        }
        botabloco(mapa);  //adição de mais elementos a matriz a cada movimentação do jogador.
        imprime(mapa);
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

    inicializa(mapa);
    botabloco(mapa);
    botabloco(mapa);
    imprime(mapa);

    while(denovo == 1){
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