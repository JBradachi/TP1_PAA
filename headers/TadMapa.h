#include <stdio.h>
#include <stdlib.h>

typedef struct Mapa{
    int **mapa;

}Mapa;

int alocaMatriz(int linhas, int colunas, int ***matriz);
int mostraMatriz(int linhas, int colunas, int **matriz);
int preencheMatrizTeste(int linhas, int colunas, int ***matriz);
