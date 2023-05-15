#include <iostream>
#include <vector>
#include <windows.h>

void escreverTabela(std::string (&tabela)[][30],std::vector<std::string> armazenarChute){ //gera a tabela XD

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    std::cout << " --------------------------------------------------------------------------------------------\n";
    for(int i = 0;i < 30;i++){

        std::cout << "|  ";
        for(int j = 0;j < 30;j++){
            std::cout <<tabela[i][j] << "  ";
        }
        std::cout << "|\n";
    }  
    std::cout << " --------------------------------------------------------------------------------------------";
    std::cout << "\nPalavras acertadas: \033[31m";
        for(int i = 0;i < armazenarChute.size();i++){
            std::cout << armazenarChute[i] << " ";
        }
        std::cout << std::endl;
}
