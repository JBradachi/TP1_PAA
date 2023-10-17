#include "TadMapa.h"

int IniciaBT(TMapa* mapa, TMapa* resultado, char mostrarPossibilidades);

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passoAtual, int chavesObtidas, int* quantCaminhos, char mostrarPossibilidades);

int salvaResultado(TMapa* mapa, TMapa* resultado);

int inicializaResultado(TMapa* mapa, TMapa* resultado);

int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn);

int mostraTempoReal(TMapa* mapa);

int mostraVetorResultado(TMapa *resultado, int X, int Y, int passo);