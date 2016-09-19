#include "arma.h"
#include "armaLejos.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
armaLejos::armaLejos(string nombre,int dano,int nivel,int municion):arma(nombre,dano,nivel),municion(municion){

}
int armaLejos::getMunicion(){
	return municion;
}
armaLejos::~armaLejos(){

}
string armaLejos::toString()const{
	stringstream ss;
	ss<<arma::toString()<<" Municion: "<<municion;
	return ss.str();
}