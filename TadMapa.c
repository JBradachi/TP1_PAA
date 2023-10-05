#include "TadMapa.h"

int alocaMatriz(int linhas, int colunas, int ***matriz){
    int i;
    *matriz = (int **) malloc(linhas * sizeof(int*));
    for(i=0; i<linhas; i++){
        (*matriz)[i] = (int* )malloc (colunas * sizeof(int));
    }
}

int mostraMatriz(int linhas, int colunas, int **matriz){
    int i, j;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int preencheMatrizTeste(int linhas, int colunas, int ***matriz){
    int i, j;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            (*matriz)[i][j] = 1;
        }
    }
}