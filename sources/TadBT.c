#include "../headers/TadBT.h"

int IniciaBT(TMapa* mapa){
    int v[4] = {0, -1, 0, 1}, h[4] = {1, 0, -1, 0}, q = 0; // com essa configutação indiana bones anda -> direita -> baixo -> esquerda -> cima.
    mapa->mapa[0][0].passo = 1; // ponto de início
    RecursaoBT(mapa, 0, 0, q, v, h, 1, 0);
    if (q){
        // retorna resultado obtido
    }else{
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }
}

int RecursaoBT(TMapa* mapa, int posX, int posY, int q, int v[4], int h[4], int passo, int chavesObtidas){
    int xn, yn, q1, i=-1; // só pra i começar em 0 no while
    
    while(q1 || i<3){
        i++;
        q1 = 0;
        xn = posX + h[i];
        yn = posY + v[i];
        if((xn < mapa->coluna) && (yn < mapa->linha) && (mapa->mapa[xn][yn].tipo != '1') && (mapa->mapa[xn][yn].passo == 0)){ // != "1" testa se é diferente de parede
            // caso de não houver solução >>> andar 
            //if (passo < quantPassosTotal){
                if((chavesObtidas != mapa->qntChaves) && (mapa->mapa[xn][yn].tipo == 'X')){
                    // chegou no baú sem chave, volta pra buscar as chaves 
                    q1 = 0; // analizar pra q serve q1
                    return 0;
                }
                else if((chavesObtidas == mapa->qntChaves) && (mapa->mapa[xn][yn].tipo == 'X')){
                    // chegou no baú
                    q1 = 1; // analizar pra q serve q1
                    // salva a matriz
                }

                mapa->mapa[xn][yn].passo = passo+1; // ultima passada no baú conta como passo?
                
                if(mapa->mapa[xn][yn].tipo == 'C'){
                    chavesObtidas++;
                }
                
                

                RecursaoBT(mapa, xn, yn, q1, v, h, passo+1, chavesObtidas);
                if(q1 == 0){
                    mapa->mapa[xn][yn].passo = 0; // volta o passo, desmarca o caminho
                    if(mapa->mapa[xn][yn].tipo == 'C'){
                        chavesObtidas--;
                    }
                }
                else{
                    q1 = 1;
                }
            //}
            
        }    
    }
    q = q1;
}


// !! =========================================================== RECURSAO ============================================

int RecursaoBackTracking(TMapa * mapa, TMapa * resultado){
    int voltaApagando = 0, passo, ChavesObtidas = 0;
    corpoRecursao(mapa, resultado, 0, 0, &voltaApagando, 1, &ChavesObtidas);
}

int corpoRecursao(TMapa * mapa, TMapa * resultado, int X, int Y, int *voltaApagando, int passo, int *ChavesObtidas){
    printf ("Estou no passo %d\nTotal de chaves: %d\nVolta apagando: %d\n", passo, *ChavesObtidas, *voltaApagando);
    printf ("\n");
    //Condicoes de parada
    if (!verificaCelula(mapa, X, Y)){ //a celula esta fora do escopo da matriz
        printf("celula nao existe\n");
        *voltaApagando = 1;
        return 0;
    }
    if (ehParede(mapa, X, Y)){
        printf("eh parede\n");
        *voltaApagando = 1;
        return 0;
    }
    else if (mapa->mapa[X][Y].passo != 0){ // o passo é diferente de zero e nao se trata da celula inicial
        printf("ja passou por aqui\n");
        *voltaApagando = 1;
        return 0;
    }

    // verificaçoes 
    if (ehChave(mapa, X, Y)){
        printf("eh chave\n");
        *ChavesObtidas += 1;
        mapa->mapa[X][Y].passo = passo;
        *voltaApagando = 0;
    }

    else if (ehBau(mapa, X, Y) && *(ChavesObtidas) != mapa->qntChaves){
        printf("Numero de chaves erradas\n");
        mostraMatrizPassos(mapa);
        *voltaApagando = 1;
        return 0;
    }
    
    else if (ehBau(mapa, X, Y) && *(ChavesObtidas) == mapa->qntChaves){

        printf("===========UMA POSSIVEL RESPOSTA==============\n");
        mapa->mapa[X][Y].passo = passo;
        // ! =====================
        // ! TODO: guardar resultado
        mostraMatrizPassos(mapa);

        //estou saindo para nao executar tudo, mas se deixar, ele ira procurar todas
        exit(0);
        *voltaApagando = 1;
    }
    mapa->mapa[X][Y].passo = passo;

    //Recursao (direita, baixo, esquerda, cima)
    corpoRecursao(mapa, resultado, X, Y+1, voltaApagando, passo + 1, ChavesObtidas);
    corpoRecursao(mapa, resultado, X+1, Y, voltaApagando, passo + 1, ChavesObtidas);
    corpoRecursao(mapa, resultado, X, Y-1, voltaApagando, passo + 1, ChavesObtidas);
    corpoRecursao(mapa, resultado, X-1, Y, voltaApagando, passo + 1, ChavesObtidas);
    
    mostraMatrizPassos(mapa);

    //caso dê erro, procedimento que volta apagando
    if (voltaApagando){
        printf("apagou\n");
        if (ehChave(mapa, X, Y)){
            *ChavesObtidas -= 1;
        }
        mapa->mapa[X][Y].passo = 0;
        return 0;
    }
}
