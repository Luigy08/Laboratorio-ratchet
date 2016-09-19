#include <string>
#include "pj.h"
#include "inventario.h"
using std::string;
#pragma once
class rachet: public pj
{
private:
	int monsDerrotados;
	int dinero;
	inventario* bolsa;
public:
	inventario* getBolsa();
	int getDinero();
	void setDinero(int);
	void setMonsDerrotados(int);
	int getMonsDerrotados();
	rachet(string,int,int,int,inventario*);
	virtual~rachet();
	virtual string toString()const;
	
};