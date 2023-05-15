#include <iostream>
#include <vector>
#include "funcoes/criarTabela.cpp"
#include "funcoes/escreverTabela.cpp"
#include "funcoes/preencherTabelaPalavras.cpp"
#include "funcoes/validarPalavras.cpp"

int main(){

    srand(time(NULL)); //iniciar o gerador aleatorio

    std::string palavras[][8] = {{"GATO","CACHORRO","TIGRE","RATO","PATO","TARTARUGA","MACACO","URSO"},
                                 {"PROFESSOR","ALUNO","CANETA","CADERNO","LIVRO","ESQUADRO","GIZ","APONTADOR"},
                                 {"COMPUTADOR","CELULAR","TABLET","NOTEBOOK","PROCESSADOR","MONITOR","TECLADO","MOUSE"}}; // palavras que serao usadas
    std::string tabela[30][30]; // tabela 30x30
    std::string validar_decisao;
    int decisao;
    bool decisao_valida = false;
    int numeroPalavras = sizeof(palavras[0])/sizeof(palavras[0][0]); //automatizar o numero de palavras
    int jogadas = numeroPalavras; // numero de jogadas
    int restante = numeroPalavras; // palavras restantes na validacao palavras

    std::vector <std::string> armazenarChute; // um container para armazenar todos os chutes certeiros do jogador
    
    std::cout << "Qual tema voce quer? 0-Animais; 1-Escola; 2-Tecnologia" << std::endl;
    do{
        std::getline(std::cin >> std::ws,validar_decisao);
        try{
            decisao = std::stoi(validar_decisao);
            decisao_valida = true;
        }catch(const std::exception& e){
            std::cout << "Input invalido, digite denovo:" << std::endl;
        }
        if(decisao < 0 || decisao > 2){
            std::cout << "Input invalido, digite denovo:" << std::endl;
        }
    }while(!decisao_valida || decisao < 0 || decisao > 2);

    criarTabela(tabela);
    preencherTabelaPalavras(tabela,palavras,numeroPalavras,decisao);

    while(jogadas > 0){ //loop ate o jogador acertar todas as palavras
    escreverTabela(tabela,armazenarChute);
    validarPalavras(palavras,numeroPalavras,jogadas,armazenarChute,restante,decisao);
    system("cls");
    }
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0); //voltar a cor original
    system("pause");

    return 0;
}





