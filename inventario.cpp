#include <vector>
#include "inventario.h"
#include "arma.h"
#include "mejora.h"
using std::vector;
inventario::inventario(){

}
inventario::~inventario(){

}
vector<arma*> inventario::getArmas(){
	return armas;
}
mejora inventario::getMejoras(){
	return mejoras;
}
void inventario::setArmas(arma* a){
	armas.push_back(a);
}