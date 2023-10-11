#include "./headers/TadBT.h"

int IniciaBT(Mapa* mapa){
    int v[4] = {1, 1, 0, 0}, h[4] = {0, 0, 1, 1}, q = 0;
    RecursaoBT(&mapa, 0, 0, q, v, h, 1, 0);
    if (q){
        // retorna resultado obtido
    }else{
        printf("Indiana Jones nao consegue abrir o bau :( ");
    }
}

int RecursaoBT(Mapa* mapa, int posX, int posY, int q, int v[4], int h[4], int passo, int chavesObtidas){
    int xn, yn, q1, i=-1;
    
    while(q1 || i<3){
        i++;
        q1 = 0;
        xn = posX + h[i];
        yn = posY + h[i];
        if(xn < mapa->coluna && yn < mapa->linha && mapa->mapa[xn][yn] != '1' /* && mapa->mapa[xn][yn] != de caminho já marcado*/){
            mapa->mapa[posX][posY] = "0"; // marcar caminho com passo >>> verificar amanhã
            if(mapa->mapa[xn][yn] == 'C'){
                chavesObtidas++;
            }
            else if((chavesObtidas == mapa->qntChaves) && (mapa->mapa[xn][yn] == 'X')){
                // chegou no baú
            }
            // caso de não haver solução >>> leitura pode guardar quantas casas é possível andar no máximo
            // if (passo < quantPassosTotal){
            RecursaoBT(&mapa, xn, yn, q1, v, h, passo+1, chavesObtidas);
            if(q1 == 0){
                mapa->mapa[posX][posY] = "0"; // volta o passo, desmarca o caminho
            }
            else{
                q1 = 1;
            }
            //}
            
        }    
    }
    q = q1;
}