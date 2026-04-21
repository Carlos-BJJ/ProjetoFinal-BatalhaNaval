#include <stdio.h>

//Definindo as constantes das linhas do tabuleiro e das habilidades
#define Linhas 10
#define Colunas 10
#define linhasHab 3
#define colunasHab 5

int main(){

//Matrizes e variaveis importantes declaradas
int tabuleiro[Linhas][Colunas] = {0};
int habilidadeCruz[linhasHab][colunasHab];
int habilidade1[linhasHab][colunasHab];
int centro = colunasHab / 2;
int centroOcta = 2;
int matrizHabOcta[linhasHab][colunasHab];


//Definindo os navios
int NavioHorizontal [3] = {4, 4, 4}, NavioVertical [3] = {4, 4, 4};
int NavioDiagonal1 [3] = {4, 4, 4}, NavioDiagonal2 [3] = {4, 4, 4};

//Definindo as coordenadas dos navios
int linhaH = 2, colunaH = 1; // Navio Horizontal
int linhaV = 5, colunaV = 7; // Navio Vertical
int LinhaD1 = 4, ColunaD1 = 1; //Navio diagonal
int LinhaD2 = 0, ColunaD2 = 6; //Navio diagonal


//LOOPS PARA O POSICIONAMENTO DOS NAVIOS
//LOOP PARA O NAVIO NA DIAGONAL
for(int i = 0; i < 3; i++){
    tabuleiro[LinhaD1 + i][ColunaD1 + i] = NavioDiagonal1[i];
} 

for(int i = 0; i < 3; i++){
    tabuleiro[LinhaD2 + i][ColunaD2 + i] = NavioDiagonal2[i];
}
/* Eu somo a coluna e linha com i, pois eu quero que os valores estejam
em diagonal */

//LOOP PARA O NAVIO NA HORIZONTAL
for(int i = 0; i < 3; i++){
    tabuleiro[linhaH][colunaH + i] = NavioHorizontal[i];
} 
/* Eu somo a coluna com i, pois eu quero que os valores estejam
um do lado do outro*/

//LOOP PARA O NAVIO NA VERTICAL
for(int i = 0; i < 3; i++){
    tabuleiro[linhaV + i][colunaV] = NavioVertical[i];
}
/*
Eu somo a linha com i, pois eu quero que os valores estejam
um embaixo do outro
*/

//LOOPS PARA O POSICIONAMENTO DAS HABILIDADES

//Definindo as coordenadas onde a matriz da habilidade coomeça 
int linhaInicialHab1 = 0, colunaInicialHab1 = 0;
int linhaInicialHabCruz = 7, colunaInicialHabCruz = 0;
int linhaInicialHabOcta = 7, colunaInicialHabOcta = 5 ; 

//Loop para a habilidade do cone
for(int i = 0; i < linhasHab; i++){
    for(int j = 0; j < colunasHab; j++){
        
        if (j >= centro - i && j <= centro + i){
            habilidade1[i][j] = 1;
        } else{
            habilidade1[i][j] = 0;
        }

        //Se a soma da linha inicial com o indice da linha for maior que o número de linhas então irá passar da borda.
        //Essa mesma regra serve pras colunas
        if((linhaInicialHab1 + i) < Linhas && (colunaInicialHab1 + i) < Colunas){
        tabuleiro[linhaInicialHab1 + i][colunaInicialHab1 + j] = habilidade1[i][j];
        } else{
            printf("Essas coordenadas da habilidade de cone saem das bordas do tabuleiro!");
            return 1;
        }
    }      
}

//Loop para habilidade da cruz
for(int i = 0; i < linhasHab; i++){
        for(int j = 0; j < colunasHab; j++){
            if(i == 1 || j == 2){
                habilidadeCruz[i][j] = 2; 
            }else {
                habilidadeCruz[i][j] = 0;   
            }
            
            if((linhaInicialHabCruz + i) < Linhas && (colunaInicialHabCruz + j) < Colunas){
                tabuleiro[linhaInicialHabCruz + i][colunaInicialHabCruz + j] = habilidadeCruz[i][j];
            }else{
            printf("Essas coordenadas da habilidade de cruz saem das bordas do tabuleiro!");
            return 1;
        }
        }
    }

//Loop para habilidade do octaedro
for(int i = 0; i < linhasHab; i++){
        // Calcula a distância do centro para preencher com '3'
        // Na linha 0 e 2, dist é 0 (apenas o centro). Na linha 1, dist é 1.
        int dist = (i % 2 == 0) ? 0 : 1;

        for(int j = 0; j < colunasHab; j++){
            // Se j estiver dentro do alcance da distância do centro
            if (j >= centroOcta - dist && j <= centroOcta + dist){
                matrizHabOcta[i][j] = 3;    
            }
            else {
                matrizHabOcta[i][j] = 0;    
            }

            if((linhaInicialHabOcta + i) < Linhas && (colunaInicialHabOcta + j) < Colunas){
                tabuleiro[linhaInicialHabOcta + i][colunaInicialHabOcta + j] = matrizHabOcta[i][j];
            }
            else{
            printf("Essas coordenadas da habilidade de cruz saem das bordas do tabuleiro!");
            return 1;
            }

    printf("\n");

    }
}


printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
printf("[1]Habilidade Cone\n");
printf("[2]Habilidade Cruz\n");
printf("[3]Habilidade Octaedro\n");
printf("[4]Habilidade Navios\n");
for (int i = 0; i < Linhas; i++){
    for (int j = 0; j < Colunas; j++){
        printf("%d ", tabuleiro[i][j]);
}
    printf("\n");
}

} 