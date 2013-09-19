#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

using namespace std;

class Cmatriz{
	
	friend ostream& operator << (ostream &, const Cmatriz &);
	//Similar a desplegar()
	
	friend Cmatriz operator * (const Cmatriz &, const float &);
	//Multiplicar matriz por flotante
	
	friend Cmatriz operator * (const float &, const Cmatriz &);
	//Multiplicar flotante por matriz
	
	public:
	
	Cmatriz(int=1,int=1);
	Cmatriz(const Cmatriz &);
	~Cmatriz();
	float get(int,int) const;  //retorna un elemento de la matriz
	void set(int,int,float); //graba un elemento en la matriz
	
	Cmatriz& operator=(const Cmatriz &); //operador de asignacion
	float operator()(int,int); //retornar elemento de la matriz
	void desplegar(); //despliega toda la matriz
	Cmatriz operator+(const Cmatriz &); //suma dos matrices
	Cmatriz operator-(const Cmatriz &); //restar dos matrices
	
	private:
	
	int filas;
	int columnas;
	float **ptdata;
};

#endif
