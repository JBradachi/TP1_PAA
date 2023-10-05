#include "./headers/TadMapa.h"

int main(){
    Mapa m1;
    
    alocaMatriz(3, 3, &m1);
    preencheMatrizTeste(3, 3, &m1);
    mostraMatriz(3, 3, &m1);
    printf("\ncompilou\n");
    return 0;
}