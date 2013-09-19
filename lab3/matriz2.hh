#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

using namespace std;

class Cmatriz{
	
	public:
	
	Cmatriz(int=1,int=1);
	Cmatriz(const Cmatriz &);
	~Cmatriz();
	float get(int,int) const;  //retorna un elemento de la matriz
	void set(int,int,float); //graba un elemento en la matriz
	
	Cmatriz &operator=(const Cmatriz &); //operador de asignacion
	float operator()(int,int); //retornar elemento de la matriz
	void desplegar(); //despliega toda la matriz
	Cmatriz operator+(const Cmatriz &); //suma dos matrices
	Cmatriz operator*(const float &); //multiplicar matriz por escalar
	
	private:
	
	int filas;
	int columnas;
	float **ptdata;
};

#endif
