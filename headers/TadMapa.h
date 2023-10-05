#include <stdio.h>
#include <stdlib.h>

typedef struct Mapa{
    int **mapa;

}Mapa;

int alocaMatriz(int linhas, int colunas, Mapa *mapa);
int mostraMatriz(int linhas, int colunas, Mapa *mapa);
int preencheMatrizTeste(int linhas, int colunas, Mapa *mapa);
