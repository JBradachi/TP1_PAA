#include <string.h>
#include "./headers/TadMapa.h"

int main(){
    TMapa m1, resultado;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste copy.txt";
    printf("Digite o nome do arquivo: ");
    scanf("%s", &arquivo);

    strcat(path, arquivo);
    manipulaArquivo(path, &m1);
    mostraMatriz(&m1);
    
    IniciaBT(&m1, &resultado);

    return 0;
}