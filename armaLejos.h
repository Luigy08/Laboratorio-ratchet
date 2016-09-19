#pragma once
#include "arma.h"
#include <string>

class armaLejos:public arma
{
private:
	int municion;
public:
	int getMunicion();
	armaLejos(string,int,int,int);
	~armaLejos();
	virtual string toString()const;
};