#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define YLW   "\033[33m"
#define RED   "\033[31m"
#define GRN     "\033[32m"
#define NONE  "\033[0m"
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define clear() system("cls"); 
#else
    #include <unistd.h>
    #define clear() system("clear");
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif


enum MaterialLabirinto { //Material labirinto (se e parede, se e espaço vazio, etc)
    EspacoVazio,
    Parede,
    Bau,
    Chave
};
typedef struct Celula {
    enum MaterialLabirinto tipo; // para cada celula, guarda seu tipo (a enum serve para facilitar o entendimento)
    int passo; // passo do indiana bones, se 0 então ele não passou por lá
}TCelula;

typedef struct Mapa{
    TCelula** mapa;
    int linha;
    int coluna;
    int qntChaves;
    int locBau[2];
}TMapa;

int alocaMatriz(TMapa *mapa);
int mostraMatriz(TMapa *mapa);
int preencheMatrizTeste(TMapa *mapa);
int manipulaArquivo(char *pTexto, TMapa *mapa, int isLido);
int mostraResultadoGrafico(TMapa* resultado);
int ehParede(TMapa *mapa, int X, int Y);
int ehChave(TMapa *mapa, int X, int Y);
int ehBau(TMapa *mapa, int X, int Y);
int celulaDentroDoMapa(int xn, int yn, TMapa* mapa);
int verificaCelula(int xn, int yn, TMapa* mapa);
int desalocaMatriz(TMapa* mapa);
