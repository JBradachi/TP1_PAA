#include "./headers/TadBT.h"

int IniciaBT(TMapa* mapa, TMapa* resultado){
    int v[4] = {0, -1, 0, 1}, h[4] = {1, 0, -1, 0}, ehCaminho = 0; // com essa configutação indiana bones anda -> direita -> baixo -> esquerda -> cima.
    mapa->mapa[0][0].passo = 1; // ponto de início

    inicializaResultado(mapa, resultado);

    RecursaoBT(mapa, resultado, 0, 0, ehCaminho, v, h, 1, 0);

    if (resultado->mapa[0][0].passo != 0){
        // retorna resultado obtido

    }else{
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }
}

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int ehCaminhoAnterior, int v[4], int h[4], int passo, int chavesObtidas){
    int xn, yn, ehCaminho, i=-1; // só pra i começar em 0 no while
    
    while(ehCaminho || i<3){
        i++;
        ehCaminho = 0;
        xn = posX + h[i];
        yn = posY + v[i];
        if((xn < mapa->coluna) && (yn < mapa->linha) && (mapa->mapa[xn][yn].tipo != '1') && (mapa->mapa[xn][yn].passo == 0)){ // != "1" testa se é diferente de parede
            
            mapa->mapa[xn][yn].passo = passo+1; // ultima passada no baú conta como passo?

            if(mapa->mapa[xn][yn].tipo == 'C'){
                    chavesObtidas++;
                }

            if((chavesObtidas != mapa->qntChaves) && (mapa->mapa[xn][yn].tipo == 'X')){
                // chegou no baú sem chave, volta pra buscar as chaves 
                ehCaminho = 0; // analizar pra q serve ehCaminho
                return 0;
            }
            else if((chavesObtidas == mapa->qntChaves) && (mapa->mapa[xn][yn].tipo == 'X')){
                // chegou no baú
                // ehCaminho = 1; analizar pra q serve ehCaminho

                // salva a matriz
                if (mapa->mapa[mapa->locBau[0]][mapa->locBau[1]].passo < resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo){ // pegar o passo que está no baú
                    SalvaResultado(mapa, resultado);
                    ehCaminho = 0; // analizar pra q serve ehCaminho
                    return 0;
                }
            }
            else{

                RecursaoBT(mapa, resultado, xn, yn, ehCaminho, v, h, passo+1, chavesObtidas);
                if(ehCaminho == 0){
                    mapa->mapa[xn][yn].passo = 0; // volta o passo, desmarca o caminho
                    if(mapa->mapa[xn][yn].tipo == 'C'){
                        chavesObtidas--;
                    }
                }
                else{
                    ehCaminho = 1;
                }
            }
        }
    }
    ehCaminhoAnterior = ehCaminho;
}

int salvaResultado(TMapa* mapa, TMapa* resultado){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            resultado->mapa[i][j].passo = mapa->mapa[i][j].passo;
        }
    }
}

int inicializaResultado(TMapa* mapa, TMapa* resultado){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            resultado->mapa[i][j].tipo = mapa->mapa[i][j].tipo;
            resultado->mapa[0][0].passo = 0;
        }
    }
}
