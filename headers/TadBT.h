#include "TadMapa.h"

int IniciaBT();
int RecursaoBT(TMapa* mapa, int posX, int posY, int q, int v[4], int h[4], int passo, int chavesObtidas);

int RecursaoBackTracking(TMapa * mapa, TMapa * resultado);
int corpoRecursao(TMapa * mapa, TMapa * resultado, int X, int Y, int *voltaApagando, int passo, int *ChavesObtidas);