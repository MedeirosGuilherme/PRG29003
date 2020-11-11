#include <iostream>
#include <prglib.h>
#include "RPN.h"

using namespace prglib;
using namespace std;

int main(int argc, char * argv[]) {
    
    string gets;
    string op; //string para entrada de dados;
    RPN calc; //objeto calc da classe RPN que representa a calculadora polonesa RPN
        
    cout << "**Calculadora RPN**";
    cout << endl << endl << endl;
    while(true){ //laço para o funcionamento do programa
        
        
        
        cout << "" << endl;
        cout << "> ";
        cin >> op;
        
        if(op == "H"){ // tela de ajuda
            cout << endl;
            cout << "** Ajuda para comandos da calculadora RPN **" << endl;
            cout << "Digite dois números e depois a operação que deseja realizar (n1 n2 *); (n1 n2 /); (n1 n2 -); (n1 n2 +)" << endl;
            cout << "Digite ! para mostrar o ultimo número ou ultima operação realizada" << endl;
            cout << "Digite ? para mostrar todos os números da memória" << endl;
            cout << "Digite p para trocar o ultimo número n pelo maior número primo menor que n" << endl;
            cout << "Digite z para limpar a memória da calculadora" << endl;
            cout << "Digite # para mostrar quantos números há na memória" << endl;
            cout << "Digite end para desligar a calculadora" << endl << endl;
        }   
        
        else if(op == "!"){ // caraceter ! que chama o método .show, que mostra o ultimo caractere da memória da calculadora
            cout << calc.show();
            cout << endl;
        }
        
        else if(op == "end"){ //entrada end que sai do programa e finaliza tudo.
            cout << "bye ;)";
            break;
        }
        
        else if(op == "?"){ //entrada ? que chama o método .lshow, que mostra todos os números da memória da calculadora
            cout << calc.lshow();
            cout << endl;
        }
        
        else if(op == "z"){ //entrada z que chama o método .limpa limpa a memória da calculadora
            calc.limpa();
        }
        
        else if(op == "p"){ // entrada p que chama o método .trunca que encontra o maior número primo menor que o ultimo número armazenado na memória e o armazena
            calc.trunca();
        }
            
        else if(op == "+"){ // entrada + que chama o método .soma e realiza uma soma entre os dois ultimos números da memória
            cout << calc.soma();
        }
           
        else if(op == "-"){ // entrada - que chama o método .subtrai e realiza uma subtração entre os dois ultimos números da memória
            cout << calc.subtrai();
        }
            
        else if(op == "/"){ //entrada / que chama o método .divide e realiza uma divisão entre os dois ultimos números da memória
            cout << calc.divide();
        }
        
        else if(op == "*"){ // entrada * que chama o método .multiplica e realiza uma multiplicação entre os dois ultimos números da memória.
            cout << calc.multiplica();
        }
        
        else if(op == "#"){
            cout << calc.tamanho();
        }
        
        else{  //entrada numérica que armazena números na memória da calculadora
               try{
                   calc.armazena(stod(op));}
               catch(...){
                   cout << "Caractere inválido. Pressione H para ajuda" << endl;
               }
        }
    }
    return 0;
}
