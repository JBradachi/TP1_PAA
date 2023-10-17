#include "../headers/TadMapa.h"

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

int celulaValida(int xn, int yn, TMapa* mapa){
    
    // verifica se está dentro do mapa
    if(xn>=0 && yn>=0 && (xn < mapa->coluna) && (yn < mapa->linha)){

        // verifica se é possível ir (caso de ser parede e caso de ser caminho já andado)
        if (!ehParede(mapa, yn, xn) && (mapa->mapa[yn][xn].passo == 0)){
            return 1;
        }
    }
    
    return 0;
}

int verificaCelula(int xn, int yn, TMapa* mapa){
    
    // verifica se está dentro do mapa
    if(xn>=0 && yn>=0 && (yn < mapa->coluna) && (xn < mapa->linha)){

        // verifica se é possível ir (caso de ser parede e caso de ser caminho já andado)
        if ((mapa->mapa[xn][yn].tipo != Parede ) && (mapa->mapa[xn][yn].passo == 0)){
            return 1;
        }
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
                    printf(GRN " 1 ");
                    break;
                case EspacoVazio:
                    printf( CYN " 0 ");
                    break;
                case Chave:
                    printf(YLW " C ");
                    break;
                case Bau:
                    printf(RED " X ");
                    break;
                
                default:
                    break;
                }
        }
        printf(NONE"\n");
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
                    mapa->mapa[j][i].tipo = Parede;
                    break;
                case '0':
                    mapa->mapa[j][i].tipo = EspacoVazio;
                    break;
                case 'C':
                    mapa->mapa[j][i].tipo = Chave;
                    break;
                case 'X':
                    mapa->mapa[j][i].tipo = Bau;
                    break;
                
                default:
                    break;
                }
                mapa->mapa[j][i].passo = 0;
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

int mostraResultadoGrafico(TMapa* resultado){
    int i, j;
    for(i=0; i<resultado->linha; i++){
        for(j=0; j<resultado->coluna; j++){
                if(resultado->mapa[i][j].tipo == Parede){
                    printf( GRN " P ");
                }else if(resultado->mapa[i][j].tipo == EspacoVazio && resultado->mapa[i][j].passo == 0){
                    printf( CYN " %d ", resultado->mapa[i][j].passo);
                }else if(resultado->mapa[i][j].tipo == EspacoVazio && resultado->mapa[i][j].passo > 0){
                    printf( WHT " %d ", resultado->mapa[i][j].passo);
                }else if(resultado->mapa[i][j].tipo == Bau){
                    printf( RED " %d ", resultado->mapa[i][j].passo);
                }else if(resultado->mapa[i][j].tipo == Chave){
                    printf( YLW " %d ", resultado->mapa[i][j].passo);
                }
            
            if(resultado->mapa[i][j].passo < 10){
                printf(" ");
            }
        }
        printf(NONE"\n");
    }
}
