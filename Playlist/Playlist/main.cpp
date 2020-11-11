// estes arquivos pertencem a biblioteca TagLib
#include <taglib.h>
#include <fileref.h>
#include <iostream>
#include <string>
#include <prglib.h>
#include <cstdlib>
#include <manipula.h>
#include "playlist.h"

// as declarações da TagLib estão no namespace TagLib
using namespace TagLib; 
using namespace std;
using namespace prglib;

int main(int argc, char** argv) {
    
   //Declarações;
    int operacao;
      int a; 
    cout << "----Editor de Listas de Reprodução----" << endl;
    cout << endl;
    
    cout << "Entre com o caminho dos arquivos de músicas" << endl;
    string path;
    getline(cin,path);
    playlist plista(path);
    cout << "Entre com o nome da sua playlist!" << endl;
    string nome;
    getline(cin,nome);
    
    cout << endl;
    while (true) {
        cout << "Escolha o que deseja fazer com a playlist " << nome << ":" << endl;
        cout << "1 - Gravar listas de reprodução em arquivos" << endl;
        cout << "2 - Ordena pelo nome do artista" << endl; 
        cout << "3 - Ordena pelo titulo da música" << endl;
        cout << "4 - Ordena pelo numero da trilha no album" << endl;
        cout << "5 - Ordena pela duração das músicas" << endl;
        cout << "6 - Ordena pelo gênero das músicas" << endl;
        cout << "7 - Ordena pelo ano de lançamento" << endl;
        cout << "8 - Ordena pelo album" << endl;
        cout << "9 - Mistura aleatoriamente as musicas" << endl;    //INTERFACE
        cout << "10 - Apresentar a lista em tela" << endl;
        cout << "11 - Sair do programa" << endl;
        cin >> a;
   
        if (a > 11 or a <1) cout << "Entrada inválida, digite uma operação do menu: " << endl;
    
        if(a == 1){
            cout << endl << "Digite o arquivo onde você quer gravar a playlist: " << endl;
            string txt;
            cin >> txt;
            txt = txt + "/" + nome + ".M3U";
            plista.escreve(txt);
        }
        
        if(a == 2){
            plista.por_artista(a);  //ordena por artista
        }
        
        if(a == 3){
            plista.por_titulo(a);   //ordena por titulo
        }
        
        if(a == 4){
            plista.por_trilha(a);   //ordena pela trilha
        }
        
        if(a == 5){
            plista.por_tamanho(a);  //ordena pelo tamanho
        }
        
        if(a == 6){
            plista.por_genero(a);   //ordena pelo gênero musical
        }
        
        if(a == 7){
            plista.por_ano(a);  //ordena pelo ano de lançamento
        }
        
        if(a == 8){
            plista.por_album(a);    //ordena pelo album da música
        }
                
        if(a == 9){
            plista.aleatorio(); //embaralhando a playlist aleatoriamente
        
        }
        
        if(a == 10){
            cout << "(trilha |"<< "artista |" << "música |" << "duracao |" << "album |" << "ano |" << "genero musical) ---- " << nome << endl;
            manipula b;             // objeto da classe manipula para auxiliar
            lista<manipula> l;
            l = plista.show();      //chama o método show que retorna a lista<manipula> musica como parametro.
            l.inicia();
            while(not l.fim()){     //itera a lista e imprime os dados de cada música
                b = l.proximo();
                cout << b.trilha << " | " << b.artista << " | " << b.titulo << " | " << b.tamanho << " | " << b.album << " | " << b.ano << " | " << b.genero <<  endl;
                
            }
            cout << endl << endl;
        }
        
        if(a == 11){
            return 0; //sai do programa
        }
    }
}