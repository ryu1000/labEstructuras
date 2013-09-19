#include "matriz1.hh"
#include <iostream>

void displaymatriz(int,int,const Cmatriz &);
void fillmatriz(int,int,Cmatriz &);

using namespace std;

int main(){
	const int n=2;
	const int m=3;
	cout<<"Probando el constructor y get():"<<endl;
	Cmatriz A(n,m);
	displaymatriz(n,m,A);
	cout<<"Probando set():"<<endl;
	fillmatriz(n,m,A);
	displaymatriz(n,m,A);
	cout<<"Probando el constructor con parametros ";
	cout<<"predeterminados"<<endl;
	Cmatriz B;
	displaymatriz(1,1,B);
	cout<<"Probando el constructor de copia:"<<endl;
	Cmatriz C(A);
	displaymatriz(n,m,C);
	return 0;
}

void displaymatriz(int x,int y,const Cmatriz &Matriz){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<Matriz.get(i,j)<<"\t";
		}
		cout<<endl;
	}
};

void fillmatriz(int x,int y,Cmatriz &Matriz){
	float elemento=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			Matriz.set(i,j,elemento);
			elemento++;
		}
	}
};
