#include "arma.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

arma::arma(string nombre,int nivel,int dano){
	this->nombre=nombre;
	this->nivel=nivel;
	this->dano=dano;
}
void arma::setNivel(int nivel){
	this->nivel=nivel;
}
void arma::setDano(int dano){
	this->dano=dano;
}
int arma::getDano(){
	return dano;
}
int arma::getNivel(){
	return nivel;
}
arma::~arma(){

}
string arma::toString()const{
	stringstream ss;
	ss<<" Nombre: "<<nombre<<", Nivel: "<<nivel<<", Daño: "<<dano;
	return ss.str();
}