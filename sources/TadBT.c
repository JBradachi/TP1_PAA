#include "../headers/TadBT.h"

int IniciaBT(TMapa* mapa, TMapa* resultado){
    int v[4] = {0, 1, 0, -1}, h[4] = {1, 0, -1, 0}; // com essa configutação indiana bones anda -> direita -> baixo -> esquerda -> cima.
    mapa->mapa[0][0].passo = 1; // ponto de início

    inicializaResultado(mapa, resultado);

    RecursaoBT(mapa, resultado, 0, 0, v, h, 1, 0);
    
    if (resultado->mapa[0][0].passo != 0){
        printf("\n");
        mostraResultadoGrafico(resultado);

    }else{
        printf("\n");
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }
    return 0;
}

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passo, int chavesObtidas){
    int xn, yn, i=-1; // só pra i começar em 0 no while
    
    while(i<3){
        i++;
        xn = posX + h[i];
        yn = posY + v[i];
        if(verificaBT(xn, yn, mapa)){ 
            
            // SE QUISER VER O Q TA ROLANDO EM TEMPO REAL SÓ TIRAR OS "//" ABAIXO
            
            //printf("\n");
            //mostraTempoReal(mapa);
            //printf("\n");
            //mostraMatriz(mapa);
            
            
            
            mapa->mapa[yn][xn].passo = passo+1; // ultima passada no baú conta como passo?
            

            if(mapa->mapa[yn][xn].tipo == Chave){
                    chavesObtidas++;
                }

            if((chavesObtidas != mapa->qntChaves) && (mapa->mapa[yn][xn].tipo == Bau)){
                // chegou no baú sem chave, volta pra buscar as chaves 
                mapa->mapa[yn][xn].passo = 0;
            }
            else if((chavesObtidas == mapa->qntChaves) && (mapa->mapa[yn][xn].tipo == Bau)){
                // chegou no baú
                // salva a matriz
                if (verificaSeEhMenosCustoso(mapa, resultado, xn, yn)){ // pegar o passo que está no baú
                    // TODO: salvar todos os resultados
                    salvaResultado(mapa, resultado);
                    
                }
                mapa->mapa[yn][xn].passo = 0;
            }
            else{
                
                RecursaoBT(mapa, resultado, xn, yn, v, h, passo+1, chavesObtidas);
                
                mapa->mapa[yn][xn].passo = 0; // volta o passo, desmarca o caminho
                //if(mapa->mapa[xn][yn].tipo == Chave){
                    //chavesObtidas--;
                //}
            }
        }
        
    }
}

int salvaResultado(TMapa* mapa, TMapa* resultado){
    int i, j;
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            resultado->mapa[i][j].passo = mapa->mapa[i][j].passo;
        }
    }
    return 0;
}

int inicializaResultado(TMapa* mapa, TMapa* resultado){
    int i, j;
    resultado->coluna = mapa->coluna;
    resultado->linha = mapa->linha;
    alocaMatriz(resultado);
    for(i=0; i<mapa->linha; i++){
        for(j=0; j<mapa->coluna; j++){
            resultado->mapa[i][j].tipo = mapa->mapa[i][j].tipo;
            
            resultado->mapa[i][j].passo = 0;
        }
    }
    resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo = (mapa->coluna) * (mapa->linha);
    return 0;
}

int verificaBT(int xn, int yn, TMapa* mapa){
    if(xn>=0 && yn>=0 && (xn < mapa->coluna) && (yn < mapa->linha)){
        if ((mapa->mapa[yn][xn].tipo != Parede ) && (mapa->mapa[yn][xn].passo == 0)){
            return 1;
        }
    }
    
    return 0;
};
int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn){
    if((mapa->mapa[yn][xn].passo) <= (resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo)){
        return 1;
    }
    return 0;
}
int mostraTempoReal(TMapa* mapa){
    system("sleep 0.1");
    mostraResultadoGrafico(mapa);
    fflush(stdout);
};