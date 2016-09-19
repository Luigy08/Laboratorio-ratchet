#pragma once
#include "arma.h"
#include <string>
class armaCortaDistancia:public arma
{
public:
	armaCortaDistancia(string,int,int);
	~armaCortaDistancia();
	virtual string toString()const;
};