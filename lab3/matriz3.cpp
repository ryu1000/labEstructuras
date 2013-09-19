#include "matriz2.hh"

Cmatriz::Cmatriz(int n, int m){
	filas=n;
	columnas=m;
	ptdata=new float*[filas];
	for(int i=0;i<filas;i++){
		ptdata[i]=new float[columnas];
	}
}

Cmatriz::Cmatriz(const Cmatriz &Matriz){ 
	filas=Matriz.filas;
	columnas=Matriz.columnas;
	ptdata=new float*[filas];
	for(int i=0;i<filas;i++){
		ptdata[i]=new float[columnas];
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			ptdata[i][j]=Matriz.get(i,j);
		}
	}	
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

Cmatriz& Cmatriz::operator = (const Cmatriz &Matriz){
	filas=Matriz.filas;
	columnas=Matriz.columnas;
	ptdata=new float*[filas];
	for(int i=0;i<filas;i++){
		ptdata[i]=new float[columnas];
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			ptdata[i][j]=Matriz.get(i,j);
		}
	}
	return *this;
}

float Cmatriz::operator () (int f, int c){
	float valor=this->get(f,c);
	return valor;
}

void Cmatriz::desplegar(){
	for(int i=0;i<this->filas;i++){
		for(int j=0;j<this->columnas;j++){
			std::cout<<this->get(i,j)<<"\t";
		}
		std::cout<<std::endl;
	}
}

Cmatriz Cmatriz::operator + (const Cmatriz &Matriz){
	Cmatriz temp(*this);
	for(int i=0;i<this->filas;i++){
		for(int j=0;j<this->columnas;j++){
			temp.ptdata[i][j]+=Matriz.ptdata[i][j];
		}
	}
	return (temp);
}

Cmatriz Cmatriz::operator * (const float &escalar){
	Cmatriz temp(*this);
	for(int i=0;i<this->filas;i++){
		for(int j=0;j<this->columnas;j++){
			temp.ptdata[i][j]*=escalar;
		}
	}
	return (temp);
}
