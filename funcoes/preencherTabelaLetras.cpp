#include <iostream>

char preencherTabelaLetras(){ //gera letras aleatorias

    int num;
    char letra;

    for (int i=0; i< 26; i++){   
        num = rand() % 26; 
        letra = 'A' + num;      
    }
    return letra;
}