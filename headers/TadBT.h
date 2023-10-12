#include "TadMapa.h"

int IniciaBT(TMapa* mapa, TMapa* resultado);


int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passo, int chavesObtidas);

int salvaResultado(TMapa* mapa, TMapa* resultado);

int inicializaResultado(TMapa* mapa, TMapa* resultado);

int verificaBT(int xn, int yn, TMapa* mapa);