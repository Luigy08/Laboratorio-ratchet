#include <iostream>
#include <string>
#include <vector>
using std::vector;
using namespace std;

#include "pj.h"
#include "rachet.h"
#include "monstruo.h"
#include "arma.h"
#include "armaLejos.h"
#include "armaCortaDistancia.h"
#include "mejora.h"
#include "inventario.h"

int main(int argc, char const *argv[])
{
	int op=0;
	vector<pj*> personajes;
	while(op!=3){
		cout<<"1.-Agregar"<<endl<<"2.-Simulacion de duelo"<<endl<<"3.-Finalizar simulacion"<<endl<<"...";
		cin>>op;
		if (personajes.size()==0)
		{
			pj* r=new rachet("Rachet",100,0,200,new inventario());
			personajes.push_back(r);
		}

		switch(op){
			case 1:{
				int op2=0;
				cout<<"1.-Mostruos"<<endl<<"2.-Inventario"<<endl<<"...";
				cin>>op2;
				switch(op2){
					case 1:{
						cout<<"-----MONSTRUOS-----"<<endl;
						string nombre;
						int fuerza,vida,defensa;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Vida: ";
						cin>>vida;
						cout<<"Fuerza: ";
						cin>>fuerza;
						cout<<"Defensa: ";
						cin>>defensa;
						personajes.push_back(new monstruo(nombre,vida,fuerza,defensa));
						break;
					}
					case 2:{
						cout<<"-----INVENTARIO-----"<<endl;
						int opInv=0;
						cout<<"1.-Armas de largo alcance"<<endl<<"2.-Armas de corto alcance"<<endl<<"...";
						cin>>opInv;
						string nombre;
						int dano,nivel=1;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Daño: ";
						cin>>dano;
						switch(opInv){
							case 1:{
								int municion;
								cout<<"Municion: ";
								cin>>municion;
								dynamic_cast<rachet*>(personajes[0])->getBolsa()->setArmas(new armaLejos(nombre,nivel,dano,municion));
								break;
							}
							case 2:{
								dynamic_cast<rachet*>(personajes[0])->getBolsa()->setArmas(new armaCortaDistancia(nombre,nivel,dano));
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 2:{
				if (dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas().size()>0&&personajes.size()>1)
				{
					cout<<"-----SIMULACION-----"<<endl;
					int desicion=0;
					int opEnemigo=0;
					for (int i = 0; i < personajes.size(); i++)
					{
						if (dynamic_cast<monstruo*>(personajes.at(i))!=NULL)
						{
							monstruo* tem=dynamic_cast<monstruo*>(personajes.at(i));
							cout<<i<<".-"<<tem->toString()<<endl<<"-------------------------------"<<endl;
						}
					}
					monstruo* enemigo;
					do
					{
						cout<<"Elija enemigo para el duelo: ";
						cin>>opEnemigo;
						enemigo=dynamic_cast<monstruo*>(personajes.at(opEnemigo));
						if (enemigo->getVida()<=0)
						{
							cout<<"El enemigo no esta en condiciones de lcuhar elija otro...."<<endl;
						}
					} while (enemigo->getVida()<=0);
					cout<<"+++++DUELO+++++"<<endl;
					bool bandera=true;
					while(bandera){
						cout<<"......ENEMIGO......"<<endl;
						cout<<enemigo->toString()<<endl;
						cout<<"..................."<<endl<<endl;
						cout<<"......RATCHET......"<<endl;
						cout<<dynamic_cast<rachet*>(personajes[0])->toString()<<endl;
						cout<<"..................."<<endl<<endl;
						do
						{
							cout<<"1.-Atacar"<<endl<<"2.-Huir"<<endl<<"...";
							cin>>desicion;
						} while (desicion<1||desicion>2);
						if (desicion==1)
						{
							cout<<"*****Inventario*****"<<endl;
							for (int i = 0; i < dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas().size(); i++)
							{
								if (dynamic_cast<armaLejos*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i]))
								{
									cout<<i+1<<".-"<<dynamic_cast<armaLejos*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i])->toString();
								}
								if (dynamic_cast<armaCortaDistancia*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i]))
								{
									cout<<i+1<<".-"<<dynamic_cast<armaCortaDistancia*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i])->toString();
								}
								cout<<endl;
							}
							int opArma;
							do
							{
								cout<<"Elija un arma: ";
								cin>>opArma;
							} while (opArma>dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas().size()||opArma<0);
							opArma--;
							cout<<"********************"<<endl;
							cout<<"=====RATCHET ATACA====="<<endl;
							if (dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[opArma]->getDano()-enemigo->getDefensa()<0)
							{
								enemigo->setVida(enemigo->getVida()-1);
							}else{
								enemigo->setVida(enemigo->getVida()-(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[opArma]->getDano()-enemigo->getDefensa()));
							}
							cout<<enemigo->toString();
							cout<<endl<<"======================="<<endl;
							cout<<"=====ENEMIGO ATACA====="<<endl;
							dynamic_cast<rachet*>(personajes[0])->setVida(dynamic_cast<rachet*>(personajes[0])->getVida()-enemigo->getFuerza());
							cout<<dynamic_cast<rachet*>(personajes[0])->toString();
							cout<<endl<<"======================="<<endl<<endl;
						}else{
							bandera=false;
						}
						if (dynamic_cast<rachet*>(personajes[0])->getVida()<=0||enemigo->getVida()<=0)
						{
							bandera=false;
						}	

					}//fin de simulacion de combate
					personajes[opEnemigo]=enemigo;
					if (enemigo->getVida()<=0)
					{
						dynamic_cast<rachet*>(personajes[0])->getBolsa()->getMejoras().setCantidad(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getMejoras().getCantidad()+1); 
						dynamic_cast<rachet*>(personajes[0])->setMonsDerrotados(dynamic_cast<rachet*>(personajes[0])->getMonsDerrotados()+1);
						dynamic_cast<rachet*>(personajes[0])->setDinero(dynamic_cast<rachet*>(personajes[0])->getDinero()+100);
					}
					if (dynamic_cast<rachet*>(personajes[0])->getVida()<=0)
					{
						cout<<"Rachet nesecita atencion medica!!"<<endl;
						cout<<"Costo: 200"<<endl;
						char resp;
						cout<<"Desea curarlo (s/n)...";
						cin>>resp;
						if (resp=='s')
						{
							dynamic_cast<rachet*>(personajes[0])->setVida(100);
							dynamic_cast<rachet*>(personajes[0])->setDinero(dynamic_cast<rachet*>(personajes[0])->getDinero()-200);
						}else{
							op==4;
						}
					}
					if (enemigo->getVida()<=0)
					{
						dynamic_cast<rachet*>(personajes[0])->setMonsDerrotados(dynamic_cast<rachet*>(personajes[0])->getMonsDerrotados()+1);
					}
				}else{
					cout<<endl<<"No puede emular un combate aunss"<<endl;
				}
				break;
			}
		}
	}
	cout<<"--------------Reporte-------------"<<endl;
	cout<<dynamic_cast<rachet*>(personajes[0])->toString()<<endl;
	cout<<"->Inventario"<<endl;
	for (int i = 0; i < dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas().size(); i++)
	{
		if (dynamic_cast<armaLejos*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i]))
			{
				cout<<i+1<<".-"<<dynamic_cast<armaLejos*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i])->toString();
			}
		if (dynamic_cast<armaCortaDistancia*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i]))
		{
			cout<<i+1<<".-"<<dynamic_cast<armaCortaDistancia*>(dynamic_cast<rachet*>(personajes[0])->getBolsa()->getArmas()[i])->toString();
		}
		cout<<endl;
	}
	cout<<endl<<"->Enemigos"<<endl;
	for (int i = 0; i < personajes.size(); i++)
	{
		if (dynamic_cast<monstruo*>(personajes.at(i))!=NULL)
		{
			monstruo* tem=dynamic_cast<monstruo*>(personajes.at(i));
			cout<<i<<".-"<<tem->toString()<<endl;
		}
	}
	return 0;
}
