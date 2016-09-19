#include <vector>
#include "arma.h"
#include "mejora.h"
using std::vector;
#pragma once
class inventario
{
private:
	vector<arma*> armas;
	mejora mejoras;
public:
	vector<arma*> getArmas();
	void setArmas(arma*);
	mejora getMejoras();
	inventario();
	~inventario();
	
};