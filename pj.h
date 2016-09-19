#include <string>
using std::string;
#pragma once
class pj
{
private:
	string nombre;
	int vida;
public:
	int getVida();
	void setVida(int);
	pj(string,int);
	virtual ~pj();
	virtual string toString()const;
};