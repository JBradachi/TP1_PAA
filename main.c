#include <string.h>
#include "./headers/TadBT.h"

void pausar(){
    printf("\n\nPressione ENTER para continuar... ");
    
    // Aguarda até que o usuário pressione Enter
    getchar();
    getchar();
}

int main(){
    TMapa m1, resultado;
    int opcao, isLido;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste copy.txt";
    
    while (1)
    {
        clear();
        printf(NONE "\nEscolha uma das opções abaixo: \n 1 - Entrar com arquivo \n 2 - Mostrar matriz\n 3 - Calcular caminho \n 4 - Sair\n>>> ");
        // ignorar o \n na leitura da entrada
        scanf(" %d%*[^\n]",&opcao);
        switch (opcao)
        {
            case 1:
                printf("\nDigite o nome do arquivo [sem .txt]: ");
                scanf("%s", arquivo);

                strcat(path, arquivo);
                strcat(path, ".txt");
                isLido  = manipulaArquivo(path, &m1);
                break;
            case 2:
                if(isLido) mostraMatriz(&m1);
                else printf(RED "\nERRO!!! Nenhum arquivo inserido\n");
                break;
            case 3: 
                if(isLido)  IniciaBT(&m1, &resultado);
                else printf(RED "\nERRO!!! Nenhum arquivo inserido\n");
                break;
            case 4:
                exit(0);
            default:
                printf(RED "\nERRO!! Opcao inexistente\n");
                break;
        }
       pausar();
    }

    return 0;
}