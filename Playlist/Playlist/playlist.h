#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
#include "Diretorio.h"
#include <prglib.h>
#include "manipula.h" 

using namespace std;
using namespace prglib;

class playlist {
public:
    lista<manipula> play;
    
    playlist(string cam);
    
    virtual ~playlist();
    
    int escreve(string txt); //método que escreve a playlist no formato M3U
    
    void por_artista(int par); //
                        // 
    void por_genero(int par);  //
                        //
    void por_album(int par);   //
                        //  Métodos que ordenam a lista de acordo com seu nome
    void por_titulo(int par);  //
                        //
    void por_ano(int par);     //
                        //
    void por_trilha(int par);  //
                        //
    void por_tamanho(int par); //
                        //
    void aleatorio();   //
    
    lista<manipula> show(); // método que mostra a lista de reprodução em tela;
        
    
private:
    manipula aux;   //objeto da classe manipula auxiliar que será usado na iteração da lista no método escreva
    
    
};

#endif /* PLAYLIST_H */

