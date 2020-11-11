#include "analisador.h"
#include <string>
#include <iostream>
#include <com.h>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

analisador::analisador(string arquivo): tab(1300) {
    
    //thash<com> tab(20000);  
    ifstream arq(arquivo);
    
    if(not arq.is_open()){ //testa a abertura do pacote
        throw -1;
    }
    int i =0;
    string pacote;
    while(getline(arq, pacote)){
        com odilson(pacote);    //invoca o construtor da classe com.h para o objeto odilson 
        
        //cout << "Horario: " << odilson.horario << endl;
        //cout << "Protocolo: " << odilson.protocolo << endl;
        //cout << "Endereço de Origem: " << odilson.end_origem << endl;
        //cout << "Porta de Origem: " << odilson.port_origem << endl;
        
       // cout << "Endereço de destino: " << odilson.end_destino << endl;
       // cout << "Porta de destino: " << odilson.port_destino << endl;
        
        //cout << "Tag: " << odilson.flag << endl;
        //cout << "Tamanho: " << odilson.comprimento << endl << endl;
        
        if (i == 0) {
            tab.adiciona(odilson.comunic, odilson);
            i = i + 1;
        } 
        else { 
            //string ori = odilson.end_origem;
            //string dest = odilson.end_destino;
            //string com = dest + ">" + ori;
            
            if (tab.existe(odilson.comunic)) {
                if (odilson.flag != "[S]" and odilson.flag != "[F]" and odilson.flag != "[F.]") {
                  tab[odilson.comunic].pacote++;
                  tab[odilson.comunic].comprimento += odilson.comprimento;
                } else {//caso seja inicio ou fim de com
                    tab[odilson.comunic].horario = odilson.horario;
                }
            } else {
                tab.adiciona(odilson.comunic, odilson);
                }
            }
        }
}



analisador::~analisador() {
}


lista<string> analisador:: show(){
    
    lista<string> retorno;
    
    auto key = tab.chaves();
    
    key->inicia();
    
    while(not key->fim()){
        
        string aux = key->proximo();
        string aux2 = aux.substr(0,aux.find(">"));
        aux.erase(0,aux.find(">")+1);
        string procura = aux2 + ">" + aux;
        int hor = tab.obtem(aux).horario;
        if (tab.existe(procura)) {
            int dt = tab.obtem(procura).horario - hor; 
            retorno.anexa(aux + " " + "length= " + to_string(tab.obtem(aux).comprimento) + ", pkts= " + to_string(tab.obtem(aux).pacote) + ", dt= " + to_string(dt));
        }
    }
    return retorno;
}

string analisador:: whatever(){
    return "hahah";
}