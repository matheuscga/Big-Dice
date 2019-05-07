#include <string>
#include "jogador.h"

Jogador::Jogador(string nome, int status, int somad){
	this->nome = nome;
	this->status = status;
	this->somad = somad;
}
void Jogador::setNome(string nome){
	this->nome = nome;
}
		
string Jogador::getNome(){
	return this->nome;
}

void Jogador::setStatus(int status){
	this->status = status;
}
int Jogador::getStatus(){
	return this->status;
}
void Jogador::setSomad(int somad ){
	this->somad = somad;
}
int Jogador::getSomad(){
	return this->somad;
}