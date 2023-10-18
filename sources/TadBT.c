#include "../headers/TadBT.h"


int IniciaBT(TMapa* mapa, TMapa* resultado, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes){

    int movimentoX[4] = {0, 1, 0, -1}, movimentoY[4] = {1, 0, -1, 0};
    int quantCaminhos = 0; 
    recursoes->profundidadeMax = 0;
    recursoes->totalDeRecursoes = 0;
    // com essa configutação indiana bones anda: direita -> baixo -> esquerda -> cima.
    
    // ponto de início já começa como 1
    mapa->mapa[0][0].passo = 1; 

    // prepara a variável que irá guardar o resultado
    inicializaResultado(mapa, resultado);

    // inicia a recursão do primeiro ponto
    RecursaoBT(mapa, resultado, 0, 0, movimentoX, movimentoY, 1, 0, &quantCaminhos, mostrarPossibilidades, mostraTR, recursoes);
    
    // se possúi resultado (variável resultado foi alterada), mostra o resultado
    if (resultado->mapa[0][0].passo != 0){
        printf("\n");
        printf("\nMatriz resultado: \n");
        mostraResultadoGrafico(resultado);
        printf("\nVetor resultado: \n");
        mostraVetorResultado(resultado, 0, 0, 1);
        printf("\nForam encontrados %d caminho(s) diferente(s)\n", quantCaminhos);

    }
    else{
        printf("\n");
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }

    return 1;
}

int RecursaoBT(TMapa* mapa, TMapa* resultado, int posX, int posY, int movimentoX[4], int movimentoY[4], int passoAtual, int chavesObtidas, int* quantCaminhos, char mostrarPossibilidades, char mostraTR, TRecursoes* recursoes){
    int xn, yn, i=-1; // só pra i começar em 0 no while
    recursoes->totalDeRecursoes += 1;
    if(mapa->mapa[posX][posY].passo > recursoes->profundidadeMax){
        recursoes->profundidadeMax = mapa->mapa[posX][posY].passo;
    }
    // "i" é o indice referente a como indiana bones irá dar pelo labirinto
    // linhas 36, 37, 38 e 39 são as possíveis movimentações
    while(i<3){
        i++;
        xn = posX + movimentoX[i];
        yn = posY + movimentoY[i];

        // verifica se é possível ir para o lugar, se não for testa a próxima movimentação
        if(verificaCelula(xn, yn, mapa)){ 
            
            if(mostraTR == 'S'){
                printf("\n");
                mostraTempoReal(mapa);
                printf("\n");
            }
            
            
            
            // atualização dos passos
            // ultima passada no baú conta como passo
            mapa->mapa[xn][yn].passo = passoAtual+1; 
            
            // se for chave aumenta a quantidade de chaves obtidas
            if(mapa->mapa[xn][yn].tipo == Chave){
                    chavesObtidas++;
                }

            // se for baú e não tem a quantidade de chaves o suficiente
            if((chavesObtidas != mapa->qntChaves) && ehBau(mapa, xn, yn)){

                // chegou no baú sem chave, volta pra buscar as chaves 
                mapa->mapa[xn][yn].passo = 0;
            }

            // se for baú e tem a quantidade de chaves o suficiente
            else if((chavesObtidas == mapa->qntChaves) && ehBau(mapa, xn, yn)){

                // mostra todas as possibilidades de resultado
                if(mostrarPossibilidades == 'S'){
                    printf("Possivel possibilidade:\n");
                    mostraVetorResultado(mapa, 0, 0, 1);
                }

                // conta quantidade de caminhos existentes
                *quantCaminhos += 1;

                // verifica se o caminho obtido é o menor caminho encontrado
                if (verificaSeEhMenosCustoso(mapa, resultado, xn, yn)){


                    // salva o resultado de menor caminho
                    salvaResultado(mapa, resultado);
                    
                }
                // volta o passo, desmarca o caminho para procurar outros caminhos
                mapa->mapa[xn][yn].passo = 0;
            }

            // se não for baú avança até encontrar o baú
            else{

                // avança no mapa 
                RecursaoBT(mapa, resultado, xn, yn, movimentoX, movimentoY, passoAtual+1, chavesObtidas, quantCaminhos, mostrarPossibilidades, mostraTR, recursoes);
                
                // volta o passo, desmarca o caminho para procurar outros caminhos
                mapa->mapa[xn][yn].passo = 0; 
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

int verificaSeEhMenosCustoso(TMapa* mapa, TMapa* resultado,int xn,int yn){

    // compara o passo que chegou no baú com o passo que está na localização do baú do resultado
    if((mapa->mapa[xn][yn].passo) <= (resultado->mapa[mapa->locBau[0]][mapa->locBau[1]].passo)){
        
        return 1;
    }

    return 0;
}

int mostraTempoReal(TMapa* mapa){

    
    mostraResultadoGrafico(mapa);
    SLEEP_MS(100);
    // espaçamento entre matrizes
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fflush(stdout);

    return 0;
}

int mostraVetorResultado(TMapa *resultado, int X, int Y, int passo){
    if (ehBau(resultado, X, Y)){
        printf("[%d][%d]\n", X, Y);
        return 0;
    }
    printf("[%d][%d],", X,Y);
    if (celulaDentroDoMapa(X+1, Y, resultado) && resultado->mapa[X+1][Y].passo == passo+1) mostraVetorResultado(resultado, X+1, Y, passo+1);
    else if (celulaDentroDoMapa(X, Y+1, resultado) && resultado->mapa[X][Y+1].passo == passo+1) mostraVetorResultado(resultado, X, Y+1, passo+1);
    else if (celulaDentroDoMapa(X-1, Y, resultado) && resultado->mapa[X-1][Y].passo == passo+1) mostraVetorResultado(resultado, X-1, Y, passo+1);
    else if (celulaDentroDoMapa(X, Y-1, resultado) && resultado->mapa[X][Y-1].passo == passo+1) mostraVetorResultado(resultado, X, Y-1, passo+1);

}

void RetornaAnaliseRecursao(TRecursoes recursao){
    printf("\nProfundidade maxima da recursao: %d\nTotal de recursoes feitas: %d\n", recursao.profundidadeMax, recursao.totalDeRecursoes);
}