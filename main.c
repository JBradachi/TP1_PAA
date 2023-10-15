#include <string.h>
#include "./headers/TadBT.h"

int main(){
    TMapa m1, resultado;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste.txt";

    strcat(path, arquivo);
    manipulaArquivo(path, &m1);
    printf("linha: %d , coluna %d\n", m1.linha, m1.coluna);
    mostraMatriz(&m1);
    printf("linha: %d , coluna %d\n", m1.linha, m1.coluna);
    mostraMatrizPassos(&m1);
    printf("\ncompilou\n");
    RecursaoBackTracking(&m1, &resultado);
    return 0;
}