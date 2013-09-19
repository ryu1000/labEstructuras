#include "matriz1.hh"

Cmatriz::Cmatriz(int n, int m){
	filas=n;
	columnas=m;
	ptdata=new float*[filas];
	for(int i=0;i<filas;i++){
		ptdata[i]=new float[columnas];
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			ptdata[i][j]=0;
		}
	}
}

Cmatriz::Cmatriz(const Cmatriz &Matriz){ 
	filas=Matriz.filas;
	columnas=Matriz.columnas;
	ptdata=Matriz.ptdata;
}

Cmatriz::~Cmatriz(){
	for(int i=0;i<filas;i++){
		delete [] ptdata[filas];
	}
	delete [] ptdata;
} 

float Cmatriz::get(int f, int c) const{
	float valor;
	valor=ptdata[f][c];
	return valor;
}

void Cmatriz::set(int f, int c, float d){
	ptdata[f][c]=d;
}
