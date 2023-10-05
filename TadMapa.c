#include "./headers/TadMapa.h"


int alocaMatriz(int linhas, int colunas, Mapa *mapa){
    int i;
    mapa->mapa = (int **) malloc(linhas * sizeof(int*));
    for(i=0; i<linhas; i++){
        mapa->mapa[i] = (int* )malloc (colunas * sizeof(int));
    }
}

int mostraMatriz(int linhas, int colunas, Mapa *mapa){
    int i, j;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf(" %d ", mapa->mapa[i][j]);
        }
        printf("\n");
    }
}

int preencheMatrizTeste(int linhas, int colunas, Mapa *mapa){
    int i, j;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            mapa->mapa[i][j] = 1;
        }
    }
}