#include "TadMapa.h"

typedef struct Recursoes{
    int totalDeRecursoes;
    int profundidadeMax;
}TRecursoes;

int IniciaBT(TMapa* mapa, TMapa* resultado, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes);

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passoAtual, int chavesObtidas, int* quantCaminhos, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes);

int salvaResultado(TMapa* mapa, TMapa* resultado);

int inicializaResultado(TMapa* mapa, TMapa* resultado);

int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn);

int mostraTempoReal(TMapa* mapa);

int mostraVetorResultado(TMapa *resultado, int X, int Y, int passo);

void RetornaAnaliseRecursao(TRecursoes recursao);

int IniciaGloboBT(TMapa* mapa, TMapa* resultado, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes);

int RecursaoGloboBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int movimentoX[4], int movimentoY[4], int passoAtual, int chavesObtidas, int* quantCaminhos, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes);

int mostraVetorResultadoGlobo(TMapa *resultado, int X, int Y, int passo);