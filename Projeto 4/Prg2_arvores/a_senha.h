#ifndef A_SENHA_H
#define	A_SENHA_H

#include "a_senha.h"
#include <string>
#include <iostream>
#include <prglib.h>

using namespace std;
using namespace prglib;

class a_senha {
public:
    
    a_senha();
    a_senha(string l);
    string original();
    string invertida();
    string substituidos();
    string reduzidas();
    virtual ~a_senha();
    
private:
    string entrada;
    string aux;
    
    
    
};

#endif	/* A_SENHA_H */

