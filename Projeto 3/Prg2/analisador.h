#ifndef ANALISADOR_H
#define ANALISADOR_H

#include <string>
#include <iostream>
#include <com.h>
#include "prglib.h"

using namespace std;
using namespace prglib;

class analisador {
public:
    //analisador();
    analisador(string arquivo);
    virtual ~analisador();
    lista<string> show();
    string whatever();
    
private:
   thash<com> tab;  
};

#endif /* ANALISADOR_H */

