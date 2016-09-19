temp: main.o pj.o rachet.o monstruo.o mejora.o inventario.o arma.o armaLejos.o armaCortaDistancia.o
	g++ main.o pj.o rachet.o monstruo.o mejora.o inventario.o arma.o armaLejos.o armaCortaDistancia.o -o temp
main.o: main.cpp pj.h rachet.h monstruo.h mejora.h inventario.h arma.h armaLejos.h armaCortaDistancia.h
	g++ -c main.cpp
pj.o: pj.cpp pj.h
	g++ -c pj.cpp
rachet.o: rachet.cpp rachet.h pj.h
	g++ -c rachet.cpp
monstruo.o:monstruo.cpp monstruo.h pj.h
	g++ -c monstruo.cpp
arma.o: arma.cpp arma.h
	g++ -c arma.cpp
armaLejos.o: armaLejos.cpp armaLejos.h arma.h
	g++ -c armaLejos.cpp
inventario.o: inventario.cpp inventario.h arma.h armaLejos.h armaCortaDistancia.h
	g++ -c inventario.cpp
