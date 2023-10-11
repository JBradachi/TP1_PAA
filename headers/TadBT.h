#include "TadMapa.h"

int IniciaBT(TMapa* mapa, TMapa* resultado);

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int q, int v[4], int h[4], int passo, int chavesObtidas);

int SalvaResultado(TMapa* mapa, TMapa* resultado);

int inicializaResultado(TMapa* mapa, TMapa* resultado);