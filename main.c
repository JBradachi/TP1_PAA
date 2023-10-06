#include <string.h>
#include "./headers/TadMapa.h"

int main(){
    Mapa m1;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste.txt";

    strcat(path, arquivo);
    manipulaArquivo(path, &m1);
    mostraMatriz(&m1);
    printf("\ncompilou\n");
    return 0;
}