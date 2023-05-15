#include <iostream>

void preencherTabelaPalavras(std::string (&tabela)[][30], std::string palavras[][8], int numeroPalavras,int decisao){

    int posicoesUsadas[30][30] = {0};  // matriz para manter registro das posições já ocupadas
    int linhaAleatoria, colunaAleatoria;
    bool repetiu;

    for(int i = 0; i < numeroPalavras; i++){
        
        linhaAleatoria = 0;
        colunaAleatoria = 0;
        
        // alterna entre palavras verticais e horizontais
        if(i % 2 == 0){       
            do{
                repetiu = false;
                linhaAleatoria = rand() % 30;
                colunaAleatoria = rand() % (30 - palavras[decisao][i].length()); // garante que a palavra não ultrapasse a borda direita do grid

                // verifica se a posição está livre
                for(int j = 0; j < palavras[decisao][i].length(); j++){
                    if(posicoesUsadas[linhaAleatoria][colunaAleatoria+j]){
                        repetiu = true;
                        break;
                    }
                }
                
            }while(repetiu);      
            
            // preenche a tabela com a palavra horizontal
            for(int j = 0; j < palavras[decisao][i].length(); j++){
                tabela[linhaAleatoria][colunaAleatoria+j] = palavras[decisao][i][j];
                posicoesUsadas[linhaAleatoria][colunaAleatoria+j] = 1;
            }   
        }
        else{
            do{
                repetiu = false;
                linhaAleatoria = rand() % (30 - palavras[decisao][i].length()); // garante que a palavra não ultrapasse a borda inferior do grid
                colunaAleatoria = rand() % 30;

                // verifica se a posição está livre
                for(int j = 0; j < palavras[decisao][i].length(); j++){
                    if(posicoesUsadas[linhaAleatoria+j][colunaAleatoria]){
                        repetiu = true;
                        break;
                    }
                }
                
            }while(repetiu);      
            
            // preenche a tabela com a palavra vertical
            for(int j = 0; j < palavras[decisao][i].length(); j++){
                tabela[linhaAleatoria+j][colunaAleatoria] = palavras[decisao][i][j];
                posicoesUsadas[linhaAleatoria+j][colunaAleatoria] = 1;
            }   
        }
    }
}