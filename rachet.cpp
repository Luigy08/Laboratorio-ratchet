#include <string>
#include "pj.h"
#include "inventario.h"
using std::string;
#include "rachet.h"
#include <string>
#include <sstream>
using std::stringstream;
rachet::rachet(string nombre,int vida,int monsDerrotados,int dinero,inventario* bolsa):pj(nombre,vida),monsDerrotados(monsDerrotados),dinero(dinero),bolsa(bolsa){

}
rachet::~rachet(){

}
inventario* rachet::getBolsa(){
	return bolsa;
}
void rachet::setMonsDerrotados(int monsDerrotados){
	this->monsDerrotados=monsDerrotados;
}
int rachet::getMonsDerrotados(){
	return monsDerrotados;
}
int rachet::getDinero(){
	return dinero;
}
void rachet::setDinero(int dinero){
	this->dinero=dinero;
}
string rachet::toString()const{
	stringstream ss;
	ss<<pj::toString()<<"Dinero: "<<dinero<<" Monstruos Derrotados: "<<monsDerrotados;
	return ss.str();
}