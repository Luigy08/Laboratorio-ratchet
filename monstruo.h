#pragma once
#include "pj.h"
#include <string>
using std::string;
class monstruo:public pj
{
private:
	int defensa;
	int fuerza;
public:
	int getFuerza();
	int getDefensa();
	monstruo(string,int,int,int);
	~monstruo();
	virtual string toString()const;
};