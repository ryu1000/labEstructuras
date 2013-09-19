#include "matriz3.hh"
#include <iostream>

void fillmatriz(int,int,Cmatriz &);

using namespace std;

int main(){
	const int n=2;
	const int m=3;
	cout<<"Probando los operadores =, +, - y *"<<endl;
	cout<<"A:"<<endl;
	Cmatriz A(n,m);
	fillmatriz(n,m,A);
	cout<<A<<endl;
	A.desplegar();
	cout<<"B:"<<endl;
	Cmatriz B(A);
	B=3*A;
	cout<<B<<endl;
	B.desplegar();
	cout<<"C:"<<endl;
	Cmatriz C=B-A;
	cout<<C<<endl;
	C.desplegar();
	return 0;
}

void fillmatriz(int x,int y,Cmatriz &Matriz){
	float elemento=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			Matriz.set(i,j,elemento);
			elemento++;
		}
	}
};
