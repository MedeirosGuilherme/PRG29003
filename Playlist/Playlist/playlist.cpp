#include "playlist.h"
#include <string>
#include <iostream>
#include "Diretorio.h"
#include <prglib.h>
#include "manipula.h" 
#include <fstream>

using namespace std;
using namespace prglib;

playlist::playlist(string cam) {
    
    Diretorio dir(cam);
    string camusica;
    
    //itera o diretorio:
    dir.inicia_listagem();
    
    while(not dir.fim_listagem()){
        Entrada e = dir.proximo(); // Pega o próximo arquivo de música
                
        if(e.tipo == Tipo::Arquivo and e.nome.rfind(".mp3") != string::npos){
            camusica = cam + "/" + e.nome;  //cria o caminho completo: caminho/nomedamusica.mp3
            manipula musica(camusica);      //Entra na classe manipula e cria um arquivo musica 
            play.anexa(musica);             //separando em tags e anexando na lista.
        }       
    }
    cout << endl;
}


playlist::~playlist() {
}

int playlist::escreve(string txt){
    
    fstream file;
    file.open(txt, std::fstream::out | std::fstream::trunc);    //Abre o arquivo digitado pelo usuario
    file << "#EXTM3u" << endl;                                  //para saída com o out, limpo como trunc
                                
    play.inicia();                  //começa a iteração da lista para imprimir
    while(not play.fim()){
        aux = play.proximo();
        file << "#EXTINF:" << aux.tamanho << "," << aux.artista << " - " << aux.titulo << endl;
        file << aux.arquivo << endl;    //imprimi no arquivo desejado com o formato estabelecido pela M3U
    }
}

void playlist::por_artista(int par){
    play.inicia();
    while(not play.fim()){                  //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
        play.proximo().parametro = par;
    }
    play.ordena();
}

void playlist::por_genero(int par){
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }
    
    play.ordena();
}

void playlist::por_album(int par){
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }
    play.ordena();
}

void playlist::por_titulo(int par){
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }
    play.ordena();
}

void playlist::por_ano(int par){   
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }                                       // par é o parâmetro que faz a escolha, é passado pelo main como a variável "a", a mesma usada para escolher o menu.
    play.ordena();
}

void playlist::por_trilha(int par){
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }
    play.ordena();
}

void playlist::por_tamanho(int par){
    play.inicia();
    while(not play.fim()){
        play.proximo().parametro = par;     //Inicia a iteração da lista e coloca no parametro "parametro" de cada objeto musica um número inteiro que funcionara como método de escolha de comparação pelo bool operator
    }
    play.ordena();
}

void playlist::aleatorio(){
    play.embaralha();                   //chama o método que embaralha a playlist
}

lista<manipula> playlist::show(){
    lista<manipula> l = play;       //mostra a playlist em tela, método retorna a lista para o main, com o objetivo de imprimir os seus dados.
    return l;
}