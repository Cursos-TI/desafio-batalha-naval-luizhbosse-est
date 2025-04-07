#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10];
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int posicaoNavioHorizontal[3] = {2,3,4};
    int posicaoNavioVertical[3] = {7,8,9};

    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            tabuleiro[i][j] = 0;
        }         
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    for (int h = 0; h < 3; h++)
    {    
        tabuleiro[1][posicaoNavioHorizontal[h]-1] = 3;   
    }

    for (int v = 0; v < 3; v++)
    {    
        tabuleiro[posicaoNavioVertical[v]-1][2] = 3;
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    int posicaoNavioDiagonalPrincipal[3] = {7,8,9}; // Linha e coluna igual, o vetor indica linha e coluna
    int posicaoNavioDiagonalSecundaria[3] = {1,2,3}; // Soma de linha e coluna = tamanho do tabuleiro, o vetor indica a linha
    
    for (int dp = 0; dp < 3; dp++)
    {    
        tabuleiro[posicaoNavioDiagonalPrincipal[dp]-1][posicaoNavioDiagonalPrincipal[dp]-1] = 3;        
    }

    int posicaoColuna = 0;
    for (int ds = 0; ds < 3; ds++)
    {    
        posicaoColuna = 10 - posicaoNavioDiagonalSecundaria[ds];
        tabuleiro[posicaoNavioDiagonalSecundaria[ds]-1][posicaoColuna] = 3;        
    }

    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    /*
    printf("Tabuleiro batalha naval...\n");
    printf("    ");
    for (int c = 0; c < 10; c++)
    {    
        printf("%c ",coluna[c]);    
    }
    printf("\n");

    for(int i = 0; i<10; i++){
        i==9 ? printf("%d ", i+1): printf("%d  ", i+1);
        for(int j = 0; j<10; j++){
            printf(" %d",tabuleiro[i][j]);
        } 
        printf("\n");
    }
*/
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    int habilidadeCone[3][5];
    int habilidadeCruz[3][5];
    int habilidadeOctaedro[3][5];

    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            if(j >= 2 - i && j <= 2 + i){
                habilidadeCone[i][j] = 1;
            }else{
                habilidadeCone[i][j] = 0;
            }
        }  
    }

    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            if(i == 1 || j == 2){
                habilidadeCruz[i][j] = 1;
            }else{
                habilidadeCruz[i][j] = 0;
            }
            
        }  
    }

    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            if((i == 1 || j == 2) && j < 4 && j > 0){
                habilidadeOctaedro[i][j] = 1;
            }else{
                habilidadeOctaedro[i][j] = 0;
            }           
        }  
    }

    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    printf("\nHabilidade de Cone..\n");
    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            printf("%d ", habilidadeCone[i][j]);
        } 
        printf("\n"); 
    }

    printf("\nHabilidade de Cruz..\n");
    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            printf("%d ", habilidadeCruz[i][j]);
        } 
        printf("\n"); 
    }

    printf("\nHabilidade de Octaegro..\n");
    for (int i = 0; i < 3; i++)
    {    
        for (int j = 0; j < 5; j++){
            printf("%d ", habilidadeOctaedro[i][j]);
        } 
        printf("\n"); 
    }
    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Exibir tabuleiro para o usuário com um monte de 2
    int tabuleiroJogador[10][10];

    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            tabuleiroJogador[i][j] = 2;
        }         
    }

    int qtdVidas = 10;
    int acertouTiro = 0;
    int qtdNavioEncontrado = 0;

    do{

        printf("\n\nTabuleiro batalha naval...\n");
        printf("    ");
        for (int c = 0; c < 10; c++)
        {    
            printf("%c ",coluna[c]);    
        }
        printf("\n");
    
        for(int i = 0; i<10; i++){
            i==9 ? printf("%d ", i+1): printf("%d  ", i+1);
            for(int j = 0; j<10; j++){
                printf(" %d",tabuleiroJogador[i][j]);
            } 
            printf("\n");
        }
    
        printf("\n");
        printf("\n");
    
        printf("Quantidade de vidas atual: %d\n", qtdVidas);

        // Solicitar para o usuário qual habilidade ele quer usar
        int habilidadeSelecionada;
        int linhaSelecionada;
        char colunaSelecionada;
        int colunaSelecionadaInt;

        printf("\n");
        printf("Indique qual habilidade deseja utilizar:\n");
        printf("1: Habilidade em Cone\n");
        printf("2: Habilidade em Cruz\n");
        printf("3: Habilidade em Octaedro\n");
        scanf("%d", &habilidadeSelecionada);
        if (habilidadeSelecionada < 1 || habilidadeSelecionada > 3){
            printf("Habilidade inválida, tente novamente...\n");
            //continue;
        }

        // Solicitar para o usuário a linha
        printf("Indique em qual linha irá utilizar a habilidade:\n");
        scanf("%d", &linhaSelecionada);
        if (linhaSelecionada < 1 || linhaSelecionada > 10){
            printf("Linha inválida, tente novamente...\n");
            //continue;
        }

        // Solicitar para o usuário a coluna
        printf("Indique em qual coluna irá utilizar a habilidade:\n");
        scanf(" %c", &colunaSelecionada);
        colunaSelecionadaInt = 0;
        switch (colunaSelecionada)
        {
            case 'A':
                colunaSelecionadaInt = 1;
                break;
            case 'B':
                colunaSelecionadaInt = 2;
                break;
            case 'C':
                colunaSelecionadaInt = 3;
                break;
            case 'D':
                colunaSelecionadaInt = 4;
                break;
            case 'E':
                colunaSelecionadaInt = 5;
                break;
            case 'F':
                colunaSelecionadaInt = 6;
                break;
            case 'G':
                colunaSelecionadaInt = 7;
                break;
            case 'H':
                colunaSelecionadaInt = 8;
                break;
            case 'I':
                colunaSelecionadaInt = 9;
                break;
            case 'J':
                colunaSelecionadaInt = 10;
                break;
        
        default:
        printf("Coluna inválida, tente novamente...\n");
            break;
        }

        // Decrementa 1 para não precisar ficar fazendo sempre -1 nos indexadores
        colunaSelecionadaInt--;
        linhaSelecionada--;

        // Preencher no tabuleiro de 8 do usuário, os valores do tabuleiro, 0 quando agua, 3 quando navio, 8 quando não descoberto
        for (int i=0; i < 10; i++)
        {
            for (int j=0; j < 10; j++){
                // Verifica se a posição deve está dentro da matriz 3x5 de habilidade
                if (i>=linhaSelecionada && i<=linhaSelecionada+2 && j >= colunaSelecionadaInt && j <= colunaSelecionadaInt +4){ 
                    
                    // Fazer IF, de acordo com o tipo de habilidade selecionada, para não verificar toda a matriz 3x5
                    switch (habilidadeSelecionada)
                    {
                        case 1: // Cone
                            if (habilidadeCone[i-linhaSelecionada][j-colunaSelecionadaInt] == 1){
                                tabuleiroJogador[i][j] = tabuleiro[i][j];
                                if(tabuleiro[i][j] == 3){
                                    acertouTiro = 1;
                                    qtdNavioEncontrado++;
                                }
                            }
                            break;
                        case 2: // Cruz
                            if (habilidadeCruz[i-linhaSelecionada][j-colunaSelecionadaInt] == 1){
                                tabuleiroJogador[i][j] = tabuleiro[i][j];
                                if(tabuleiro[i][j] == 3){
                                    acertouTiro = 1;
                                    qtdNavioEncontrado++;
                                }
                            }                            
                            break;
                        case 3: // Octaedro
                            if (habilidadeOctaedro[i-linhaSelecionada][j-colunaSelecionadaInt] == 1){
                                tabuleiroJogador[i][j] = tabuleiro[i][j];
                                if(tabuleiro[i][j] == 3){
                                    acertouTiro = 1;
                                    qtdNavioEncontrado++;
                                }
                            }
                            break;
                    
                    default:
                        break;
                    }               

   

                }
            }
        }

        if (acertouTiro == 0){
            qtdVidas--;
        }
        acertouTiro = 0;

        if (qtdNavioEncontrado == 12){
            break;
        }
    
    } while(qtdVidas > 0);

    printf("Jogo encerrado..\n");

    if (qtdVidas == 0){
        printf("Você perdeu... Tente novamente...\n");  
    }

    if (qtdNavioEncontrado == 12){
        printf("Parabéns... Você venceu\n");  
    }

    return 0;
}