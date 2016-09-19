#include <string>
using std::string;
#include "pj.h"
#include "monstruo.h"
#include <sstream>
using std::stringstream;
monstruo::monstruo(string nombre,int vida,int defensa,int fuerza):pj(nombre,vida),defensa(defensa),fuerza(fuerza){

}
int monstruo::getFuerza(){
	return fuerza;
}
int monstruo::getDefensa(){
	return defensa;
}
monstruo::~monstruo(){

}
string monstruo::toString()const{
	stringstream ss;
	ss<<pj::toString()<<", Defensa: "<<defensa<<", Fuerza"<<fuerza;
	return ss.str();
}