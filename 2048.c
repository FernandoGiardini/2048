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
                    printf("%d", mat[i][j]);
                    
                    break;
                case 4 :
                    
                    nverde();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 8 :
                
                    laranja();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 16 :
                
                    amarelo();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 32 :
                
                    vermelho();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 64 :
                
                    nvermelho();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 128 :
                
                    magenta();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 256 :
                    
                    nmagenta();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 512 :
                
                    nazul();
                    printf("%d", mat[i][j]);
                
                    break;
                case 1024 :
                
                    ciano();
                    printf("%d", mat[i][j]);
                    
                    break;
                case 2048 :
                
                    nciano();
                    printf("%d", mat[i][j]);
                    
                    break;
                default:
                    reset();
                    printf("%d", mat[i][j]);
                    break;
            }
        }
        printf("\n");//printf usado para separar a matriz corretamente(linha por linha).
    }
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

void cima(){

}

void baixo(){

}

void esquerda(){

}

void direita(){

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