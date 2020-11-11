#ifndef MANIPULA_H
#define MANIPULA_H

#include <iostream>
#include <string>
#include <prglib.h>
#include "Diretorio.h"
#include <tag.h>

class manipula {
public:
    
   string artista;
   string genero;
   string album;
   string titulo;
   int ano;                             // parametros que recebem as tags da música pela taglib
   int trilha;
   int tamanho;
   string arquivo;
   int parametro; // PARAMETRO DE ORGANIZAÇÃO DA PLAYLIST
   bool operator<(const manipula & outro);  //operador < para objetos da classe manipula
   
   manipula();
       
   manipula(string caminho);
   
   virtual ~manipula();
   
private:
    

};

#endif /* MANIPULA_H */

