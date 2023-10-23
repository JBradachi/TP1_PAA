#include <string.h>
#include "./headers/TadBT.h"

void pausar(){
    printf(NONE "\n\nPressione ENTER para continuar... ");
    
    // Aguarda até que o usuário pressione Enter
    getchar();
    getchar();
}

int main(){
    TMapa m1, resultado;
    int opcao, isLido, isExec;
    char mostrarPossibilidades, mostraTempReal;
    char path[100] = "./entradas/";
    char arquivo[30] = "teste copy.txt";
    TRecursoes recursao;
    
    while (1)
    {
        clear();
        printf(NONE "\nEscolha uma das opcoes abaixo: \n 1 - Entrar com arquivo \n 2 - Mostrar matriz\n 3 - Calcular caminho\n 4 - Retornar analise de recursao \n 5 - Sair\n>>> ");
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
                strcpy(path, "./entradas/");
                break;
            case 2:
                if(isLido) mostraMatriz(&m1);
                else printf(RED "\nERRO!!! Nenhum arquivo inserido\n");
                break;
            case 3: 
                if(isLido){
                    printf("\nDeseja mostrar todas as possiveis possibilidades de caminho? [S/N] \n >>> ");
                    scanf(" %c%*[^\n]",&mostrarPossibilidades);
                    printf("\nDeseja mostrar em tempo real? [S/N] \n >>> ");
                    scanf(" %c%*[^\n]",&mostraTempReal);
                    printf("\n");
                    isExec = IniciaBT(&m1, &resultado, mostrarPossibilidades, mostraTempReal, &recursao);
                    
                }  
                else printf(RED "\nERRO!!! Nenhum arquivo inserido\n");
                break;
            case 4:
                if(isLido && isExec){
                    RetornaAnaliseRecursao(recursao);
                }
                else printf(RED "\nERRO!!! Nenhum arquivo inserido/executado\n");
                break;
            case 5:
                exit(0);
            default:
                printf(RED "\nERRO!! Opcao inexistente\n");
                break;
        }
       pausar();
    }

    return 0;
}