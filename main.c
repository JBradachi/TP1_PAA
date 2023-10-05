#include "TadMapa.h"

int main(){
    Mapa m1;
    
    alocaMatriz(3, 3, &(m1.mapa));
    preencheMatrizTeste(3, 3, &(m1.mapa));
    mostraMatriz(3, 3, m1.mapa);
    printf("\ncompilou\n");
    return 0;
}