#include <string>
using std::string;
#pragma once
class arma
{
private:
	string nombre;
	int dano;
	int nivel;
public:
	void setNivel(int);
	void setDano(int);
	int getDano();
	int getNivel();
	arma(string,int,int);
	~arma();
	virtual string toString()const;
};