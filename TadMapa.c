#include "./headers/TadMapa.h"


int alocaMatriz(Mapa *mapa){
    mapa->mapa = (char **) malloc(mapa->linha * sizeof(char*));
    for(int i=0; i<(mapa->linha); i++){
        mapa->mapa[i] = (char* )malloc (mapa->coluna * sizeof(char));
    }
}

int mostraMatriz(Mapa *mapa){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            printf(" %c ", mapa->mapa[i][j]);
        }
        printf("\n");
    }
}

int preencheMatrizTeste(Mapa *mapa){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            mapa->mapa[i][j] = 1;
        }
    }
}

int manipulaArquivo(char *pTexto, Mapa *mapa)
{
    FILE *arquivo;
    char c;
    char valor = 'n';
    int i = 0;
    int j = 0;


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
                mapa->mapa[i][j] = valor;
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