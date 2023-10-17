#include "TadMapa.h"

int IniciaBT(TMapa* mapa, TMapa* resultado);

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passoAtual, int chavesObtidas, int* quantCaminhos);

int salvaResultado(TMapa* mapa, TMapa* resultado);

int inicializaResultado(TMapa* mapa, TMapa* resultado);

int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn);

int mostraTempoReal(TMapa* mapa);