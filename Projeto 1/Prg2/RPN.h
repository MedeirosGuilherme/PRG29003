#ifndef RPN_H
#define RPN_H

#include "prglib.h"
#include <iostream>
#include <string>


using namespace std;
using namespace prglib;

class RPN {
public:
    RPN();
    
    virtual ~RPN();
    
    string show();
    
    string lshow();
    
    void limpa();
    
    int trunca();
    
    string soma();
    
    string subtrai();
    
    string multiplica();
    
    string divide();
    
    string armazena(double n);
    
    string tamanho();

private:
    pilha<double> p;//instanciando a pilha usada como atributo da classe RPN
    
};

#endif /* RPN_H */

