#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


// Como salvar a matriz? a matriz resposta faz parte do tad ou é uma matriz separada?
// para o caso de mostrar todas as possibilidades de caminhos colocar flag na recursãoBT e dentro dela chamar o mostra matriz
// é interesante criar um tad resposta pra ir guardando a matriz e se possúi resposta, porque vai acomulando respostas certas e queremos encontrar amelhor solução
// a flag q ainda continua sendo útil para percorrer a matriz e ir voltando os passos
// o fim de RecursaoBT sempre será 0 pois BT tentará fazer todos os caminhos possíveis

typedef struct Mapa{
    TCelula** mapa;
    int linha;
    int coluna;
    int qntChaves;
    int locBau[2];
}TMapa;

int verificaCelula(TMapa *mapa, int X, int Y);
int alocaMatriz(TMapa *mapa);
int mostraMatriz(TMapa *mapa);
int preencheMatrizTeste(TMapa *mapa);
int manipulaArquivo(char *pTexto, TMapa *mapa);