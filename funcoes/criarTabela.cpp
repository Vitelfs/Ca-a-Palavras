#include <iostream>
#include "preencherTabelaLetras.cpp"

void criarTabela(std::string (*tabela)[30]){ // preenche a tebela com letras aleatorias
    for(int i = 0;i < 30;i++){
        for(int j = 0;j < 30;j++){
            tabela[i][j] = preencherTabelaLetras();      
        }
    }  
}
