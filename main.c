#include <string.h>
#include "./headers/TadBT.h"

int main(){
    TMapa m1, resultado;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste.txt";
    strcat(path, arquivo);
    manipulaArquivo(path, &m1);
    mostraMatriz(&m1);
    
    IniciaBT(&m1, &resultado);

    return 0;
}