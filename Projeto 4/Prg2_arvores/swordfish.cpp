#include "swordfish.h"
#include <prglib.h>
#include <string>
#include <iostream>

using namespace std;
using namespace prglib;

swordfish::swordfish() {
}

swordfish::swordfish(string entrada) :a = new arvore<string>("a") {
    
    a->adiciona("computador");
    a->adiciona("cadeira");
    a->adiciona("dicionário");
    a->adiciona("projeto");
    a->adiciona("sobral");
}

bool swordfish::teste_original(string original){
    
    try{
        if(a->obtem(original) == original){
            return true;
        }
    } catch(...){
        return false;
    }
}

swordfish::~swordfish() {
}

