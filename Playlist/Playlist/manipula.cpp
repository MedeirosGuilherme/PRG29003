#include <string>
#include "manipula.h"
#include <tag.h>
#include <iostream>
#include <fileref.h>

using namespace std;
using namespace TagLib;


manipula::manipula(){}

manipula::manipula(string caminho) {
    
    try{
    FileRef f(caminho.c_str());
    Tag * tag = f.tag();                            //acessar as tags de arquivos de música
    AudioProperties * prop = f.audioProperties();
    
    String dado;
    
    dado = tag->artist();
    artista = dado.toCString();     //
                                    //
    dado = tag->genre();            //
    genero = dado.toCString();      //
                                    //
    dado = tag->album();            //Atributos da classe manipula para criar um objeto para
    album = dado.toCString();       //cada música com suas tags, para anexá-las em uma lista
                                    //
    dado = tag->title();            //
    titulo = dado.toCString();      //
                                    //
    ano = tag->year();              //
                                    //
    trilha = tag->track();          //
                                    //
    tamanho = prop->lengthInSeconds();//
    
    arquivo = caminho;  //pega o caminho da música;
    }
    catch(...){}
    
}

    bool manipula::operator<(const manipula & outro){
        if(parametro == 2){                     //
            return artista < outro.artista;     //
        }                                       // Operação que muda a maneira como um objeto da classe manipula é classificada.    
        if(parametro == 3){                     //
            return titulo < outro.titulo;       // Usa a variável "a" do main como forma de diferenciar a maneira de comparação.
        }                                       //
        if(parametro == 4){                     //
            return trilha < outro.trilha;       //
        }                                       //
        if(parametro == 5){                     //
            return tamanho < outro.tamanho;     //
        }                                       //
        if(parametro == 6){                     //
            return genero < outro.genero;       //
        }                                       //
        if(parametro == 7){                     //
            return ano < outro.ano;             //
        }                                       //
        if(parametro == 8){                     //
            return album < outro.album;         //
        }                                       //    
}



manipula::~manipula() {
}

