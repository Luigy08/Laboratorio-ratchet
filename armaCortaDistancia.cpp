#include "arma.h"
#include "armaCortaDistancia.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
armaCortaDistancia::armaCortaDistancia(string nombre,int dano,int nivel):arma(nombre,dano,nivel){

}
armaCortaDistancia::~armaCortaDistancia(){

}
string armaCortaDistancia::toString()const{
	stringstream ss;
	ss<<arma::toString();
	return ss.str();
}