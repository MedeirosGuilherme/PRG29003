#include "analisador.h"
#include <string>
#include <iostream>
#include "com.h"
#include <prglib.h>

using namespace prglib;
using namespace std;

int main(int argc, char * argv[]) {
    
    string caminho;
    getline(cin, caminho);
    analisador wireshark(caminho);    
    //cout << "cuzao" << endl;
    lista<string> alishow;
    
    alishow = wireshark.show();
    alishow.inicia();
    
    while (not alishow.fim()) {
       // cout << "cuzao";
        cout << alishow.proximo() << endl;
    }
}
