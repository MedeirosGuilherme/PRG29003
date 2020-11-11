#include <string>
#include "RPN.h"
#include <iostream>

using namespace std;
using namespace prglib;

RPN::RPN(): p(999) {//Criação da pilha com tamanho 999
}

RPN::~RPN() {
}

string RPN::armazena(double n){ //Método que armazena números na memória.
    
    string retorno;
    if(not p.cheia())
        p.push(n);
        
    else{
        retorno = "Limite de memória da calculadora";
        return retorno;
    }
}

string RPN::show(){ //Método que mostra o último número da memória
    string retorno;
    if(not p.vazia()){
        double n = p.pop();
        retorno = retorno + to_string(n) + " ";
        p.push(n);
    }
    return retorno;
}

string RPN::lshow(){    //Método que mostra todos os números da memória
    string retorno;
    if(not p.vazia()){
        pilha<double> q(999);
        while(not p.vazia()){
            double n = p.pop();
            retorno = retorno + to_string(n) + " ";
            q.push(n);
            }
    
        while(not q.vazia()){
            double n = q.pop();
            p.push(n);
            }
        }
    return retorno;
}

void RPN::limpa(){  //Método que limpa a memória da calculadora
    p.esvazia();
}

int RPN::trunca(){  //Método que realiza o calculo do maior número primo menor que o ultimo número da memória da calculadora e o armazena
    double n = p.pop();
    fila<int> inteiros(999);    //Criando as duas filas
    fila<int> primos(999);
    
    int i = n;
    while(i >= 2){
        inteiros.enfileira(i);  //Enfileirando a de números inteiros
        i--;        
    }
            
    int aux;
    int a = 2;
    int b = sqrt(n);
    int c = 1;      //Criando variáveis auxiliares
    int tam = inteiros.comprimento();   
    while(a <= b){
        
        while (c <= tam) {
        aux = inteiros.desenfileira();
            if(aux%c != 0 or aux == c){
                inteiros.enfileira(aux);    //Realização do crivo
            }
            c++;
        }
        a++;
        }
    primos = inteiros;
    p.push(primos.frente());
}

string RPN::soma(){ //Soma dois ultimos números
    
    string retorno;
    if(p.comprimento()<2){
        retorno = "Não há números suficientes na memória para completar operação";
        return retorno;
    }
    
    else{
        double d = p.pop();
        double e = p.pop();
        double f;
        f = d + e;
        p.push(f);
    }
}

string RPN::subtrai(){  //Subtrai dois ultimos números
    string retorno;
    if(p.comprimento()<2){
        retorno = "Não há números suficientes na memória para completar operação";
        return retorno;
    }
    else{
        double d = p.pop();
        double e = p.pop();
        double f;
        f = e - d;
        p.push(f);    
    }
}

string RPN::multiplica(){   //Multiplica dois ultimos números
    string retorno;
    if(p.comprimento()<2){
        retorno = "Não há números suficientes na memória para completar operação";
        return retorno;
    }
    else{
        double d = p.pop();
        double e = p.pop();
        double f;
        f = e*d;
        p.push(f);
    }
}

string RPN::divide(){   //Divide dois ultimos números
    string retorno;
    if(p.comprimento()<2){
        retorno = "Não há números suficientes na memória para completar operação";
        return retorno;
    }
    
    else{
        double d = p.pop();
        double e = p.pop();
        double f;
        f = e/d;
        p.push(f);
    }    
}

string RPN::tamanho(){  //Método extra realizado por curiosidade para mostrar a memória usada da calculadora
    
    string retorno = "Tamanho ocupado: " + to_string(p.comprimento()) + " " + "Tamanho livre: " + to_string(999 - p.comprimento());
    return retorno;    
}



