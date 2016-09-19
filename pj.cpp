#include <string>
using std::string;
#include "pj.h"
#include <sstream>
using std::stringstream;
pj::pj(string nombre,int vida){
	this->nombre=nombre;
	this->vida=vida;
}
void pj::setVida(int vida){
	this->vida=vida;
}
int pj::getVida(){
	return vida;
}
string pj::toString()const{
	stringstream ss;
	ss<<" Nombre: "<<nombre<<"| Vida: "<<vida;
	return ss.str();
}
pj::~pj(){

}