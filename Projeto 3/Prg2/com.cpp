#include "com.h"
#include <string>
#include <iostream>
#include "analisador.h"
#include <prglib.h>

using namespace std;
using namespace prglib;

com::com() {
}

com::com(string pacote) {
    
    string strhorario = pacote.substr(0, pacote.find(" "));
    horario = stod(strhorario.substr(0,strhorario.find(":")))*3600;
    strhorario.erase(0, strhorario.find(":")+1);
    horario = horario + stod(strhorario.substr(0,strhorario.find(":")))*60;
    strhorario.erase(0, strhorario.find(":")+1);
    horario = horario + stod(strhorario);
    
    pacote.erase(0, pacote.find(" ")+1);
    protocolo = pacote.substr(0, pacote.find(" "));
    
    pacote.erase(0, pacote.find(" ")+1);
   
    string origem = pacote.substr(0, pacote.find(" "));
    pacote.erase(0, pacote.find(" ")+1);
   
    end_origem = origem.substr(0, origem.find_last_of("."));
    origem.erase(0, origem.find_last_of(".")+1);
       
    port_origem = origem;
       
    pacote.erase(0,pacote.find(" ")+1);
   
    string destino = pacote.substr(0, pacote.find(":"));
   
    end_destino = destino.substr(0, destino.find_last_of("."));
    destino.erase(0, destino.find_last_of(".")+1);

    port_destino = destino;
   
    int pos1 = pacote.find("[");
    int pos2 = pacote.find("]");
   
    flag = pacote.substr(pacote.find("["), pos2-pos1+1);
   
    pacote.erase(0, pacote.find("length"));

    pos1 = pacote.find(" ");
    pos2 = pacote.find(":");
   
    comprimento = stoi(pacote.substr(pacote.find(" "), pos2 - pos1 +1));
    comunic = end_origem +">" + end_destino;
}

com::~com() {
}

