#ifndef COM_H
#define COM_H

#include <string>
#include <iostream>
#include "analisador.h"
#include <prglib.h>

using namespace std;
using namespace prglib;

class com {
public:
    com();
    com(string pacote);
    virtual ~com();
    
    int pacote = 2;
    int horario;
    string protocolo;
    string end_origem;
    string port_origem;
    string end_destino;
    string port_destino;
    string flag;
    int comprimento;    
    string comunic;
    int quantidade;
    int tempo;
    
    
private:

};

#endif /* COM_H */

