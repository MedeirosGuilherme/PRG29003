#include "a_senha.h"
#include <string>
#include <iostream>

using namespace std;

a_senha::a_senha() {
}

a_senha::a_senha(string l){
    entrada = l;
}

string a_senha::original(){
    return entrada;
}

string a_senha::invertida(){
    string invertida;
    aux = entrada;
    while(aux.size() >0){
        invertida += aux.back();
        aux.pop_back();            
    }
    
    return invertida;    
}

string a_senha::substituidos(){
    
    
    while(entrada.find("3") != string::npos){
        entrada.replace(entrada.find("3"), 1, "e");
    }
    
    while(entrada.find("0") != string::npos){
        entrada.replace(entrada.find("0"), 1, "o");
    }
    
    while(entrada.find("4") != string::npos){
        entrada.replace(entrada.find("4"), 1, "a");
    }
    
    while(entrada.find("5") != string::npos){
        entrada.replace(entrada.find("5"), 1, "s");
    }
    
    while(entrada.find("1") != string::npos){
        entrada.replace(entrada.find("1"), 1, "l");
    }
    
    return entrada;
}

string a_senha::reduzidas(){
    string reduz = entrada;
//    while(reduz.find(".") != string::npos){
//        reduz.erase(reduz.find("."),1);
//    }
    
    int i = 0;
    while(i<entrada.size()){
        char c = entrada[i];
        if(c < 65 or c > 122 or c == '[' or c ==']'){
            entrada.erase(i, 1);
            i=0;
        }
        i++;        
    }
            
    
    
    return entrada;
}

a_senha::~a_senha() {
    
}

