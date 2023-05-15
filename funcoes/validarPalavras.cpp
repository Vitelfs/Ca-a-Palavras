#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

void validarPalavras(std::string palavras[][8],int numeroPalavras, int &jogadas, std::vector<std::string> &armazenarChute, int &restante,int decisao){ 
    
    //uso o vector para servir de container para as palavras digitadas pelo usuario
    std::string chute;
    bool certo = false,repetiu = false;
     
    std::cout << "\nAchou uma palavra?! Digite ela aqui para ver se esta certa:(palavras restantes: " << restante << "): ";
    std::cin >> chute;
    for(int i = 0;i < chute.size();i++){
        chute[i] = toupper(chute[i]);
    }

    for(int i = 0;i < numeroPalavras;i++){       
        if(chute == palavras[decisao][i]){
            if(find(armazenarChute.begin(),armazenarChute.end(),chute) != armazenarChute.end()){
                repetiu = true;
            }
            else{
                certo = true;
                armazenarChute.push_back(chute);
            }
        }
    }
    if(repetiu == true){
        std::cout << "voce ja digitou essa palavra\n";  
        repetiu = false;
        Sleep(1500);
    }
    else if(certo == true){
        std::cout << jogadas << "\n";
        std::cout << "\nParabens! Voce acertou a palavra: " << chute << '\n';
        jogadas--;
        restante--;
        certo = false;
        Sleep(1500);
    }
    else{
        std::cout << "\nInfelizmente nao temos essa palavra em nosso banco de dados\n";
        Sleep(1500);
    }
}