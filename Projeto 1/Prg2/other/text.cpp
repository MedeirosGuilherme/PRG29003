/*
 * Projeto 1 :: Prog 2::  Calculadora RPN

 - Classe RPN: Atributos:
 * pilha p<double> -> Recebe números
 * fila  f<int> -> Calculo de números primos
 * string s -> Recebe prompts do telcado.
 * 
 * 

-Classe RPN: Métodos:
 * 
 *  RPN::R.armazena(doubel num){ //recebe número
 *      pega stod da string da main e o empilha na memória;} 
 * 
 *  RPN::R.soma(){ //recebe +
 *      desempilha dois números da pilha p e realiza uma soma entre os dois, empilhando o resultado;}
 * 
 *  RPN::R.subtrai(){ //recebe -
 *      desempilha dois números da pilha p e realiza uma subtração entre os dois, empilhando o resultado;}
 * 
 *  RpN::R.multiplica(){ //recebe *
 *      desempilha dois números da pilha p e realiza uma multiplicação entre os dois, empilhando o resultado;}
 * 
 *  RPN::R.divide(){ //recebe/
 *      desempilha dois números da pilha p e realiza uma divisão entre os dois, empilhando o resultado;}
 * 
 *  RPN::R.show(){ //recebe !
 *      mostra o número no topo da pilha;}
 * 
 *  RPN::R.limpa(){ //recebe z
 *      limpa a memória da calculadora;}
 * 
 *  RPN::R.lshow(){ //recebe ?
 *      mostra todos os números da memória;}
 * 
 *  RPN::R.trunca(){ //recebe p
 *      pega o último número n da memória, o trunca para um inteiro e o substitui pelo primeiro número primo menor que n, usando 
 *  o algoritmo Crivo de Erastostenes;}
 * 
 *
 * 
 * */	
