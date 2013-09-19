#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Cmatriz{
	
	public:
	
	Cmatriz(int=1,int=1);
	Cmatriz(const Cmatriz &);
	~Cmatriz();
	float get(int,int) const;  //retorna un elemento de la matriz
	void set(int,int,float); //graba un elemento en la matriz
	
	private:
	
	int filas;
	int columnas;
	float **ptdata;
};

#endif
