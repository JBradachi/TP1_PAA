#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mapa{
    char** mapa;
    int linha;
    int coluna;
    int qntChaves;
    int locBau[2];
}Mapa;

int alocaMatriz(Mapa *mapa);
int mostraMatriz(Mapa *mapa);
int preencheMatrizTeste(Mapa *mapa);
int manipulaArquivo(char *pTexto, Mapa *mapa);