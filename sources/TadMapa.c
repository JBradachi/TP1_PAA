#include "../headers/TadMapa.h"

//retorna 1 para celula valida e 0 para invalida

int verificaCelula(TMapa *mapa, int X, int Y){

    // TODO: verificar se a ordem X = coluna e Y = linha esta correta
    if (X < 0 || X >= mapa->coluna){
        return 0;
    }
    if (Y < 0 || Y >= mapa->linha){
        return 0;
    }
    return 1;
}

//retorna se eh parede
int ehParede(TMapa *mapa, int X, int Y){
    if (mapa->mapa[X][Y].tipo == Parede){
        return 1;
    }
    return 0;
}

//retorna se eh chave
int ehChave(TMapa *mapa, int X, int Y){
    if (mapa->mapa[X][Y].tipo == Chave){
        return 1;
    }
    return 0;
}

//retorna se eh bau
int ehBau(TMapa *mapa, int X, int Y){
    if (mapa->mapa[X][Y].tipo == Bau){
        return 1;
    }
    return 0;
}

int alocaMatriz(TMapa *mapa){
    mapa->mapa = (TCelula **) malloc(mapa->linha * sizeof(TCelula*));
    for(int i=0; i<(mapa->linha); i++){
        mapa->mapa[i] = (TCelula* )malloc (mapa->coluna * sizeof(TCelula));
    }
}

int mostraMatriz(TMapa *mapa){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            switch (mapa->mapa[i][j].tipo){
                case Parede:
                    printf(" 1 ");
                    break;
                case EspacoVazio:
                    printf(" 0 ");
                    break;
                case Chave:
                    printf(" C ");
                    break;
                case Bau:
                    printf(" X ");
                    break;
                
                default:
                    break;
                }
        }
        printf("\n");
    }
}


int mostraMatrizPassos(TMapa *mapa){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            printf("\t%d ", mapa->mapa[i][j].passo);
        }
        printf("\n");
    }
}

int preencheMatrizTeste(TMapa *mapa){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            mapa->mapa[i][j].tipo = 1;
        }
    }
}

int manipulaArquivo(char *pTexto, TMapa *mapa)
{
    FILE *arquivo;
    char c;
    char valor = 'n';
    int i = 0;
    int j = -1;


    // fscanf lê uma linha inteira do arquivo
    printf("Arquivo: %s\n", pTexto);

    
    if ((arquivo = fopen(pTexto, "r")) != NULL)
    {
        fscanf(arquivo, "%d %d", &mapa->linha, &mapa->coluna);
        fscanf(arquivo, "%d", &mapa->qntChaves);
        fscanf(arquivo, "%d %d", &mapa->locBau[0], &mapa->locBau[1]);

        alocaMatriz(mapa);
        while (fscanf(arquivo, "%c", &valor) != EOF)
        { 
            if (valor == '\n')
            {
                j++;
                i = 0;
            }else if(valor != ' '){
                switch (valor)
                {
                case '1':
                    mapa->mapa[i][j].tipo = Parede;
                    break;
                case '0':
                    mapa->mapa[i][j].tipo = EspacoVazio;
                    break;
                case 'C':
                    mapa->mapa[i][j].tipo = Chave;
                    break;
                case 'X':
                    mapa->mapa[i][j].tipo = Bau;
                    break;
                
                default:
                    break;
                }
                mapa->mapa[i][j].passo = 0;
                i++;
            }

        }
    }else{
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    fclose(arquivo);
    return 1;
}