#ifndef SWORDFISH_H
#define	SWORDFISH_H

#include "swordfish.h"
#include <prglib.h>
#include <string>
#include <iostream>

using namespace std;
using namespace prglib;


class swordfish {
public:
    swordfish();
    swordfish(string entrada);
    bool teste_original(string entrada);
    virtual ~swordfish();
private:
    arvore<string> * a;
    string original;
    string aux;
    string invertida;
};

#endif	/* SWORDFISH_H */

