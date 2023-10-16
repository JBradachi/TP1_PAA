#include "../headers/TadBT.h"

int IniciaBT(TMapa* mapa, TMapa* resultado){

    int v[4] = {0, 1, 0, -1}, h[4] = {1, 0, -1, 0}; 
    // com essa configutação indiana bones anda -> direita -> baixo -> esquerda -> cima.
    
    // ponto de início já começa como 1
    mapa->mapa[0][0].passo = 1; 

    // prepara a variável que irá guardar o resultado
    inicializaResultado(mapa, resultado);

    // inicia a recursão do primeiro ponto
    RecursaoBT(mapa, resultado, 0, 0, v, h, 1, 0);
    
    // se possúi resultado (variável resultado foi alterada), mostra o resultado
    if (resultado->mapa[0][0].passo != 0){
        printf("\n");
        mostraResultadoGrafico(resultado);

    }
    else{
        printf("\n");
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }

    return 0;
}

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int v[4], int h[4], int passoAtual, int chavesObtidas){
    int xn, yn, i=-1; // só pra i começar em 0 no while
    
    // "i" é o indice referente a como indiana bones irá dar pelo labirinto
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
            
            
            // atualização dos passos
            // ultima passada no baú conta como passo

            mapa->mapa[yn][xn].passo = passoAtual+1; 
            
            // se for chave aumenta a quantidade de chaves obtidas
            if(mapa->mapa[yn][xn].tipo == Chave){
                    chavesObtidas++;
                }

            // se for baú e não tem a quantidade de chaves o suficiente
            if((chavesObtidas != mapa->qntChaves) && (mapa->mapa[yn][xn].tipo == Bau)){

                // chegou no baú sem chave, volta pra buscar as chaves 
                mapa->mapa[yn][xn].passo = 0;
            }

            // se for baú e tem a quantidade de chaves o suficiente
            else if((chavesObtidas == mapa->qntChaves) && (mapa->mapa[yn][xn].tipo == Bau)){

                // TODO: salvar todos os resultados

                // chegou no baú
                // verifica se o caminho obtido é o menor caminho encontrado
                if (verificaSeEhMenosCustoso(mapa, resultado, xn, yn)){

                    // salva o resultado de menor caminho
                    salvaResultado(mapa, resultado);
                    
                }
                // volta o passo, desmarca o caminho para procurar outros caminhos
                mapa->mapa[yn][xn].passo = 0;
            }
            else{

                // avança na matriz 
                RecursaoBT(mapa, resultado, xn, yn, v, h, passoAtual+1, chavesObtidas);
                
                // volta o passo, desmarca o caminho para procurar outros caminhos
                mapa->mapa[yn][xn].passo = 0; 
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

            // inicia todos os passos como 0 e vai preenchendo posteriormente
            resultado->mapa[i][j].passo = 0;
        }
    }

    // inicia o passo do baú com o máximo possível
    resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo = (mapa->coluna) * (mapa->linha)+1;

    return 0;
}

int verificaBT(int xn, int yn, TMapa* mapa){
    
    // verifica se está dentro do mapa
    if(xn>=0 && yn>=0 && (xn < mapa->coluna) && (yn < mapa->linha)){

        // verifica se é possível ir (caso de ser parede e caso de ser caminho já andado)
        if ((mapa->mapa[yn][xn].tipo != Parede ) && (mapa->mapa[yn][xn].passo == 0)){
            return 1;
        }
    }
    
    return 0;
}

int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn){

    // compara o passo que chegou no baú com o passo que está na localização do baú do resultado
    if((mapa->mapa[yn][xn].passo) <= (resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo)){
        
        return 1;
    }

    return 0;
}

int mostraTempoReal(TMapa* mapa){

    system("sleep 0.1");
    mostraResultadoGrafico(mapa);
    fflush(stdout);

    return 0;
}

