#include <iostream>
#include <cstdlib>
#include <prglib.h>
#include <string> 
#include "swordfish.h"
#include "a_senha.h"

using namespace prglib;
using namespace std;

int main() {
    string entrada;
    swordfish knowles;
    
    while(true){
        cin >> entrada;
        a_senha password(entrada);
        
        knowles.teste_original(password.original());
    }
        
        return 0;
}    

